/****************************************************/
/*																									*/
/*					main.c for KTP LLC controller CPU				*/
/*					18.4.2014 JML														*/
/*																									*/
/****************************************************/

#include "utils.h"
#include "defines.h"

uint32_t    temp1 = 0;
/*--------------
  Main function		
 *--------------*/
 
int main (void)
{
	uint32_t		FPGA_Reset=0x00008000;
  
	vSetupIO(); /* initialize I/O, fpga reset active on exit */
  while(FPGA_Reset--)	; /* fpga and fgpa pll held reset */
  GPIO_SetValue(4,1<<5); /* remove fpga reset */
  while(! temp1 ) /* wait for pll to lock */
  {
    temp1= (GPIO_ReadValue(4) & (0x00000008));
  };
  FPGA_RAM(0)=INIT_PHASE_PERIOD;  /* initialize phase period regisiter */
//Not implemented yet  FPGA_RAM(2)=WATCHDOG;						/* initialize watchdog timeout value */
  FPGA_RAM(1)=DEADBAND;						/* initialize deadband values */
	//	FPGA_RAM(6)|= 0x00000000;
	vSetupInts();
	vSetupRtos();
	vTaskStartScheduler();

/* Sould never get here - scheduler does not return */  

  
for ever	
	{
		/* To do - put some sort of error trap and indication here */
  }

}

