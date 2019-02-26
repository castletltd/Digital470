/**************************/
/*									      */
/*		ram.c								*/
/*		Rewrittrn for LLC 	*/
/*    18.6.2014 JML     	*/
/*                        */
/**************************/

#include "utils.h"


/*-----------------------------------------------------------------------
 Functions below here are called from main() during initialisation 
-------------------------------------------------------------------------*/
void	vSetupIO(void)
{
	/*  Heartbeat */
	scu_pinmux(LED1_Pin_name_PORT ,LED1_Pin_name_BIT , MD_PUP, LED1_pin_Function); 	/* PE.9 : MODULE HB LED  */
	GPIO_SetDir(LED1_GPIO_PORT,(1<<LED1_GPIO_BIT), 1);
	GPIO_SetValue(LED1_GPIO_PORT,(1<<LED1_GPIO_BIT));		
  
	CGU_EntityConnect(CGU_CLKSRC_IDIVB, CGU_BASE_CLKOUT);	/*Enable clock output for FPGA 50MHz (cpu_clock/2) from IDIVB */
	LPC_SCU_CLK(0)=0xF1;		
	CGU_UpdateClock();
}

void vSetupRtos(void)
{
	xTaskCreate(vTaskHeartBeat,"Heartbeat",240,NULL,HEARTBEAT_TASK_PRIORITY,NULL);
	xTaskCreate(vTaskPoll,"Poll",240,NULL,POLL_TASK_PRIORITY,NULL);
}


