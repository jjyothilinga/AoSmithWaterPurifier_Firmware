 #ifndef DEVICE_H
#define DEVICE_H

/*
*------------------------------------------------------------------------------
* device.h
*
* Include file for port pin assignments
*

*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* File				: device.h
*------------------------------------------------------------------------------
*

*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/
#ifdef __18F4520
#include <p18f4520.h>
#elif __18F4620
#include <p18f4620.h>
#endif
#include <delays.h>
#include <timers.h>
#include "typedefs.h"
#include "config.h"




/*
*------------------------------------------------------------------------------
* Hardware Port Allocation
*------------------------------------------------------------------------------
*/

//Heart Beat Port

#define		 HEART_BEAT 			PORTDbits.RD2
#define		 HEART_BEAT_DIRECTION 	TRISDbits.TRISD2



#define 	SER_TX					PORTCbits.RC6 		// serial transmit
#define		SER_TX_DIR				TRISCbits.TRISC6
#define 	SER_RX					PORTCbits.RC7			// serial receive
#define		SER_RX_DIR				TRISCbits.TRISC7



// Display digit select lines
#define		DIGIT_SEL_A					PORTAbits.RA1 			// demux digit sel A
#define		DIGIT_SEL_A_DIRECTION		TRISAbits.TRISA1
#define		DIGIT_SEL_B					PORTAbits.RA0			// demux digit sel B
#define		DIGIT_SEL_B_DIRECTION		TRISAbits.TRISA0

//External Interrupt 
#define     EXTERNAL_INTERRUPT0              PORTBbits.RB0
#define     EXTERNAL_INTERRUPT0_DIRECTION    TRISBbits.TRISB0
#define     EXTERNAL_INTERRUPT1              PORTBbits.RB1
#define     EXTERNAL_INTERRUPT1_DIRECTION    TRISBbits.TRISB1






	
/*
*------------------------------------------------------------------------------
* Public Defines
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Macros
*------------------------------------------------------------------------------
*/

#define DEVICE_ID			(0x01)


//#define SYSTEM_CLOCK			(20000000UL)	// Hz		// 20MHz external crystal  used

//#define SYSTEM_CLOCK			(40000000UL)	// Hz		// 10MHz external crystal x4 PLL

#define SYSTEM_CLOCK			(16000000UL)	// Hz		// 4MHz internal oscillator x4 PLL

#define PERIPHERA_CLOCK			(SYSTEM_CLOCK / 4)UL

#define PERIPHERA_CLOCK_PERIOD 	(1 / PERIPHERA_CLOCK)UL



// Direction controle bit is processor specific ,
#define PORT_OUT				(BOOL)(0)
#define PORT_IN					(0XFF)

#define OFF_FOREVER				(BOOL)(0)
#define LOOP_FOREVER			(BOOL)(1)

#define SWITCH_OFF				(BOOL)(0)
#define SWITCH_ON				(BOOL)(1)


#define DISPLAY_DISABLE			(BOOL)(1)
#define DISPLAY_ENABLE			(BOOL)(0)
void EnableInterrupts(void);

/*
#ifdef __74LS374__
#undef DISPLAY_DISABLE
#undef DISPLAY_ENABLE

#define DISPLAY_DISABLE			(BOOL)(0)
#define DISPLAY_ENABLE			(BOOL)(1)

#endif 			//__74LS374__
*/


#define GetSystemClock()		(SYSTEM_CLOCK)      // Hz
#define GetInstructionClock()	(GetSystemClock()/4)
#define GetPeripheralClock()	GetInstructionClock()


#define BUZZER_ON()			BUZ_OP = SWITCH_ON;
#define BUZZER_OFF()		BUZ_OP = SWITCH_OFF;

// Disable global interrupt bit.
#define ENTER_CRITICAL_SECTION()	INTCONbits.GIE = 0;

// Enable global interrupt bit.
#define EXIT_CRITICAL_SECTION()		INTCONbits.GIE = 1;

#define ENABLE_GLOBAL_INT()			EXIT_CRITICAL_SECTION()


#define DISABLE_ADC_INTERRUPT()		PIE1bits.ADIE = 0
#define ENABLE_ADC_INTERRUPT()		PIE1bits.ADIE = 1

#define DISABLE_INT0_INTERRUPT()	INTCONbits.INT0IE = 0
#define ENABLE_INT0_INTERRUPT()		INTCONbits.INT0IE = 1
#define CLEAR_INTO_INTERRUPT()		INTCONbits.INT0IF = 0


#define DISABLE_TMR0_INTERRUPT()	INTCONbits.TMR0IE = 0
#define ENABLE_TMR0_INTERRUPT()		INTCONbits.TMR0IE = 1

#define DISABLE_TMR1_INTERRUPT()	PIE1bits.TMR1IE = 0
#define ENABLE_TMR1_INTERRUPT()		PIE1bits.TMR1IE = 1


#define DISABLE_UART_TX_INTERRUPT()	PIE1bits.TXIE = 0
#define ENABLE_UART_TX_INTERRUPT()	PIE1bits.TXIE = 1

#define DISABLE_UART_RX_INTERRUPT()	PIE1bits.RCIE = 0
#define ENABLE_UART_RX_INTERRUPT()	PIE1bits.RCIE = 1


#define HOLD_ATKBD_CLOCK()		    ATKBD_CLK_DIR= PORT_OUT;\
									ATKBD_CLK = 0;

#define RELEASE_ATKBD_CLOCK()	  	ATKBD_CLK_DIR = PORT_IN;\
									ATKBD_CLK = 1;

#define SET_INT0_FALLING_EDGE_TRIGGER()	INTCON2bits.INTEDG0 = 0

#define	ATKBD_INTERRUPT_EDGE	INTCON2.INTEDG0		

#define ENB_485_TX()	TX_EN = 1;
#define ENB_485_RX()	TX_EN = 0;

#define Delay10us(us)		Delay10TCYx(((GetInstructionClock()/1000000)*(us)))
#define DelayMs(ms)												\
	do																\
	{																\
		unsigned int _iTemp = (ms); 								\
		while(_iTemp--)												\
			Delay1KTCYx((GetInstructionClock()+999999)/1000000);	\
	} while(0)

/*
*------------------------------------------------------------------------------
* Public Data Types
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Variables (extern)
*------------------------------------------------------------------------------
*/


/*
*------------------------------------------------------------------------------
* Public Constants (extern)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Function Prototypes (extern)
*------------------------------------------------------------------------------
*/

extern void BRD_init(void);

#endif
/*
*  End of device.h
*/