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
 * This private func returns a new string with just number representation,
 * removing all useless chars. It returns signal on *signal pointer param.
 *
 * @param char *buffer - Initial buffer.
 * @param int *signal - Pointer with mem address of signal on BiggyInt structure.
 *
 * @return char* - The output number in str
 */
char* _bint_parseStrInput(char *buffer, int *signal);


/**
 * BiggyInt brute manipulations. Functions code in biggy_int.c
 */

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
void bint_free(BiggyInt *num){
    free(num->num);//frees the only vector on num
    free(num);//free the structure
}

#endif // BIGGY_INT_H
