#include "board.h"




#define MAX_ENTRIES 16
#define	MAX_LENGTH_OF_ENTRY 8 

enum
{
	CMD_GET_LOG_STATUS = 0X80
};

enum
{ 
	PORTB2_CODE = 0X02,
	PORTB1_CODE = 0X01
};

extern void APP_init(void);
extern void APP_task(void);	
