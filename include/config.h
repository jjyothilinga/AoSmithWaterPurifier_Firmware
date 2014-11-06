#ifndef CONFIG_H
#define CONFIG_H

/*
*------------------------------------------------------------------------------
* config.h
*
*/




#define DEVICE_ADDRESS			0XFA


//#define __FACTORY_CONFIGURATION__

//MMD module configuration
#define MMD_MAX_CHARS		8
#define MMD_MAX_SEGMENTS	4
#define MMD_MAX_ADDRESS		128
#define __MMD_STATIC__


//DIGIT DISPLAY TEST
#define __DISPLAY_TEST__
//#define __COMMON_CATHODE__

//#define __FACTORY_CONFIGURATION__
//#define __SIMULATION__


#define MAX_MSG 7
#define DISPLAY_REFRESH_PERIOD	2	//period of refresh in milliseconds

/* UART Configurations */
enum
{
	RX_PACKET_SIZE = 64,
	TX_PACKET_SIZE = 64
};

#define 	RECEIVER_MAX_PAKET_SIZE		(RX_PACKET_SIZE)	
#define 	TRANSMITTER_MAX_PAKET_SIZE	(TX_PACKET_SIZE)


/* COM module configuration */
#define __BCC_XOR__
#define __RESPONSE_ENABLED__
//#define __UART_TEST__
//#define __LOOP_BACK__
#define BROADCAST_ADDRESS		0xFA
#define CMD_SOP	0xAA
#define CMD_EOP 0xBB
#define RESP_SOP	0xCC
#define RESP_EOP	0xDD


/* APP configuration */
//#define TEST

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

#endif
/*
*  End of config.h
*/



