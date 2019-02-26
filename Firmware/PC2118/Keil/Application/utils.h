//	utils.h
//
//	

#include "LPC43xx.h"
#include "lpc43xx_cgu.h"
#include "lpc43xx_gpio.h"
#include "lpc43xx_scu.h"
#include "lpc_types.h"
//#include "defines.h"

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "defines.h"




#define HEARTBEAT_TASK_PRIORITY				( tskIDLE_PRIORITY + 1UL )
#define POLL_TASK_PRIORITY            ( tskIDLE_PRIORITY + 3UL )
#define FPGA_INT_HANDLER_PRIORITY     ( tskIDLE_PRIORITY + 4UL ) /*should be highest priority for deferred interupt */
#define IO_TASK_PRIORITY							( tskIDLE_PRIORITY + 2UL )

extern void vTaskHeartBeat(void*pvParameters);
extern void vTaskPoll(void*pvParameters);
extern void vTaskFpgaIntHandler(void*pvParameters);
extern void vTaskDigIO(void*pvParameters);
extern SemaphoreHandle_t xFpgaSemaphore;

void vSetupIO(void);
void vSetupInts(void);
void vSetupRtos(void);
void DigIns(uint8_t DigIn);

extern FlagStatus		start;
extern FlagStatus		fault;






