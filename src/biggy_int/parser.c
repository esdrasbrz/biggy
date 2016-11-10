/**
 * File with parsers functions to manipulate biggy_int library. It will
 * receive buffers and will return beautiful string number.
 */

#include <stdlib.h>
#include <string.h>

#include "biggy_int.h"

/*
* This function
** receive a raw string (tipcaly created by the user), the pointer signal
** returns the absolute value as a string and updates the pointer (-1 for negative and +1 for positive)
* The string buffer must be formated as <num>, -<num> or +<num> where num is some natural number or 0
*/

char* _bint_parseStrInput(char *buffer, int *signal) {
  //updates the pointer
  int i_signal = 0;//this guy makes sure that we're copying just digits to the returned string
  if(buffer[0] == '-'){
    *signal = -1;
    i_signal = 1;//if there's a signal, we'll have to jump it during copying
  }
  else if(buffer[0] == '+'){
    *signal = 1;
    i_signal = 1;
  }

  char *str_aux;
  str_aux = malloc((strlen(buffer) - i_signal)*sizeof(char));//just the right quantity of memory

  //standard copying loop
  for(i = i_signal; i < strlen(*buffer); i++){
    str_aux[i] = buffer[i];
  }

  return str_aux;
}
