//module demand(clk,enable,zxing,delay,sync);
//input clk,enable,zxing;
//input wire[15:0] delay;
//output reg sync;
//
//
//reg[15:0] counter;
//
//always @ (negedge clk)
//begin
//  sync<=1'b0;
// if(zxing) counter<=delay; 
//  if (enable)
//    begin 
//          if (counter)
//            begin
//              counter<=counter-1'b1;
//              if (counter==1'b1)sync<=1'b1; 
//            end
//    end
//end
//
//endmodule

module demand(clk,enable,zxing,delay,sync);
input clk,enable,zxing;
input wire[15:0] delay;
output wire sync;


reg[15:0] counter;


assign sync = (counter==16'h1);

always @ (negedge clk)
begin
 if(zxing)  counter<=delay; 

 else
 begin
  if (enable)
    begin 
			
         if (counter)
            begin
              counter<=counter-1'b1;
            end
    end
 end
end

endmodule
