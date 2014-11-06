#include "externInterrupts.h"
#include "portb.h"


#pragma idata EXINT_DATA
UINT8 portb2_hasData = 0;
UINT8 portb1_hasData = 0;
#pragma idata

void externInt_init(void)
{   
	OpenRB2INT( PORTB_PULLUPS_OFF & FALLING_EDGE_INT & PORTB_INT_PRIO_HIGH );
  
    OpenRB1INT( PORTB_PULLUPS_OFF & FALLING_EDGE_INT &PORTB_INT_PRIO_HIGH );


	INTCON3bits.INT2IE = 1;
	INTCON3bits.INT2IF = 0;	
	INTCON3bits.INT1IF = 0;
}

#pragma interrupt RB2INT_ISR
void RB2INT_ISR(void)
{

  	INTCON3bits.INT2IF =0;	//clear interrupt flag	

	if(debounceCount_B2 < 2500)
		return;
	else
		debounceCount_B2 = 0;
	portb2_hasData = 1;	//set interrupt indication

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



