#include "rtos.h"


void vTaskHeartBeat(void*pvParameters)
{
	static uint16_t del = 500;
  for ( ; ; )
  {
		GPIO_ToggleValue(LED1_GPIO_PORT,(1<<LED1_GPIO_BIT)); /* MODULE heartbeat LED */
    vTaskDelay(del/portTICK_RATE_MS);
  }  
}

void vTaskPoll(void*pvParameters) /* Runs every 10mS for "houskeeping" ) */
{
  portTickType xLastWakeTime;
	xLastWakeTime=xTaskGetTickCount();
  for (;;) 
  {
    vTaskDelayUntil(&xLastWakeTime,(10/portTICK_RATE_MS));  
  }
}

