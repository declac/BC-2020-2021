/*
 *
 * C program to convert a real value to IEEE 754 floating point representation 
 * 
 * Author: Declan McGranahan
 */ 

//The Libraries we need to include in order to run the code
#include <math.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


/*
 * Takes an input as an unsigned int.
 * Shifts the mask over by 31.
 * Prints out the coressponding characters for the binary representation.
*/
void print_binary(unsigned int num) {
    unsigned int shift = 31;
    unsigned int mask = 1 << shift;
    printf("Binary Representation:\n");
    while(mask) {
        putchar(((num & mask) >> shift) + '0');
        mask >>= 1;
        --shift;
    }
    putchar('\n');
}

/* 
 * Takes an input unsigned int and names it sign.
 * Shifts the input over by 31 to find the right most bit.
 * Prints out the right most bit in both Binary and Decimal.
 * These two will be the same. 
*/
void print_sign(unsigned int sign) {
    unsigned int shift = 31;
    unsigned int mask = 1 << shift;
    printf("\nSign:\n");
    printf("\tBinary: ");
    sign = ((sign & mask) >> shift) + '0';
    putchar(sign);
    putchar('\n');
    printf("\tDecimal: ");
    putchar(sign);
    putchar('\n');
}

/*
 * Takes an unsigned int as the input.
 * Shifts the input over so that we get bits 23-30.
 * Prints out the Binary representation.
 * Then prints out the decimal representation.
*/
void print_exponent(unsigned int input) {
    unsigned int shift = 7;
    unsigned int mask = 0xff << 23;
    unsigned int exponent = (input & mask) >> 23;
    unsigned int bias = 127;
    printf("\nExponent:\n");
    mask = 1 << shift;
    printf("\tBinary: ");
    while(mask) {
        putchar(((exponent & mask) >> shift) + '0');
        mask >>= 1;
        --shift;
    }
    putchar('\n');
    printf("\tDecimal: %u\n", exponent);
    printf("\tWithout Bias: %u\n", exponent-bias);
}

/*
 * Takes an unsigned int as the input.
 * Shifts the input over so that we get the bottom 23 bits.
 * Shifts the mask to remove the trailing zeros so we are left without them.
 * Adds the one to the Binary representation.
 * Prints the decimal followed by a seperation line.
 * Prints out the Binary representation.
 * Then prints out the decimal representation.
*/
void print_mantissa(unsigned int input) {
    printf("\nMantissa:\n");
    printf("\tBinary (With Added 1): ");
    unsigned int shift = 22;
    unsigned int mask = 0x7fffff;
    unsigned int mantissa = input & mask;
    mask = 1 << shift;
    unsigned int inverse_mask = ~mask;
    float value = 1.0;
    float weight = 1.0;
    printf("1.");
    while(mantissa) {
        unsigned int result = (mantissa & mask) >> shift;
        putchar(result + '0');
        weight /= 2.0;
        value += result * weight;
        mask >>= 1u;
        --shift;
        mantissa = mantissa & inverse_mask;
        inverse_mask >>= 1;
    }
    putchar('\n');
    printf("\tDecimal: %f\n", value);
    printf("------------------------\n");
}

//Union convertor for the float number, Used in the main function
typedef union convertor {
    float f;
    unsigned int u;
}
convertor;


//Main function of the code to take input and 
//run through functions above
int main(int argc, char * argv[]) {
    convertor input;
    printf("(Enter q to Quit Program)\n");
    printf("> ");
    while (scanf("%f", &input.f) != 0) {
        print_binary(input.u);
        print_sign(input.u);
        print_exponent(input.u);
        print_mantissa(input.u);
        printf("(Enter q to Quit Program)\n");
        printf("> ");
    }
    return 0;
}
