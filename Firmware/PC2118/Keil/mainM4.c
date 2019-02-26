/****************************************************/
/*																									*/
/*					main.c for KTP LLC controller CPU				*/
/*					18.4.2014 JML														*/
/*																									*/
/****************************************************/

#include "utils.h"

/*--------------
  Main function		
 *--------------*/
 
int main (void)
{
 	vSetupIO(); /* initialize I/O, fpga reset active on exit */
	vSetupRtos();
	vTaskStartScheduler();

/* Sould never get here - scheduler does not return */  

  
  for (;;)
	{
		/* To do - put some sort of error trap and indication here */
  }

}

