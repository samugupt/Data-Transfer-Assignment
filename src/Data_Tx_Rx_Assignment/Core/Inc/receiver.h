/*
 * receiver.h
 *
 *  Created on: Oct 3, 2021
 *      Author: gupta
 */

#ifndef INC_RECEIVER_H_
#define INC_RECEIVER_H_


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
#define RADIX 2
#define STRING_DELIMITER " "
#define STRING_SIZE 25


/* ************************************************************************************/
/* 						FUNCTION PROTOTYPES 										  */
/* ************************************************************************************/
char* binary_to_string(char *ptr_input_binary);

#endif /* INC_RECEIVER_H_ */
