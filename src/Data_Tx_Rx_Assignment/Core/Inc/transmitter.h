/*
 * transmitter.h
 *
 *  Created on: Oct 3, 2021
 *      Author: gupta
 */

#ifndef INC_TRANSMITTER_H_
#define INC_TRANSMITTER_H_

/* ************************************************************************************/
/* 						PRIVATE INCLUDES	      									  */
/* ************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* ************************************************************************************/
/* 						GLOBALS AND MACROS 											  */
/* ************************************************************************************/
#define BITS_IN_CHAR 8
#define DATA_BLOCK_LENGTH 20

extern char input_string[];

/* ************************************************************************************/
/* 						FUNCTION PROTOTYPES 										  */
/* ************************************************************************************/
char* string_to_binary(char *ptr_input_string);

#endif /* INC_TRANSMITTER_H_ */
