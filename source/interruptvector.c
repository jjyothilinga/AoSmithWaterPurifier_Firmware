#include "board.h"
#include "timer.h"
#include "externInterrupts.h"
#include "uart_driver.h"


/*
 * For PIC18xxxx devices, the low interrupt vector is found at 000000018h.
 * Change the default code section to the absolute code section named
 * low_vector located at address 0x18.
 */


#pragma code high_vector = 0x08
void high_interrupt (void)
{
	/*
   	* Inline assembly that will jump to the ISR.
   	*/


	if(PIR1bits.TMR1IF == 1)
	{
		_asm goto TMR1_ISR _endasm
	}

    if(INTCONbits.INT0IF == 1)
	{
		_asm goto RB0INT_ISR _endasm
	}

	if(INTCON3bits.INT1IF == 1)
	{
		 _asm goto RB1INT_ISR _endasm
	}

	if(INTCONbits.TMR0IF == 1)
	{
  		_asm goto TMR0_ISR _endasm
	}

	if( PIR1bits.RCIF == 1 )
	{
		_asm
			goto UartReceiveHandler
		_endasm
	}

}
/*
#pragma code low_vector=0x18
void low_interrupt (void)
{
	if(INTCONbits.TMR0IF == 1)
	{
  		_asm goto TMR0_ISR _endasm
	}
}
*/
/*
*------------------------------------------------------------------------------
* void EnableInterrupts(void)

* Summary	: Enable interrupts and related priorities
*
* Input		: None
*
* Output	: None
*
*------------------------------------------------------------------------------
*/
void EnableInterrupts(void)
{
    //	RCONbits.IPEN = 1;
     

     

	// Enable interrupt priority
  	RCONbits.IPEN = 1;
 	// Enable all high priority interrupts
  	INTCONbits.GIEH = 1;
    //SETTING INTCON
    INTCONbits.TMR0IE = 1;
    INTCONbits.INT0IE = 1;
    INTCONbits.RBIE = 0;
    INTCONbits.TMR0IF = 0;
    INTCONbits.INT0IF = 0;
    INTCONbits.RBIF = 0;

  	//INTCON = 0xB0;

}