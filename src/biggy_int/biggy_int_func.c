/**
 * File with some functions to manipulate biggy_int library.
 * This is a temporary file!
 */

#include <stdlib.h>
#include <string.h>

#include "biggy_int.h"

/*
* This function
** receives a raw string (tipcaly created by the user) and the pointer signal
** returns 1 if the received string has a signal and 0 if not, also it updates the pointer (-1 for negative and 1 for positive)
* The string buffer must be formated as <num>, -<num> or +<num> where <num> is some natural number or 0
*
* @param char *buffer - a string containing a Big natural number or zero in decimal representations
* @param int *siganl - a pointer which assumes -1 if the number is negative and 1 if positive
*
* @return int - 1 if there's a signal character ('-' or '+') and 0 if not
*/

int _bint_parseStrInput(char *buffer, int *signal) {
    //checks if there's a plus minus signal
    if(buffer[0] == '+'){
        *signal = 1;//update the pointer
        return 1;//if there's a signal, we'll have to jump it during copying
    }
    else if(buffer[0] == '-'){
        *signal = -1;
        return 1;
    }

    return 0;
}

/*
 * This function
 ** receives a BiggyInt number and free all allocated memory.
 *
 * Be a good programmer, use this function
 *
 * @param BiggyInt *num - A BiggyInt pointer
 */
void bint_free(BiggyInt *num){
    free(num->num);//frees the only vector on num
    free(num);//free the structure
}
