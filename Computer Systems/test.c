/*
 *
 * C program to convert a real value to IEEE 754 floating point representaion 
 * 
 * Author: Declan McGranahan
 */ 

#include <stdio.h> 
#include <math.h>
#include <stdlib.h> 
#include <string.h>
#define MAX_DEC_OUTPUT_SIZE 11
#define MAX_HEX_OUTPUT_SIZE 9
#define MAX_BIN_OUTPUT_SIZE 33

void print_binary(int num) {
    unsigned int mask = 1 << 31;
    while(mask) {
        if(num & mask) {
            printf("1");
        }
        else {
            printf("0");
        }
        mask >>= 1;
    }
    printf("\n");
}

/*
char print_decimal(int num) {
    char output [MAX_DEC_OUTPUT_SIZE];
    int i = MAX_DEC_OUTPUT_SIZE - 1;
    output[i] = '\0';
    --i;
    while(num) {
        output[i] = (num % 10) + '0';
        num /= 10;
        --i;
    }
    ++i;
    printf("Decimal: \n");
    printf("%s\n", output + i);
    return(output);
}
*/

void print_sign(int num) {
    unsigned int sign = num & 0x80000000;
    if(sign) {
        printf("Binary: %x\n", 1);
        printf("Decimal: %x\n", 1);
    }
    else {
        printf("Binary: %x\n", 0);
        printf("Decimal: %x\n", 0);
    }
}

int print_exponent(unsigned int exponent) {
    unsigned int shift = 23;
    unsigned int mask = 0xff << shift;
    exponent = (exponent & mask);
    exponent >>= shift;
    shift = 7;
    mask = 1 << shift;
    unsigned int result;
    unsigned int test;
    while(mask) {
        result = (exponent & mask) >> shift;
        putchar(result + '0');
        mask >>= 1;
        --shift;
    }
    printf("\n");
    return result;
}

int print_mantissa(unsigned int mantissa) {
    unsigned shift = 22;
    unsigned int mask = 1 << shift;
    unsigned int inverse_mask = ~mask;
    float value = 1.0;
    float weight = 0.5;
    while(mantissa) {
        unsigned int result = (mantissa & mask) >> shift;
        putchar(result + '0');
        value += result * weight;
        mantissa = mantissa & inverse_mask;
        mask >>= 1;
        inverse_mask >>= 1;
        --shift;
        weight /= 2.0;
    }
    printf("\n");
    printf("Decimal: %f\n", value);
    return value;

}

typedef union convertor {
    float f;
    unsigned int u;
}
convertor;

int main() {
    convertor input;
    float f; 
    printf("> ");
    scanf("%f", &input.f);
    unsigned int shift = 31;
    unsigned int mask = 1 << shift;
    while(mask) {
        putchar((((input.u & mask) >> shift)) + '0');
        mask >>= 1;
        --shift;
    }
    printf("Binary Representation: \n");
    print_binary(input.u);
    printf("Sign: \n");
    print_sign(input.u);
    printf("Exponent: \n");
    print_exponent(input.u);
    printf("Mantissa: \n");
    print_mantissa(input.u);

}
