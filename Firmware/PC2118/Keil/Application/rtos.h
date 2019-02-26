/**********************************************************
*					This file contains references and calls					*
*					related to FreeRTOS															*
***********************************************************/

#include "FreeRTOS.h"
#include "utils.h"
#include "task.h"
//#include "timers.h"
#include "semphr.h"
#include "lpc43xx_gpio.h"
#include "defines.h"

FlagStatus		start =RESET;
FlagStatus		fault =RESET;
FlagStatus		master =SET;
extern void DigIns(uint8_t DigIn);


void vTaskHeartBeat(void*pvParameters);
void vTaskPoll(void*pvParameters);
void vTaskFpgaIntHandler(void*pvParameters);
void vTaskDigIO(void*pvParameters);





