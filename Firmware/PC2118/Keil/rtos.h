/**********************************************************
*					This file contains references and calls					*
*					related to FreeRTOS															*
***********************************************************/

#include "FreeRTOS.h"
#include "utils.h"
#include "task.h"
#include "semphr.h"
#include "lpc43xx_gpio.h"

void vTaskHeartBeat(void*pvParameters);
void vTaskPoll(void*pvParameters);

