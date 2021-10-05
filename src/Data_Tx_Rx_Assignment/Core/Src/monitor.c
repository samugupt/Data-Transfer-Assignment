/*
 * monitor.c
 *
 *  Created on: Oct 5, 2021
 *      Author: gupta
 */


/* ************************************************************************************/
/* 						PRIVATE INCLUDES	      									  */
/* ************************************************************************************/
#include "monitor.h"


/* ************************************************************************************/
/* 							GLOBALS				      								  */
/* ************************************************************************************/
char uart_tx_buffer[SIZE_OF_UART_TX_BUFFER] = "";


/* ************************************************************************************/
/* 							FUNCTIONS DEFINITIONS									  */
/* ************************************************************************************/

/* Initialization Steps */
MONITOR_RESULT Is_device_M_to_A_connected() {
    return CONNECT_OK; // Assuming connection successful
}

MONITOR_RESULT Is_device_M_to_B_connected() {
    return CONNECT_OK;
}

MONITOR_RESULT Is_device_A_to_B_connected() {
    // Sending a character via UART
    // if (transmitted data == received data) {return connection OK;}
    // else {return connection error;}
    return CONNECT_OK;
}

char* clock_generator() {
    char *clock_buffer = malloc((DATA_BLOCK_LENGTH*BITS_IN_CHAR) + 100);
    char *start_clock = clock_buffer;
    for(int k=0; k<20; k++) {
        for(int j=0; j<BITS_IN_CHAR; j++,clock_buffer++) {
            if((j%2) == 0) {
                *clock_buffer = '0';
            }
            else {
                *clock_buffer = '1';
            }
        }
        // add space after every 8 bits
        *clock_buffer = ' ';
        clock_buffer++;
    }
    *clock_buffer = '\0';
    clock_buffer = start_clock;
    return clock_buffer;
}

uint16_t get_data_blocks(uint16_t string_length) {
	int number_of_data_blocks = 0;

	if((string_length % DATA_BLOCK_LENGTH) == 0) {
	  number_of_data_blocks = string_length / DATA_BLOCK_LENGTH;
	}
	else {
	  number_of_data_blocks = (string_length / DATA_BLOCK_LENGTH) + 1;
	}
	return number_of_data_blocks;
}

TRANSFER_STATUS transfer_data_A_to_B(char *input_string, int temp_blocks) {
	int blocks_sent = 0;
	// data transfer buffer
	char tx_buffer_string[DATA_BLOCK_LENGTH] = "";
    float progress = 0.0;
    // keep track of start position of the input string
    char *ptr_start_string = input_string;
    char *ptr_output_binary;
    int number_of_data_blocks = temp_blocks;

    while(temp_blocks > 0) {

        // Copy the first 20 bytes to transmit buffer
        memcpy(tx_buffer_string, ptr_start_string, DATA_BLOCK_LENGTH);
        sprintf("TRANSFER STRING: %s\n\n", tx_buffer_string);
        memset(uart_tx_buffer, 0, strlen(uart_tx_buffer));

        // clock signal
        char *clock_buffer = clock_generator();
        sprintf(uart_tx_buffer, "CLK: %s\n\n", clock_buffer);
        memset(uart_tx_buffer, 0, strlen(uart_tx_buffer));

        // transmit 20 byte block of data
        ptr_output_binary = string_to_binary(tx_buffer_string);
        sprintf(uart_tx_buffer, "BINARY STRING: %s\n\n", ptr_output_binary);
        memset(uart_tx_buffer, 0, strlen(uart_tx_buffer));

        char *ptr_output_string = binary_to_string(ptr_output_binary);
        sprintf(uart_tx_buffer, "CHARACTER STRING: %s\n\n", ptr_output_string);
        memset(uart_tx_buffer, 0, strlen(uart_tx_buffer));

        temp_blocks--;
        blocks_sent = number_of_data_blocks - temp_blocks;
        sprintf(uart_tx_buffer, "DATA BLOCKS SENT: %d\n\n", blocks_sent);
        memset(uart_tx_buffer, 0, strlen(uart_tx_buffer));

        progress = (blocks_sent / number_of_data_blocks)*100;
        sprintf(uart_tx_buffer, "************ %0.2f%% TRANSFER COMPLETE! ************\n\n", progress);
        memset(uart_tx_buffer, 0, strlen(uart_tx_buffer));

        ptr_start_string += DATA_BLOCK_LENGTH; // pointer pointing to next data block
    }
    if(temp_blocks != 0) {
        return TRANSFER_ERR;
    }
    return TRANSFER_OK;
}

TRANSFER_STATUS transfer_data_B_to_A(char *input_string, int temp_blocks) {
	return TRANSFER_OK;
}
