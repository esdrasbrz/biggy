/**
 * File for tests in a unique main function
 */

#include <stdio.h>
#include <stdlib.h>

#include <biggy/biggy_int.h>

int main(void) {
    BiggyInt* num;
    char str_num[100];

    scanf("%s", str_num);

    num = bint_create(str_num);

    bint_free(num);

    return 0;
}
