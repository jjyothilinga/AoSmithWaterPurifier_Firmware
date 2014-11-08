#include "board.h"
#include "portb.h"

void externInt_init(void);	
void RB0INT_ISR(void);
void RB1INT_ISR(void);	
extern UINT16 debounceCount_B0;
extern UINT16 debounceCount_B1;

