/*


*/
#include "LPC4330_IO.h"

#define PriorityGroup 0		/*Keep "flat" interupt model for FreeRTOS */

void GPIO_Config(void)
{
	scu_pinmux(LED1_Pin_name_PORT ,LED1_Pin_name_BIT , MD_PUP, LED1_pin_Function); 	/* PE.9 : MODULE HB LED  */
	GPIO_SetDir(LED1_GPIO_PORT,(1<<LED1_GPIO_BIT), 1);
	GPIO_SetValue(LED1_GPIO_PORT,(1<<LED1_GPIO_BIT));	
	scu_pinmux(LED2_Pin_name_PORT ,LED2_Pin_name_BIT , MD_PUP, LED2_pin_Function); 	/* P4.5 :  */
	GPIO_SetDir(LED2_GPIO_PORT,(1<<LED2_GPIO_BIT), 1);
	GPIO_SetValue(LED2_GPIO_PORT,(1<<LED2_GPIO_BIT));	
	scu_pinmux(LED3_Pin_name_PORT ,LED3_Pin_name_BIT , MD_PUP, LED3_pin_Function); 	/* P4.6 : SPK LED */ 
	GPIO_SetDir(LED3_GPIO_PORT,(1<<LED3_GPIO_BIT), 1);
	GPIO_SetValue(LED3_GPIO_PORT,(1<<LED3_GPIO_BIT));	
	scu_pinmux(LED4_Pin_name_PORT ,LED4_Pin_name_BIT , MD_PUP, LED4_pin_Function); 	/* P4.8 : RUN LED */
	GPIO_SetDir(LED4_GPIO_PORT,(1<<LED4_GPIO_BIT), 1);
	GPIO_SetValue(LED4_GPIO_PORT,(1<<LED4_GPIO_BIT));	
	scu_pinmux(LED5_Pin_name_PORT ,LED5_Pin_name_BIT , MD_PUP, LED5_pin_Function); 	/* P4.4 : PCB HB LED */
	GPIO_SetDir(LED5_GPIO_PORT,(1<<LED5_GPIO_BIT), 1);
	GPIO_SetValue(LED5_GPIO_PORT,(1<<LED5_GPIO_BIT));	
	
	scu_pinmux(FC3_Pin_name_PORT ,FC3_Pin_name_BIT , MD_PUP, FC3_pin_Function); 	/* P8.2 : USE TO DISABLE SCR AFTER SPK */
	GPIO_SetDir(FC3_GPIO_PORT,(1<<FC3_GPIO_BIT), 1);
	GPIO_SetValue(FC3_GPIO_PORT,(1<<FC3_GPIO_BIT));
  
  scu_pinmux(FC2_Pin_name_PORT ,FC2_Pin_name_BIT , MD_PUP, FC2_pin_Function); 	/* P8.3 : signal comms activity to FPGA */
	GPIO_SetDir(FC2_GPIO_PORT,(1<<FC2_GPIO_BIT), 1);
	GPIO_SetValue(FC2_GPIO_PORT,(1<<FC2_GPIO_BIT));

	
	scu_pinmux(ZXINT_Pin_name_PORT ,ZXINT_Pin_name_BIT , MD_PLN_FAST, ZXINT_pin_Function); 	/* P2.8 :  */
	GPIO_SetDir(LED1_GPIO_PORT,(1<<ZXINT_GPIO_BIT), 0);
	
	scu_pinmux(DIN1_Pin_name_PORT ,DIN1_Pin_name_BIT , MD_PLN_FAST, DIN1_pin_Function); 	/* P7.1 :  */
	GPIO_SetDir(DIN1_GPIO_PORT,(1<<DIN1_GPIO_BIT), 0);
	
	scu_pinmux(DIN2_Pin_name_PORT ,DIN2_Pin_name_BIT , MD_PLN_FAST, DIN2_pin_Function); 	/* P7.0 :  */
	GPIO_SetDir(DIN2_GPIO_PORT,(1<<DIN2_GPIO_BIT), 0);
	
	scu_pinmux(SPK_Pin_name_PORT ,SPK_Pin_name_BIT , MD_PLN_FAST, SPK_pin_Function); 	/* P8.1 */ 
	GPIO_SetDir(SPK_GPIO_PORT,(1<<SPK_GPIO_BIT), 0);
	
	scu_pinmux(SPK2_Pin_name_PORT ,SPK2_Pin_name_BIT , MD_PLN_FAST, SPK2_pin_Function); 	/* P4.3 parallel spk detect*/ 
	GPIO_SetDir(SPK2_GPIO_PORT,(1<<SPK2_GPIO_BIT), 0);
	
    LPC_SCU->PINTSEL0 &= ~(0xFFFF << 0);

    LPC_SCU->PINTSEL0|=(ZXINT_GPIO_PORT<<5)|(ZXINT_GPIO_BIT<<0);	/* set GPIO5[7] as source for pin interrupt 0 */
    LPC_GPIO_PIN_INT->ISEL &= ~(1 << 0);    /* edge sensitive*/
    LPC_GPIO_PIN_INT->SIENF = (1 << 0);     /* falling edge enable */
  //  LPC_SCU->PINTSEL0|=(SPK_GPIO_PORT<<13)|(SPK_GPIO_BIT<<8);	/* set GPIO4[1] as source for pin interrupt 1*/
  ///  LPC_GPIO_PIN_INT->ISEL &= ~(1 << 1);    /* edge sensitive */
  //  LPC_GPIO_PIN_INT->SIENR=(1 << 1);			/* enable pin interrupt 1 rising edge sensitivity */
		
		LPC_SCU->PINTSEL0|=(SPK2_GPIO_PORT<<21)|(SPK2_GPIO_BIT<<16);	/* set GPIO2[3] as source for pin interrupt 2*/
    LPC_GPIO_PIN_INT->ISEL &= ~(1 << 1);    /* edge sensitive */
    LPC_GPIO_PIN_INT->SIENR=(1 << 2);			/* enable pin interrupt 1 rising edge sensitivity */


}
void I2C0Config(void)
{
  I2C_OWNSLAVEADDR_CFG_Type	OwnSlaveAddr={0,1,ENABLE,2};
	I2C_Init(LPC_I2C0, 30000);
	I2C_SetOwnSlaveAddr(LPC_I2C0,&OwnSlaveAddr);
  LPC_I2C0->CONSET = (I2C_I2CONSET_AA | I2C_I2CONSET_I2EN);
	I2C_IntCmd(LPC_I2C0,TRUE);  
}

void SetInterrupts(void)
{
     NVIC_SetPriorityGrouping(PriorityGroup); 
 //    NVIC_SetPriority(PIN_INT1_IRQn,PINT1Priority); /*spk input from fpga*/
 //    NVIC_EnableIRQ(PIN_INT1_IRQn);
		 NVIC_SetPriority(PIN_INT2_IRQn,PINT2Priority); /*spk2 input from hardware*/
     NVIC_EnableIRQ(PIN_INT2_IRQn);
}



