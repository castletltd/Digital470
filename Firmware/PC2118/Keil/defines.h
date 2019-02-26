/* Change here to modify modulator performance parameters */

#define PERIOD 2083			/* Half period - (25kHz) */
#define MAXPHASE 1883     /* Defines minimum duty */
#define MINPHASE 200				/* Defines maximum duty */
#define MINPERIOD 1400		/* Defines min period and max frequency 35kHz */
#define MAXPERIOD 2000		/*Defines max period and minimum frequency 25khz */
#define DEADBAND 0x6464 		/* Defines deadband in each half H_Bridge in 10nS incremants (0x6464 = 1uS both halves)*/
#define WATCHDOG 0x00008000	/* Defines FPGA implemented watchdog timer period value */
#define INIT_PHASE_PERIOD 0x07D00708/* value of phaseperiod for initialization was 2000 : 1800  */

#define FLT_MASK					0xf0		/* test for F1 to F4 active */
#define LR_MASK						0x08		/* test status of Local/Reomte input */
#define RS_MASK						0x04		/* test for Reset input active */
#define STP_MASK					0x01		/* test for open Stop input */		
#define STA_MASK					0x02		/* test for Start input active */
#define TRIP_MASK					0x30		/* specify which alarms trip */

#define DO1_MASK					0x00000010	/* Bit position of Dig out 1 */
#define IGBTEN_MASK				0x00000002	/* Bit position of IGBT Driver enable signal */
#define IGBTPSU_MASK			0x00000004	/* Bit position of IGBT psu enable signal */
#define IGBTDEL_MASK			0x00000006 /* Combined mask to turn on psu and disable IGBTs */
#define DIGIN_MASK				0x0000ff00 /* mask to extract digital input bits */
#define MS_MASK           0x00000040 /* mask to extract Master/Slave status */
#define SLAVE_EN_MASK			0x00000080 /* bit position of slave enable signal */
#define IP_RESET_MASK     0x00000100 /*IP trip latch reset bit */

/* User friendly defines, only change if hardware changes*/

#define WATCHDOG_BIT 			0x00000001 	/* Watchdog bit in FPGA reg 6 bit 0 */
#define IPTRIP_BIT				0x00000004	/* IP trip latch reset bit in FPGA reg 6 bit 2 */
#define RUN_BIT						0x00000002	/* IGBT Run input FPGA reg 7 bit 1 */

#define PHASEPERIODREG		0
#define TO_FPGA_REG				6
#define FROM_FPGA_REG			7				
#define FPGA_RAM(c)       (*(volatile int*) (0x1C000000+ ((c) * 0x4)))

#define ever ( ;; )


