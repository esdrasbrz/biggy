/**
 * This file contains the casts functions
 */

#include "biggy_int.h"

/**
 * Casts between uint8_t and char
 */

uint8_t _bint_char2num(char c_num) {
    return (uint8_t) c_num - '0';
}

char _bint_num2char(uint8_t num) {
    return (char) num + '0';
}
