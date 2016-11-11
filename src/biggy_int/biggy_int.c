/**
 * File with some functions to manipulate biggy_int library.
 * This is a temporary file!
 */

#include <stdlib.h>
#include <string.h>

#include "biggy_int.h"

/**
 * Private function to put a decimal number on 4 bits array
 */
void _bint_putbits(uint8_t *array, char num, int pos) {
    int pos_array = pos / 2; // position of num on array 8 bits

    // verify if is the firsts 4 bits or the lasts
    if (pos % 2 == 0) {
        // set 0 on firsts bits, with right mask
        array[pos_array] &= RIGHT_MASK;

        // left shift on num
        num <<= 4;
    } else {
        // set 0 on lasts bits, with left mask
        array[pos_array] &= LEFT_MASK;
    }

    // assign the value
    array[pos_array] |= num;
}


/**
 * This function receives a big string with number (maybe the signal)
 * and returns a BiggyInt beautiful pointer.
 */
BiggyInt* bint_create(char *str_num) {
    BiggyInt *num; // pointer to be created
    int signal; // int number with signal of num, -1 or 1
    int len; // length of str_num
    int i_str_num = 0; // initial index of str_num
    int i_num; // initial index of num->num array


    // receives len and signal
    len = strlen(str_num);
    if (!_bint_parseStrInput(str_num, &signal)) {
        // here, the number has not signal
        signal = 1;
    } else {
        // change the length and initial index
        len--;
        i_str_num++;
    }

    // alloc the structures
    num = (BiggyInt*) malloc(sizeof(BiggyInt));
    num->num = (uint8_t*) malloc(((len + 1) / 2) * sizeof(uint8_t));
    num->dec_len = len;


    // loop on str_num and put the numbers on num->num array
    for (i_num = 0; i_num < (num->dec_len + 1) / 2; i_num++) {
        // puts each figure on array
        _bint_putbits(num->num, str_num[i_str_num] - '0', i_num);

        i_str_num++;
    }

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
