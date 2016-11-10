/**
 * File with parsers functions to manipulate biggy_int library. It will
 * receive buffers and will return beautiful string number.
 */

#include <stdlib.h>
#include <string.h>

#include "biggy_int.h"

/*
* This function
** receives a raw string (tipcaly created by the user) and the pointer signal
** returns 1 if the received string has a signal or 0 if don't, also it updates the pointer (-1 for negative and +1 for positive)
* The string buffer must be formated as <num>, -<num> or +<num> where <num> is some natural number or 0
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
