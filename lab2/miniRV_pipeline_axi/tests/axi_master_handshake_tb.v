`timescale 1ns / 1ps

module axi_master_handshake_tb;
    reg aclk = 1'b0;
    reg areset = 1'b1;
    reg [3:0] ic_cpu_ren = 4'h0;
    reg [31:0] ic_cpu_raddr = 32'h0;
    reg [3:0] dc_cpu_wen = 4'h0;
    reg [31:0] dc_cpu_waddr = 32'h0;
    reg [31:0] dc_cpu_wdata = 32'h0;
    reg [3:0] dc_cpu_ren = 4'h0;
    reg [31:0] dc_cpu_raddr = 32'h0;
    reg m_axi_awready = 1'b0;
    reg m_axi_wready = 1'b0;
    reg [1:0] m_axi_bresp = 2'b00;
    reg m_axi_bvalid = 1'b0;
    reg m_axi_arready = 1'b0;
    reg [31:0] m_axi_rdata = 32'h0;
    reg [1:0] m_axi_rresp = 2'b00;
    reg m_axi_rlast = 1'b0;
    reg m_axi_rvalid = 1'b0;

    wire ic_dev_rrdy, ic_dev_rvalid, dc_dev_wrdy, dc_dev_rrdy, dc_dev_rvalid;
    wire [127:0] ic_dev_rdata, dc_dev_rdata;
    wire [31:0] m_axi_awaddr, m_axi_wdata, m_axi_araddr;
    wire [7:0] m_axi_awlen, m_axi_arlen;
    wire [2:0] m_axi_awsize, m_axi_arsize;
    wire [1:0] m_axi_awburst, m_axi_arburst;
    wire [3:0] m_axi_wstrb;
    wire m_axi_awvalid, m_axi_wlast, m_axi_wvalid, m_axi_bready;
    wire m_axi_arvalid, m_axi_rready;

    axi_master dut (
        .aclk(aclk), .areset(areset),
        .ic_dev_rrdy(ic_dev_rrdy), .ic_cpu_ren(ic_cpu_ren), .ic_cpu_raddr(ic_cpu_raddr),
        .ic_dev_rvalid(ic_dev_rvalid), .ic_dev_rdata(ic_dev_rdata),
        .dc_dev_wrdy(dc_dev_wrdy), .dc_cpu_wen(dc_cpu_wen), .dc_cpu_waddr(dc_cpu_waddr),
        .dc_cpu_wdata(dc_cpu_wdata), .dc_dev_rrdy(dc_dev_rrdy), .dc_cpu_ren(dc_cpu_ren),
        .dc_cpu_raddr(dc_cpu_raddr), .dc_dev_rvalid(dc_dev_rvalid), .dc_dev_rdata(dc_dev_rdata),
        .m_axi_awaddr(m_axi_awaddr), .m_axi_awlen(m_axi_awlen), .m_axi_awsize(m_axi_awsize),
        .m_axi_awburst(m_axi_awburst), .m_axi_awvalid(m_axi_awvalid), .m_axi_awready(m_axi_awready),
        .m_axi_wdata(m_axi_wdata), .m_axi_wstrb(m_axi_wstrb), .m_axi_wlast(m_axi_wlast),
        .m_axi_wvalid(m_axi_wvalid), .m_axi_wready(m_axi_wready), .m_axi_bready(m_axi_bready),
        .m_axi_bresp(m_axi_bresp), .m_axi_bvalid(m_axi_bvalid), .m_axi_araddr(m_axi_araddr),
        .m_axi_arlen(m_axi_arlen), .m_axi_arsize(m_axi_arsize), .m_axi_arburst(m_axi_arburst),
        .m_axi_arvalid(m_axi_arvalid), .m_axi_arready(m_axi_arready), .m_axi_rready(m_axi_rready),
        .m_axi_rdata(m_axi_rdata), .m_axi_rresp(m_axi_rresp), .m_axi_rlast(m_axi_rlast), .m_axi_rvalid(m_axi_rvalid)
    );

    always #5 aclk = ~aclk;

    task expect_cache_on_grant;
        input [31:0] address;
        begin
            wait (ic_dev_rrdy === 1'b1);
            ic_cpu_raddr = address;
            ic_cpu_ren = 4'hf;
            @(posedge aclk);
            #1;
            if (!m_axi_arvalid || m_axi_araddr != address || m_axi_arlen != 8'd3) begin
                $display("FAIL cache-on request was not accepted on its ready grant");
                $fatal;
            end
            ic_cpu_ren = 4'h0;
        end
    endtask

    task expect_cache_off_check_cycle;
        input [31:0] address;
        begin
            wait (ic_dev_rrdy === 1'b1);
            @(posedge aclk);
            #1;
            ic_cpu_raddr = address;
            ic_cpu_ren = 4'hf;
            @(posedge aclk);
            #1;
            if (!m_axi_arvalid || m_axi_araddr != address || m_axi_arlen != 8'd3) begin
                $display("FAIL cache-off request was not accepted in check cycle");
                $fatal;
            end
            ic_cpu_ren = 4'h0;
        end
    endtask

    task expect_peripheral_read_single_beat;
        input [31:0] address;
        begin
            wait (dc_dev_rrdy === 1'b1);
            dc_cpu_raddr = address;
            dc_cpu_ren = 4'hf;
            @(posedge aclk);
            #1;
            if (!m_axi_arvalid || m_axi_araddr != address || m_axi_arlen != 8'd0) begin
                $display("FAIL peripheral read must use one AXI beat");
                $fatal;
            end
            dc_cpu_ren = 4'h0;
        end
    endtask

    initial begin
        repeat (2) @(posedge aclk);
        areset = 1'b0;
        expect_peripheral_read_single_beat(32'hffff_3008);
        areset = 1'b1;
        @(posedge aclk);
        areset = 1'b0;
        expect_cache_on_grant(32'h0000_0040);
        areset = 1'b1;
        @(posedge aclk);
        areset = 1'b0;
        expect_cache_off_check_cycle(32'h0000_0080);
        $display("PASS: axi_master accepts cache-on and cache-off requests");
        $finish;
    end
endmodule
