module phaseman (clk,enable,rphase,yphase,bphase,rotation,missing,rdbphase);
input clk;
input enable;
input rphase;
input yphase;
input bphase;
output reg rotation;
output reg missing;
output reg rdbphase;

reg[3:0] rotcount;


wire clk;
wire enable;
wire rphase;
wire yphase;
wire bphase;

deb #(.WIDTH(4),.COUNT(12)) rdb (clk,enable,rphase,rmissing,rdbp);
deb #(.WIDTH(4),.COUNT(12)) ydb (clk,enable,yphase,ymissing,ydbp);
deb #(.WIDTH(4),.COUNT(12)) bdb (clk,enable,bphase,bmissing,bdbp);

always @ (*)
begin
	missing=(rmissing|ymissing|bmissing);
	rdbphase=((rdbp)&&(bphase)&&(!yphase)); //rdbphase=rdbp; old code//use blu phase to block
   if (rotcount==4'b1111)rotation=1'b1;
   else rotation=1'b0;
end
always @ (negedge clk)
begin
	if (rdbp)
	begin
		if(!((bphase)&&(!yphase)))
      begin
         if (rotcount<4'b1111)
            begin
               rotcount<=rotcount+1'b1;
            end
      end
      else 
       begin
         rotcount<=0;
       end 
	end
end

endmodule
