const fs = require("fs");
const vm = require("vm");

const html = fs.readFileSync("datapath.html", "utf8");

function assert(condition, message) {
  if (!condition) {
    throw new Error(message);
  }
}

const dataKeys = [...html.matchAll(/data-key="([^"]+)"/g)].map((match) => match[1]);
const detailKeys = [...html.matchAll(/^      ([A-Za-z0-9_]+): \{/gm)].map((match) => match[1]);
const missingDetails = dataKeys.filter((key) => !detailKeys.includes(key));

assert(dataKeys.length > 0, "expected hoverable data-key elements");
assert(missingDetails.length === 0, `missing detail entries: ${missingDetails.join(", ")}`);

const scriptMatch = html.match(/<script>([\s\S]*)<\/script>/);
assert(scriptMatch, "expected inline script");
new vm.Script(scriptMatch[1]);

assert(html.includes("let pinnedEl = null"), "expected pinnedEl state for click-to-pin");
assert(html.includes("data-pinned"), "expected data-pinned attribute for visible pinned state");
assert(/addEventListener\("click",\s*\(\)\s*=>\s*togglePinned\(el\)\)/.test(html), "expected click handler to pin detail view");
assert(/addEventListener\("keydown"/.test(html) && /event\.key === "Escape"/.test(html), "expected Escape key to clear pinned detail view");

console.log(`datapath checks passed: ${dataKeys.length} interactive elements`);
