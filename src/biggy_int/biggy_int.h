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

// ********************** //


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
 * Private function to get a char (uint8_t) number of absolute position in 4 bits array
 * representation.
 *
 * BE CAREFUL, the int pos parameter has the same representation of _bint_putbits func.
 *
 * @param uint8_t* array - The 4 bits array representation
 * @param int pos - The position of uint8_t *array with 4 bits.
 *
 * @return uint8_t - The number on array, at int pos position.
 */
uint8_t _bint_getbits(uint8_t *array, int pos);

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

/**
 * This func receives a BiggyInt pointer and prints the number
 *
 * @param BiggyInt *num - pointer to number that will be printed
 */
void bint_print(BiggyInt *num);

// ***************** //

/**
 * Casts functions. Code on casts.c file
 */

/**
 * This func receives an unsigned number of 8 bits (0, 1, 2, 3, ...) and
 * returns the char ('0', '1', '2', '3', ...).
 *
 * @param uint8_t num - The number to cast
 * 
 * @return char - Correspondent char
 */
char _bint_num2char(uint8_t num);

/**
 * This func receives a char number ('0', '1', '2', '3', ...) and
 * returns an unsigned int of 8 bits (0, 1, 2, 3, ...).
 *
 * @param char c_num - The char to cast
 * 
 * @return uint8_t - Correspondent unsigned number
 */
uint8_t _bint_char2num(char c_num);

/**
 * This func receives a BiggyInt representation number and returns it on
 * string. The first element, str[0], is the signal ('+' or '-') and the others
 * are the figures of num.
 *
 * @param BiggyInt *num - pointer to input number
 *
 * @return char* - Correspondent string of num.
 */
char* bint_biggy2str(BiggyInt *num);


#endif // BIGGY_INT_H
