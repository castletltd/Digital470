 module deb #(parameter WIDTH=3,COUNT=7)(clk,enable,phase,missing,dbphase);
  input clk;
  input enable;
  input phase;
  output reg missing;
  output reg dbphase;
  reg [7:0] lockout;
  
  
  localparam WDCOUNT = 12'h9c4; //25mS @ 50MHz clk
  localparam LOCKOUT = 8'hf0; //1.28mS @ 50MHz clk
  
  reg[11:0] wdcnt;
  reg [WIDTH-1:0] count;
  
  always @ (posedge clk)
  begin
    dbphase <=1'b0;
    if (enable) 
      begin
        missing <=1'b0;
		    if (wdcnt)wdcnt<=wdcnt-1'b1;
		    else missing<=1'b1; 
		    if (lockout) lockout<=lockout-1'b1;
        
        if (phase == 0) 
          begin
            if (!lockout) count<= COUNT;
          end
        else 
          begin
            if (count)count<=count-1'b1;
            if (count == 1)
              begin
                dbphase<=1'b1;
                wdcnt<=WDCOUNT;
                lockout<=LOCKOUT;
              end
            end

        end      
  end
endmodule 
           