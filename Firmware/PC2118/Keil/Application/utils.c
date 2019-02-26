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
 and utility functions called from rtos.c  
-------------------------------------------------------------------------*/
void	vSetupIO(void)
{
	/*  Heartbeat */
	scu_pinmux(6, 5, MD_BUK, FUNC0);	/* set pin P6_5 to GPIO3[4] */
	GPIO_SetDir(3, 1<<4, 1);					/* set GPIO3[4] to output */
	GPIO_ClearValue(3,1<<4);					
	/* Comms */
	scu_pinmux(4, 5, MD_BUK, FUNC0);	/* set pin P4_5 to GPIO2[5] */
	GPIO_SetDir(2, 1<<5, 1);					/* set GPIO2[5] to output */
	GPIO_ClearValue(2,1<<5);					
	/* IGBT Enable LED */
	scu_pinmux(0xD, 1, MD_BUK, FUNC4);	/* set pin PD_1 to GPIO6[15] */
	GPIO_SetDir(6, 1<<15, 1);					/* set GPIO6[15] to output */
	GPIO_ClearValue(6,1<<15);		
		/* Master/Slave */
	scu_pinmux(0xC, 9, MD_BUK, FUNC4);	/* set pin PC_9 to GPIO6[8] */
	GPIO_SetDir(6, 1<<8, 1);					/* set GPIO6[8] to output */
	GPIO_ClearValue(6,1<<8);	
		/* Dig In read command from cpu */
	scu_pinmux(8, 4,  MD_BUK, FUNC0);	/* set pin P8_4 to GPIO4[4] */
	GPIO_SetDir(4, 1<<4, 1);	
	GPIO_SetValue(4,1<<4);		/* set GPIO4[4] to output */
	/* FPGA reset from cpu */
	scu_pinmux(8, 5,  MD_BUK, FUNC0);	/* set pin P8_5 to GPIO4[5] */
	GPIO_SetDir(4, 1<<5, 1);	
	GPIO_ClearValue(4,1<<5);		/* set GPIO4[5] to output */
	/* Modulator Interupt  */
	scu_pinmux(8, 6, MD_PUP | MD_EZI, FUNC0);	/* set pin P8_6 to GPIO4[6] */
	GPIO_SetDir(4,1<<6, 0);					/* set GPIO4[6] to input */
  	/* PLL Lock output  */
	scu_pinmux(8, 3, MD_PUP | MD_EZI, FUNC0);	/* set pin P8_3 to GPIO4[3] */
	GPIO_SetDir(4,1<<3, 0);					/* set GPIO4[3] to input */
	
	CGU_EntityConnect(CGU_CLKSRC_IDIVB, CGU_BASE_CLKOUT);	
	LPC_SCU_CLK(0)=0xF1;		/*Enable clock output for FPGA (cpu_clock/2) from IDIVB */
	CGU_UpdateClock();

	LPC_SCU->PINTSEL0=0;
	LPC_SCU->PINTSEL0|=(4<<13)|(6<<8);	/* set GPIO4[6] as source for pin interrupt 1 */
	LPC_GPIO_PIN_INT->ISEL &= ~(1 << 1); /* edge sensitive */
	LPC_GPIO_PIN_INT->SIENF = (1 << 1);					/* enable pin interrupt 1 falling edge */		
}

void	vSetupInts(void)
{
  	
	NVIC_SetPriorityGrouping( 0 );/* Ensure all priority bits are assigned as preemption priority bits. */
	NVIC_SetPriority(PIN_INT1_IRQn,3 ); /* Highest Interrupt serviced by RTOS */
   
}

void vSetupRtos(void)	/* Create objects for RTOS */
{
		xFpgaSemaphore=xSemaphoreCreateBinary();  /* semaphore for deffered modulator interrupt */
    xTaskCreate(vTaskHeartBeat,"Heartbeat",240,NULL,HEARTBEAT_TASK_PRIORITY,NULL);
    xTaskCreate(vTaskPoll,"Poll",240,NULL,POLL_TASK_PRIORITY,NULL);
		xTaskCreate(vTaskDigIO,"IO",240,NULL,IO_TASK_PRIORITY,NULL);
		xTaskCreate(vTaskFpgaIntHandler,"Inthandler",240,NULL,FPGA_INT_HANDLER_PRIORITY,NULL);
}


/* Process data from digin and set flags for poll task */
void DigIns(uint8_t DigIn)
{
	static uint8_t Lastdigin =0;
	if( DigIn != Lastdigin )
	{
		if(!(DigIn & LR_MASK))
		{
			if (!(DigIn & STP_MASK))
			{
				start = RESET;
			}
			else if (DigIn & STA_MASK)
			{
				start = SET;
			}
			else if(DigIn & RS_MASK)
			{
				fault = RESET;
			}
		}
			if (DigIn & FLT_MASK)
			{
				fault = SET;
				if (DigIn & TRIP_MASK)
				{
					start = RESET;
				}
			}
			if (fault == SET)
			{
				FPGA_RAM(6) = FPGA_RAM(TO_FPGA_REG) | DO1_MASK;
			}
			else
			{
				FPGA_RAM(6) = FPGA_RAM(TO_FPGA_REG) & ~DO1_MASK;
			}
		}
	Lastdigin	= DigIn;
}
