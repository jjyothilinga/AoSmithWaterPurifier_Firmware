#include "board.h"
#include "portb.h"

void externInt_init(void);	
void RB2INT_ISR(void);
void RB1INT_ISR(void);	
extern UINT16 debounceCount_B2;
extern UINT16 debounceCount_B1;

