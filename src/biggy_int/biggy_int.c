/**
 * File with some functions to manipulate biggy_int library.
 * This is a temporary file!
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "biggy_int.h"

/**
 * Private function to put a decimal number on 4 bits array
 */
void _bint_putbits(uint8_t *array, char num, int pos) {
    int pos_array = pos / 2; // position of num on array 8 bits

    // verify if is the firsts 4 bits or the lasts
    if (pos % 2 == 0) { // firsts
        // set 0 on firsts bits, with right mask
        array[pos_array] &= RIGHT_MASK;

        // left shift on num
        num <<= 4;
    } else { // lasts
        // set 0 on lasts bits, with left mask
        array[pos_array] &= LEFT_MASK;
    }

    // assign the value
    array[pos_array] |= num;
}

/**
 * Private function to get the number on 4 bits array
 */
uint8_t _bint_getbits(uint8_t *array, int pos) {
    int pos_array = pos / 2; // position of num on array 8 bits
    int num;

    // verify if is the firsts 4 bits or the lasts
    if (pos % 2 == 0) { // firsts
        // get num with left mask
        num = array[pos_array] & LEFT_MASK;

        // shift the num for right position (assuming decimal representation)
        num >>= 4;
    } else { // lasts
        // get num with right mask
        num = array[pos_array] & RIGHT_MASK;
    }

    return num;
}


/**
 * This function receives a big string with number (maybe the signal)
 * and returns a BiggyInt beautiful pointer.
 */
BiggyInt* bint_create(char *str_num) {
    BiggyInt *num; // pointer to be created
    int signal = 1; // int number with signal of num, -1 or 1
    int len; // length of str_num
    int i_str_num; // initial index of str_num

    // receives len and signal
    len = strlen(str_num);
    for (i_str_num = 0; i_str_num < len && (str_num[i_str_num] < '0' || str_num[i_str_num] > '9'); i_str_num++) {
        if (str_num[i_str_num] == '+') {
            signal = 1;
            break;
        } else if (str_num[i_str_num] == '-') {
            signal = -1;
            break;
        }
    }
    
    // jumps the 0 on the left, e. g., 00000123 = 123.
    for (; i_str_num < len && (str_num[i_str_num] <= '0' || str_num[i_str_num] > '9'); i_str_num++);

    // alloc the structures
    num = (BiggyInt*) malloc(sizeof(BiggyInt));

    if (i_str_num == len) { // the number is NULL and it returns 0
        num->num = (uint8_t*) malloc(sizeof(uint8_t));
        *(num->num) = 0;
        num->dec_len = 1;
        num->signal = 1;
    } else { // the number is not null, then we'll read it
        num->num = (uint8_t*) malloc(((len - i_str_num + 1) / 2) * sizeof(uint8_t));
        num->dec_len = 0;
        num->signal = signal;

        // loop on str_num and put the numbers on num->num array
        while (i_str_num < len) {
            // verify if the figure is valid
            if (str_num[i_str_num] >= '0' && str_num[i_str_num] <= '9') {
                // puts each figure on array
                _bint_putbits(num->num, _bint_char2num(str_num[i_str_num]), num->dec_len++);
            }

            i_str_num++;
        }
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

/**
 * Print the number
 */
void bint_print(BiggyInt *num) {
    int i;
    
    // prints the signal
    num->signal == 1 ? putchar('+') : putchar('-');
    for (i = 0; i < num->dec_len; i++) {
        // prints the number
        putchar(_bint_num2char(_bint_getbits(num->num, i)));
    }

    putchar('\n');
}
