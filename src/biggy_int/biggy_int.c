/**
 * File with some functions to manipulate biggy_int library.
 * This is a temporary file!
 */

#include <stdlib.h>
#include <string.h>

#include "biggy_int.h"

/**
 * This function receives a big string with number (maybe the signal)
 * and returns a BiggyInt beautiful pointer.
 */
BiggyInt* bint_create(char *str_num) {
    BiggyInt *num; // pointer to be created
    int signal; // int number with signal of num, -1 or 1
    int len; // length of str_num
    int i = 0; // initial index of str_num


    // receives len and signal
    len = strlen(str_num);
    if (!_bint_parseStrInput(str_num, &signal)) {
        // here, the number has not signal
        signal = 1;
    } else {
        // change the length and initial index
        len--;
        i++;
    }

    // alloc the structures
    num = (BiggyInt*) malloc(sizeof(BiggyInt));
    num->num = (uint8_t*) calloc((len + 1) / 2, sizeof(uint8_t));
    num->dec_len = len;

    return num;
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
