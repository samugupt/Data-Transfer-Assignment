/*
 * transmitter.c
 *
 *  Created on: Oct 3, 2021
 *      Author: gupta
 */


/* ************************************************************************************/
/* 						PRIVATE INCLUDES	      									  */
/* ************************************************************************************/
#include "transmitter.h"


/* ************************************************************************************/
/* 							GLOBALS				      								  */
/* ************************************************************************************/
char input_string[] = "Hello World. This is a sender receiver task assignment";


/* ************************************************************************************/
/* 							FUNCTIONS DEFINITIONS									  */
/* ************************************************************************************/
/*
 * Description - This API converts an input string into binary format
 * @params - pointer to the string
 * @return - pointer to the string in binary format
 */
char* string_to_binary(char *ptr_input_string) {
    // allocate binary string length + 1 for null character
    char *binary = (char *)malloc((DATA_BLOCK_LENGTH * BITS_IN_CHAR) + 10);
    char *start = binary;
    char *ptr;

    if(strlen(ptr_input_string) == 0) {
        *binary = '\0';
        return binary;
    }

    // loop over input characters
    for(ptr = ptr_input_string; *ptr != '\0'; ptr++) {
        // loop over input character bits
        for(int j=(BITS_IN_CHAR - 1); j>=0; j--,binary++) {
            *binary = (*ptr & (1 << j)) ? '1' : '0';
        }
        // Add space after every 8 bits
        *binary = ' ';
        binary++;
    }
    *binary = '\0';
    binary = start;
    return binary;
}
