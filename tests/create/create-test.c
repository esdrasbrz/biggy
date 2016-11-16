/**
 * File for creation tests 
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <biggy/biggy_int.h>

int main(void) {
    BiggyInt *num;
    char str_num[] = "awlefjxmxhd-sakjfj0000000123jaskdjf4fj0000000asdfjh    ";
    char str_num_expected[] = "-12340000000";
    char *str_num_returned;

    num = bint_create(str_num);

    str_num_returned = bint_biggy2str(num);

    puts("The number is:");
    bint_print(num);
    putchar('\n');

    // verify the success
    if (strcmp(str_num_expected, str_num_returned) == 0) {
        puts("Success!");
    } else {
        puts("ERROR!");

        printf("\nexpected: %s\nlen: %d\n\nreturned: %s\nlen: %d\ndec_len: %d\n",
                str_num_expected, (int) strlen(str_num_expected),
                str_num_returned, (int) strlen(str_num_returned), num->dec_len);
    }

    free(str_num_returned);
    bint_free(num);

    return 0;
}
