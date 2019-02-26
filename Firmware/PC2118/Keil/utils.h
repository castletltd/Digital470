/*	utils.h  */
	
#include "LPC43xx.h"
#include "lpc43xx_cgu.h"
#include "lpc43xx_gpio.h"
#include "lpc43xx_scu.h"
#include "lpc_types.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

extern void vTaskHeartBeat(void*pvParameters);
extern void vTaskPoll(void*pvParameters);


#define HEARTBEAT_TASK_PRIORITY				( tskIDLE_PRIORITY + 1UL )
#define POLL_TASK_PRIORITY            ( tskIDLE_PRIORITY + 3UL )

void vSetupIO(void);
void vSetupRtos(void);

#define LED1_Pin_name_PORT    14	/* module heartbeat */
#define LED1_Pin_name_BIT     9   
#define LED1_pin_Function    FUNC4
#define LED1_GPIO_PORT        7 	
#define LED1_GPIO_BIT         9		




