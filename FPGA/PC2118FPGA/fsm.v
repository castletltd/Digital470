module statem(clk,sclk,sync,osc,firing);
input wire clk,sclk,sync,osc;
output reg[5:0] firing;

(* signal_encoding = "user" *)reg[5:0] gates;
(* signal_encoding = "user" *)reg [3:0] nextstate;
(* signal_encoding = "user" *)reg[3:0] state;

parameter   idle=6'b000000, scr1=6'b100100, scr3=6'b100001, scr5=6'b001001;
parameter   scr7=6'b011000, scr9=6'b010010, scr11=6'b000110;
parameter   inhibit=4'b0000, s1=4'b0001, s2=4'b0011, s3=4'b0010, s4=4'b0110, s5=4'b0111, s6=4'b0101;
parameter   s7=4'b0100, s8=4'b1100, s9=4'b1101, s10=4'b1111, s11=4'b1110, s12=4'b1010;

always @ *
     begin
				case (state)
                inhibit:
                begin
                    nextstate = inhibit;
                    gates=idle;
                end                    
                s1:
                begin
                    nextstate = s2;
                    gates=scr1;
                end                    
                s2:
                begin                
                    nextstate = s3;
                    gates=idle;
                end                    
                s3:
                begin                
                    nextstate = s4;
                    gates=scr3;
                end                   
                s4:
                begin
                    nextstate = s5;
                    gates=idle;
                end                    
                s5:
                begin
                    nextstate = s6;
                    gates=scr5;
                end                    
                s6:
                begin                
                    nextstate = s7;
                    gates=idle;
                end                    
                s7:
                begin                
                    nextstate = s8;
                    gates=scr7;
                end                    
                s8:
                begin                
                    nextstate = s9;
                    gates=idle;
                end                    
                s9:
                begin                
                    nextstate = s10;
                    gates=scr9;
                end                    
                s10:
                begin                
                    nextstate = s11;
                    gates=idle;
                end
                s11:
                begin                
                    nextstate = s12;
                    gates=scr11;
                end                    
                s12:
                begin                
                    nextstate = s1;
                    gates=idle;
                end                    
                default:
                begin               
                    nextstate = inhibit;
                    gates=idle;
                end
          endcase
			 if(!osc) firing[5:0]=idle;
			 else firing[5:0]=gates[5:0];
     end
	
always @ (negedge clk) 
		begin  
		  if (sync) state<=s1;		
		  else if (sclk) state<=nextstate; 
   	end
	endmodule
