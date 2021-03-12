/*
 *
 * C program to convert a real value to IEEE 754 floating point representaion 
 * 
 * Author: Declan McGranahan
 */ 
  
#include <stdio.h> 
#include <math.h>
#include <stdlib.h> 

// Prints the binary representation 
// of a number n up to i-bits. 
void printBinary(int n, int i) 
{ 
    int k;
    for (k = i - 1; k >= 0; k--) { 
        if ((n >> k) & 1) 
            printf("1"); 
        else
            printf("0"); 
    } 
} 

unsigned long long remove_trailing_zeroes(unsigned long long v) {
    return v ? v / (-v & v) : v;
}




long decimalToBinary(int decimalnum)
{
    long binarynum = 0;
    int rem, temp = 1;

    while (decimalnum!=0)
    {
        rem = decimalnum%2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem*temp;
        temp = temp * 10;
    }
    return binarynum;
}

void print_mantissa(unsigned int mantissa) {
    unsigned shift = 22;
    unsigned int mask = 1 << shift;
    unsigned int inverse_mask = ~mask;
    float value = 1.0;
    float weight = 1.0;
    while(mantissa) {
        unsigned int result = (mantissa & mask) >> shift;
        putchar(result + '0');
        weight /= 2.0;
        value += result * weight;
        mask >>= 1;
        --shift;
        mantissa = mantissa & inverse_mask;
        inverse_mask >>= 1;
    }
    return value;

}
  
// Order is important. 
// Here the members of the union data structure 
// use the same memory (32 bits). 
// The ordering is taken 
// from the LSB to the MSB.
typedef union { 
    float f; 
    struct
    {  
        unsigned int mantissa : 23; 
        unsigned int exponent : 8; 
        unsigned int sign : 1; 
  
    } raw; 
} myfloat; 
  
// Function to convert real value 
// to IEEE foating point representation 
void printIEEE(myfloat var) 
{ 
    int *x;
    // Prints the IEEE 754 representation 
    // of a float value (32 bits) 
    printf("%d | ", var.raw.sign); 
    //printf("%d", var.raw.exponent);
    printBinary(var.raw.exponent, 8);
    printf(" | "); 
    printBinary(var.raw.mantissa, 23);
    printf("\n"); 
} 
  
// Driver Code 
int main() 
{ 
    // Instantiate the union 
    myfloat var; 
    // Get the real value 
    var.f = -4.5; 

    float initial = -4.5;
    // Get the IEEE floating point representation 
    printf("IEEE 754 representation of %f is : \n", 
           var.f); 
    printIEEE(var); 
    printf("%d", print_mantissa(-4.5));
    return 0; 
} 