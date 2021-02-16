#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#define FALSE (0)
#define TRUE  (1)
#define ERROR (1)
#define SUCCESS (0)
#define USAGE "Usage: <temperature><scale>, where " \
                "<temperature> is a number and <scale> is either " \
                "C or F. \n"

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_integer(char * input) {
    if (*input == '+' || *input == '-') {
        input++;
    }
    while(is_digit(*input++));
    return ! *--input;
}

int is_floating_point_number(char * input) {
    if (*input == '+' || *input == '-') {
        input++;
    }
    int hit_point = FALSE;
    while (*input) {
        if (is_digit(*input)) {
            ++input;
        }
        else if (*input == '.' && !hit_point) {
            hit_point = TRUE;
            ++input;
        }
        else {
            return FALSE;
        }
    }
    return hit_point;
}

int validate_and_parse_input(char * input, double * temperature, char * scale) {
    char last_character = input[strlen(input) - 1];
    if (last_character == 'C' || last_character == 'F') {
        *scale = input[strlen(input) - 1];
    }
    else {
        return ERROR;
    }
    input[strlen(input) - 1] = '\0';
    if (is_floating_point_number(input) == TRUE) {
        *temperature = strtod(input, NULL);
        return SUCCESS;
    }
    else {
        if (is_digit(*input) == TRUE) {
        *temperature = (double)atoi(input);
        return SUCCESS;
        }
        else {
            return ERROR;
        }
    }

}

double celsius_to_fahrenheit(double celsius) {
    double fahrenheit = ((celsius * 9.0) / 5.0) + 32.0;
    return fahrenheit;
}

double fahrenheit_to_celsius(double fahrenheit) {
    double celsius = ((fahrenheit - 32) * (5/9));
    return celsius;
}

void print_output(double input_temperature, double converted_temperature, char scale) {
    if (scale == 'C') {
        printf("%0.2lf Degrees Celsius Coverted to Fahrenheit is %0.2lf Degrees\n", input_temperature, converted_temperature);
    }
    else if (scale == 'F') {
        printf("%0.2lf Degrees Fahrenheit Coverted to Celsius is %0.2lf Degrees\n", input_temperature, converted_temperature);
    }
    else {
        printf("Scale didn't represent one of the required values\n");
    }
}


void print_usage() {
    printf(USAGE);
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]) {
    double temperature;
    char scale;
    double converted_temp;
    int result;
    if (argc < 1) {
        print_usage();
    }
    else {
      result = validate_and_parse_input(argv[1], &temperature, &scale);
    }

    if (result == 1) {
        print_usage();
        printf("%c", scale);
    }
    else {
        if (scale == 'C') {
            converted_temp = celsius_to_fahrenheit(temperature);
        }
        else if (scale == 'F') {
            converted_temp = fahrenheit_to_celsius(temperature);
        }
        else {
            print_usage();
        }
    }

    print_output(temperature, converted_temp, scale);
    return 0;

    
}

