#include "externInterrupts.h"
#include "portb.h"


#pragma udata EXINT_DATA
UINT8 portb0_hasData = 0;
UINT8 portb1_hasData = 0;
#pragma udata

void externInt_init(void)
{   
	OpenRB0INT( PORTB_PULLUPS_ON & FALLING_EDGE_INT & PORTB_INT_PRIO_HIGH );
  
    OpenRB1INT( PORTB_PULLUPS_ON & FALLING_EDGE_INT &PORTB_INT_PRIO_HIGH );

	INTCONbits.INT0IF = 0;	
	INTCON3bits.INT1IF = 0;
}

#pragma interrupt RB0INT_ISR
void RB0INT_ISR(void)
{

  	INTCONbits.INT0IF =0;	//cleat interrupt flag	

	if(debounceCount_B0 < 2500)
		return;
	else
		debounceCount_B0 = 0;
	portb0_hasData = 1;	//set interrupt indication

}
	

#pragma interrupt RB1INT_ISR
void RB1INT_ISR(void)
{
 	INTCON3bits.INT1IF = 0;

	if(debounceCount_B1 < 2500)
		return;
	else
	debounceCount_B1 = 0;
  	portb1_hasData = 1;	//set interrupt indication

}	



