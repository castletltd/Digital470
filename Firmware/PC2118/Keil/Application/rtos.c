#include "rtos.h"

					uint16_t    	phase;
					uint16_t    	period;
					uint32_t  		phaseperiod;
volatile 	uint8_t 			DigIn;
					uint32_t  		temp =0;
					FlagStatus 		modchanged = RESET;
					SemaphoreHandle_t xFpgaSemaphore;

void vTaskHeartBeat(void*pvParameters)
{
	static uint16_t del = 5000;
  FlagStatus FirstTime = SET;
    fault = RESET;
  
  for ever
  {
    GPIO_ToggleValue(3,1<<4); 						/* toggle heartbeat LED */
    vTaskDelay(del/portTICK_RATE_MS);
    if (FirstTime == SET)
    {
        NVIC_EnableIRQ(PIN_INT1_IRQn);  /*Enable modulator interrupt */
        FirstTime = RESET;
        del = 500;
    }
  }  
}

void vTaskDigIO(void*pvParameters)
{
	for ever
	{
		GPIO_ClearValue(4,1<<4);
		vTaskDelay(100/portTICK_RATE_MS);
		GPIO_SetValue(4,1<<4);/*Generate LD signal via fpga */
		vTaskDelay(100/portTICK_RATE_MS);
		DigIn=(uint8_t)(((FPGA_RAM(FROM_FPGA_REG) & DIGIN_MASK))>>8);
		DigIns(DigIn); /*process digital I/O */
	}		
}

void vTaskPoll(void*pvParameters)
{
	static uint8_t	hwdel;
  portTickType xLastWakeTime;


	xLastWakeTime=xTaskGetTickCount();
  for ever 
  {
		if (FPGA_RAM(FROM_FPGA_REG) & MS_MASK)
		{
			GPIO_SetValue(6,1<<8);
			master = SET;
		}
		else
		{
			GPIO_ClearValue(6,1<<8);
			master = RESET;
		}
    if ((start == RESET)&&(!(FPGA_RAM(FROM_FPGA_REG)&IGBTEN_MASK)))
    {      /* Run input is OFF */
			GPIO_ClearValue(6,1<<15);	/*Turn off IGBT_ENABLE LED */
			FPGA_RAM(TO_FPGA_REG)=FPGA_RAM(TO_FPGA_REG) | IGBTEN_MASK; 
			FPGA_RAM(TO_FPGA_REG)=FPGA_RAM(TO_FPGA_REG) & ~IGBTPSU_MASK;
      period= PERIOD;																/* Set period to default value from header file */
			phase=MAXPHASE;
			phaseperiod =((uint32_t)phase*0x10000)+period;
      FPGA_RAM(PHASEPERIODREG)=phaseperiod;		/* set phase period to default initial value from header file */
      FPGA_RAM(1)=DEADBAND;													/* (re)load deadband values (1uS + 1uS) */
      hwdel = 200;																	/* 1 sec delay for driver psu to stabilize */
    }
    else					 /*Run input is ON */															
     {
				FPGA_RAM(TO_FPGA_REG) |=SLAVE_EN_MASK ;
        if(hwdel)  					/* Wait for fibre drive PSU to stabilize */
        {
					hwdel--;
					FPGA_RAM(TO_FPGA_REG) |=IGBTDEL_MASK ;
        }
        else
        {
					GPIO_SetValue(6,1<<15);					/* Turn IGBT_ENABLED LED */
          if (phase>MINPHASE)
						{
							phase--; 		/* Decrement phase and check limits for soft start */
						}
					taskENTER_CRITICAL();
					phaseperiod =((uint32_t)phase*0x10000)+period;	
					if ((master==RESET)&&(FPGA_RAM(8))) phaseperiod=FPGA_RAM(8); /* in slave mode get phaseperiod from FPGA sync */
					modchanged=SET; /* Signal to interrupt handler to update phase and period register at next interupt */
					taskEXIT_CRITICAL();
          FPGA_RAM(TO_FPGA_REG) = FPGA_RAM(TO_FPGA_REG) &~IGBTEN_MASK;	/* enable IGBTs */
        }
      }
   temp=FPGA_RAM(13);	
   GPIO_SetValue(4,1<<5);
   vTaskDelayUntil(&xLastWakeTime,(10/portTICK_RATE_MS));			
  }
}

void vTaskFpgaIntHandler(void*pvParameters)
{
for ever
  {
			xSemaphoreTake (xFpgaSemaphore ,portMAX_DELAY);
			/* Put stuff here that needs to be done imedeately after updating FPGA phase period register */
  }
}

void	GPIO1_IRQHandler(void)	/* interrupt service routine. Called on a rising edge of GPIO4[4] (LeadingPolarity from FPGA) */
{ 
	portBASE_TYPE xHigherPriorityTaskWoken =pdFALSE;
	LPC_GPIO_PIN_INT->FALL = (1 << 1);	/* Clear interrupt */			
	if (modchanged==SET)
		{
			xSemaphoreGiveFromISR(xFpgaSemaphore,&xHigherPriorityTaskWoken);
			FPGA_RAM(PHASEPERIODREG)=phaseperiod;
			modchanged=RESET;
			portEND_SWITCHING_ISR (xHigherPriorityTaskWoken);		
		}
	
}
