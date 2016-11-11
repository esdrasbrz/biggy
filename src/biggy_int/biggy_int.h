/**
 * Header file with structures and functions to very big integer manipulations.
 * Here we'll manipulate a big number with decimal array representations.
 */

#ifndef BIGGY_INT_H
#define BIGGY_INT_H

#include <stdint.h>

/**
 * Important defines for all functions that manipulate the bits
 */
#define BLOCK_SIZE 8 // number of bits on all position of num array.

// 8 bits mask representations
#define LEFT_MASK 240 // 11110000
#define RIGHT_MASK 15 // 00001111


/**
 * The big_int struct. Here is the main representations of numbers
 */
typedef struct {
    uint8_t *num; // array representation
    char signal; // -1 if num < 0, else 1
    int dec_len; // length of decimal numbers represented in *num
} BiggyInt;


/**
 * Functions
 */

/**
 * BiggyInt Parsers utilities. Functions code in parser.c
 */

/**
 * This private func returns an integer with 1 if buffer has a signal and
 * 0 if it hasn't.
 *
 * @param char *buffer - Initial buffer.
 * @param int *signal - Pointer with mem address of signal on BiggyInt structure.
 *
 * @return int - The output boolean
 */
int _bint_parseStrInput(char *buffer, int *signal);


/**
 * BiggyInt brute manipulations. Functions code in biggy_int.c
 */

/**
 * Private function to put a char number on absolute position in 4 bits array
 * representation.
 *
 * BE CAREFUL, because this funcs assume that pos = 0 is the firsts 4 bits of array[0]
 * and pos = 1 is the lasts 4 bits of array[0], pos = 2 the firsts 4 bits of array[1] ....
 *
 * @param uint8_t* array - The 4 bits array representation
 * @param char num - The number to put
 * @param pos - The position of char num on uint8_t *array
 */
void _bint_putbits(uint8_t *array, char num, int pos);

/**
 * This func creates a BiggyInt object and returns a pointer to it. The params
 * is a string with optional signal ('+' or '-').
 *
 * @param char *str_num - string (THE \0 IS VERY IMPORTANT!) with the number
 *
 * @return BiggyInt* - a pointer to our number representation
 */
BiggyInt* bint_create(char *str_num);

/**
 * This func takes a BiggyInt number and free all allocated memory.
 * YOU MUST CALL THIS FUNC!
 *
 * @param BiggyInt *num - A BiggyInt pointer
 */
void bint_free(BiggyInt *num);

#endif // BIGGY_INT_H
