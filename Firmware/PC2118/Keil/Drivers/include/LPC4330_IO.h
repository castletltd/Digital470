#ifndef __LPC_4330_IO_H
#define __LPC_4330_IO_H

#include "lpc43xx.h"                    /* lpc43xx definitions                */
#include "lpc_types.h"
#include "lpc43xx_scu.h"
#include "lpc43xx_gpio.h"
#include "LPC43xx_i2c.h"

#define SPK_Pin_name_PORT    8   /*Re-routed via fpga FC1, new pin P8.1*/
#define SPK_Pin_name_BIT     1
#define SPK_pin_Function    FUNC0
#define SPK_GPIO_PORT        4     
#define SPK_GPIO_BIT         1 

#define LED1_Pin_name_PORT    14	/* module heartbeat */
#define LED1_Pin_name_BIT     9   
#define LED1_pin_Function    FUNC4
#define LED1_GPIO_PORT        7 	
#define LED1_GPIO_BIT         9		

#define LED2_Pin_name_PORT    4  /* Zero crossing Led */
#define LED2_Pin_name_BIT     5
#define LED2_pin_Function    FUNC0
#define LED2_GPIO_PORT        2     
#define LED2_GPIO_BIT         5  

#define LED3_Pin_name_PORT    4  /* SPK Led */
#define LED3_Pin_name_BIT     6
#define LED3_pin_Function    FUNC0
#define LED3_GPIO_PORT        2    
#define LED3_GPIO_BIT         6

#define LED4_Pin_name_PORT    4 /* En-Disable Led */
#define LED4_Pin_name_BIT     8
#define LED4_pin_Function    FUNC4
#define LED4_GPIO_PORT        5     
#define LED4_GPIO_BIT         12 

#define LED5_Pin_name_PORT    4 /* PCB HB Led */
#define LED5_Pin_name_BIT     4
#define LED5_pin_Function    FUNC0
#define LED5_GPIO_PORT        2     
#define LED5_GPIO_BIT         4 

#define ZXINT_Pin_name_PORT    2
#define ZXINT_Pin_name_BIT     8
#define ZXINT_pin_Function    FUNC4
#define ZXINT_GPIO_PORT        5     
#define ZXINT_GPIO_BIT         7 

#define DIN1_Pin_name_PORT    7
#define DIN1_Pin_name_BIT     1
#define DIN1_pin_Function    FUNC0
#define DIN1_GPIO_PORT        3     
#define DIN1_GPIO_BIT         9  

#define DIN2_Pin_name_PORT    7
#define DIN2_Pin_name_BIT     0
#define DIN2_pin_Function    FUNC0
#define DIN2_GPIO_PORT        3     
#define DIN2_GPIO_BIT         8

#define FC2_Pin_name_PORT    8  /* Re-routed via fpga FC2, new pin P8.2 GPIO4[2] */
#define FC2_Pin_name_BIT     2
#define FC2_pin_Function    FUNC0
#define FC2_GPIO_PORT        4     
#define FC2_GPIO_BIT         2

#define FC3_Pin_name_PORT    8  /*fpga FC3, comms watchdog output to fpga */
#define FC3_Pin_name_BIT     3
#define FC3_pin_Function    FUNC0
#define FC3_GPIO_PORT        4     
#define FC3_GPIO_BIT         3

#define SPK2_Pin_name_PORT    4   /* new pin P4.3 for parallel spk detect */
#define SPK2_Pin_name_BIT     3
#define SPK2_pin_Function    FUNC0
#define SPK2_GPIO_PORT        2     
#define SPK2_GPIO_BIT         3 

#define PINT0Priority         4 /* zero crossing int */
#define PINT2Priority         2 /* Spark2 detect int */
#define I2C0Priority          5	/* I2C int (data from MCS III) */

/* Interrupts 3 -7 can be deferred by RTOS 0-2 are unaffected by RTOS code */
 
void GPIO_Config(void);
void I2C0Config(void);
void SetInterrupts(void);

#endif
