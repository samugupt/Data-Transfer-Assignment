/*
 * monitor.h
 *
 *  Created on: Oct 5, 2021
 *      Author: gupta
 */

#ifndef INC_MONITOR_H_
#define INC_MONITOR_H_


/* ************************************************************************************/
/* 						PRIVATE INCLUDES	      									  */
/* ************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "transmitter.h"
#include "receiver.h"


/* ************************************************************************************/
/* 						GLOBALS AND MACROS 											  */
/* ************************************************************************************/
#define SIZE_OF_UART_TX_BUFFER 100

extern char uart_tx_buffer[SIZE_OF_UART_TX_BUFFER];

typedef enum {
    TRANSFER_OK = 0,
    TRANSFER_ERR = 1
}TRANSFER_STATUS;

typedef enum {
    CONNECT_OK = 0,
    M_TO_A_CONNECT_ERR = 1,
    M_TO_B_CONNECT_ERR = 2,
    A_TO_B_CONNECT_ERR = 3
}MONITOR_RESULT;


/* ************************************************************************************/
/* 						FUNCTION PROTOTYPES 										  */
/* ************************************************************************************/
MONITOR_RESULT Is_device_M_to_A_connected(void);
MONITOR_RESULT Is_device_M_to_B_connected(void);
MONITOR_RESULT Is_device_A_to_B_connected(void);
uint16_t get_data_blocks(uint16_t string_length);
char* clock_generator(void);
TRANSFER_STATUS transfer_data_A_to_B(char *input_string, int temp_blocks);
TRANSFER_STATUS transfer_data_B_to_A(char *input_string, int temp_blocks);
/* ************************************************************************************/

#endif /* INC_MONITOR_H_ */
