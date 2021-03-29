/*
 * Author: Declan McGranahan - mcgranad@bc.edu
*/
#include <stdio.h>
#include <stdlib.h>

//Calls the Multiplication Function from multiply.c
long multiply(long, long);

//Main function that takes scanner input of two numbers and multiplies
int main(void) {
    long a;
    long b;
    printf("> ");
    while (scanf("%ld %ld", &a, &b) != 0) {
        printf(" %ld * %ld = %ld\n", a, b, multiply(a, b));
        printf("> ");
    }
    return EXIT_SUCCESS;
}