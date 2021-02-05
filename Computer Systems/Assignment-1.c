#include <stdio.h>
#include <stdlib.h> 

double convert (double celsius) {
   double fahrenheit = ((celsius * 5) / 9) + 32;
   return fahrenheit;
}

int main(int argc, char **argv) {
    double celsius;
    double fahrenheit;
    if (argc < 2) {
        printf("Please Enter At Least a Single Temperature for Conversion\n");
        return 0;
    }
    else if (argc > 2) {
        printf("Please Enter Only a Single Temperature for Conversion\n");
        return 0;
    }
    else {
        celsius = strtod(argv[1], NULL);
        fahrenheit = convert(celsius);
        printf("%0.2lf Degrees Celsius Coverted to Fehrenheit is %0.2lf Degrees\n", celsius, fahrenheit);
    }
}