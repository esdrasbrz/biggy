/**
 * This file contains the casts functions
 */

#include <stdlib.h>
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

/**
 * Casts between BiggyInt and string
 */

char* bint_biggy2str(BiggyInt *num) {
    char *str_num;
    int i;

    // alloc the string
    str_num = (char*) malloc((num->dec_len + 2) * sizeof(char));
    
    // put the signal on the first position
    str_num[0] = num->signal == 1 ? '+' : '-';

    // loop to get all figures of num
    for (i = 1; i <= num->dec_len; i++) {
        str_num[i] = _bint_num2char(_bint_getbits(num->num, i - 1));
    }

    // put the end of string
    str_num[i] = '\0';

    return str_num;
}
