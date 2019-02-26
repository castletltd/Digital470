module clockgen #(parameter WIDTH=8,COUNT=50)(clk,rst,enableIn,enableOut);
  input clk;
  input rst;
  input enableIn;
  output reg enableOut;
  
  reg [WIDTH-1:0] counter1;

  always @ (negedge clk)
  begin
    enableOut<=0;
    if (rst==0)
      begin
        counter1 <= COUNT-1'b1;
        enableOut<=0;
      end
    else if(enableIn)
      begin
        if (counter1)
          begin
            counter1<=counter1-1'b1;
            enableOut<=0;
          end
        else
          begin
            counter1 <= COUNT-1'b1;
            enableOut<=1;
          end  
      end  
  end
  
endmodule

