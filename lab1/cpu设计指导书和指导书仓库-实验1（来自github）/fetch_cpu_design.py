from __future__ import annotations

import http.client
import re
import socket
import ssl
from collections import deque
from pathlib import Path
from urllib.parse import quote, unquote, urljoin, urlsplit

HOST = "cpu-design.p.cs-lab.top"
IP = "10.249.12.224"
ROOT = f"https://{HOST}/"
OUT = Path("cpu-design-data")

ATTR_RE = re.compile(rb'''(?:href|src)\s*=\s*["']([^"'#]+)''', re.I)
CSS_RE = re.compile(rb'''url\(["']?([^"')]+)''', re.I)


def target_path(url: str, content_type: str) -> Path:
    path = unquote(urlsplit(url).path).lstrip("/")
    if not path or path.endswith("/"):
        path += "index.html"
    elif "text/html" in content_type and not Path(path).suffix:
        path += "/index.html"
    return OUT / path


class DirectHTTPSConnection(http.client.HTTPSConnection):
    def connect(self) -> None:
        sock = socket.create_connection((IP, self.port), self.timeout)
        self.sock = self._context.wrap_socket(sock, server_hostname=HOST)


def fetch(path_query: str) -> tuple[int, dict[str, str], bytes]:
    ctx = ssl.create_default_context()
    ctx.check_hostname = False
    ctx.verify_mode = ssl.CERT_NONE
    conn = DirectHTTPSConnection(HOST, 443, context=ctx, timeout=20)
    conn.request("GET", path_query, headers={"Host": HOST, "User-Agent": "cpu-design-offline-fetch/1.0"})
    res = conn.getresponse()
    body = res.read()
    headers = {k.lower(): v for k, v in res.getheaders()}
    conn.close()
    return res.status, headers, body


def main() -> None:
    queue = deque([ROOT])
    seen: set[str] = set()
    saved = 0
    while queue:
        url = queue.popleft()
        parts = urlsplit(url)
        clean = parts._replace(fragment="").geturl()
        if clean in seen or parts.hostname != HOST:
            continue
        seen.add(clean)
        query = parts.path or "/"
        if parts.query:
            query += "?" + parts.query
        query = quote(query, safe="/%?=&:+")
        try:
            status, headers, body = fetch(query)
        except Exception as exc:
            print(f"ERROR {clean}: {exc}")
            continue
        if status in (301, 302, 303, 307, 308) and headers.get("location"):
            queue.append(urljoin(clean, headers["location"]))
            continue
        if status != 200:
            print(f"HTTP {status} {clean}")
            continue
        ctype = headers.get("content-type", "")
        dest = target_path(clean, ctype)
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_bytes(body)
        saved += 1
        print(f"{status} {len(body):>8} {parts.path or '/'}")
        candidates = []
        if "text/html" in ctype:
            candidates.extend(ATTR_RE.findall(body))
        if "text/css" in ctype:
            candidates.extend(CSS_RE.findall(body))
        for raw in candidates:
            try:
                ref = raw.decode("utf-8").strip()
            except UnicodeDecodeError:
                continue
            if ref.startswith(("data:", "mailto:", "javascript:")):
                continue
            absolute = urljoin(clean, ref)
            if urlsplit(absolute).hostname == HOST:
                queue.append(absolute)
    print(f"Saved {saved} files under {OUT.resolve()}")


if __name__ == "__main__":
    main()
