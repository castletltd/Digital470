module periodcnt (clk,enable12,enable,zxing,cpu_rd,cpu_address,sync,cpu_data,fsmclk,gate);
input clk;
input enable12;
input enable;
input sync;
input zxing;
input cpu_rd;
input wire[6:0] cpu_address;
output wire[15:0] cpu_data;
output reg fsmclk;
output reg gate;

reg[15:0] periodcnt;
reg[15:0] tempperiod;
reg[15:0] fsmcnt;
reg[15:0] period;

memory16bit_FPGAwrite #(0) mem0(cpu_rd,cpu_data,cpu_address,period);

always @ (posedge clk)
  begin
      fsmclk<=1'b0;
 
      if (enable12)
      begin
        periodcnt<=periodcnt+16'h0001;
      end 
      if (zxing)
      begin
        period<=periodcnt;
        periodcnt<=16'h0000;
      end
      if (sync)
      begin
        tempperiod<=period;
        fsmcnt<=period-1'b1;
      end
        if(enable)
          begin
          fsmcnt<=fsmcnt - 16'h0001; 
          if (fsmcnt==0)
            begin
              fsmclk<=1'b1;
              fsmcnt<=tempperiod-1'b1;
            end  
          end  
      gate<=~fsmcnt[8];     
    end
endmodule

  