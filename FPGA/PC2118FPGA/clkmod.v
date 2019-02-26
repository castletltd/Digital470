module clkmod(clk,rst,enIn,enable,enable1,enable2);

input clk;
input rst;
input enIn;
output enable;
output enable1;
output enable2;
wire clk;
wire rst;

clockgen #(.WIDTH(3),.COUNT(4)) clkenable (clk,rst,enIn,enable); 
clockgen #(.WIDTH(4),.COUNT(12)) subclkenable (clk,rst,enable,enable1);
clockgen #(.WIDTH(4),.COUNT(10)) clk10usenable (clk,rst,enable1,enable2);

endmodule
