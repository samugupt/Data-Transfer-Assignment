/*
 * receiver.c
 *
 *  Created on: Oct 3, 2021
 *      Author: gupta
 */


/* ************************************************************************************/
/* 						PRIVATE INCLUDES	      									  */
/* ************************************************************************************/
#include "receiver.h"


/* ************************************************************************************/
/* 							GLOBALS				      								  */
/* ************************************************************************************/


/* ************************************************************************************/
/* 							FUNCTIONS DEFINITIONS									  */
/* ************************************************************************************/

/*
 * Description - This API converts the received binary string back to character string
 * @params - pointer to the string in binary format
 * @return - pointer to the character string
 */
char* binary_to_string(char *ptr_input_binary) {
    char *ptr_string = malloc(sizeof(char)*STRING_SIZE + 1);
    char *token = strtok(ptr_input_binary, " ");

    // keep track of start
    char *start = ptr_string;

    while(token != NULL) {
        char *data = token;
        char c = strtol(data, (char **)NULL, RADIX); // Converts binary to char
        *ptr_string = c;
        ptr_string++;
        token = strtok(NULL, STRING_DELIMITER);
    }
    *ptr_string = '\0'; // Add NULL character at end of string
    ptr_string = start;
    return ptr_string;
}
