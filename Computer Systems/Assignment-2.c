/*
 * Author: Declan McGranahan - mcgranad@bc.edu
*/
#define ERROR (1) //Defines Error to be set to 1
#define FALSE (0) //Defines False to be set to 0
#define TRUE  (1) //Defines True to be set to 1
#define SUCCESS (0) //Defines Success to be set to 0
#define USAGE "Usage: <temperature><scale>, where " \
                "<temperature> is a number and <scale> is either " \
                "C or F. \n" //Creates a standard error message to produce when there is a problem
#include <stdio.h> //Imports required for functions to run
#include <stdlib.h> 
#include <string.h>
/*
 * is_digit function checks to see if the inputted character is digit between 0 and 9. 
 * Returns true if it is and false if it is not.
 */ 
int is_digit(char c) {
    return c >= '0' && c <= '9';
}
/*
 * is_integer function checks if the inputted string is a integer.
 * It does this by checking is there is starting positive of negative and-
 * then going to the next character. 
 * It then calls the is_digit function to see if the character is a digit between 0 and 9.
 * If it is it returns true and moves on to the next character. Otherwise it returns false.
 */ 
int is_integer(char * input) {
    if (*input == '+' || *input == '-') {
        input++;
    }
    while(is_digit(*input++));
    return ! *--input;
}
/*
 * The is_floating_point_number function checks to see if the inputted string-
 * is a floating point number.
 * It does this by checking to see if there is digits by calling the is_digit function.
 * It then checks to see if there is a period in the number which would represent a change-
 * to a floating point number.
 * If there is it then returns true and if not then returns false. 
 */
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
/*
 * Checks that the lsat character in the input is one of the allowed characters. 
 * If it is not it will return and error, if it is stores in the inputted scale variable. 
 * Then takes the last character out and replaces it with a null value. 
 * Then checks to see if the remaning string is a floating point number. 
 * If it is then it parses it to a double and stores it in the inputted temp variable. 
 * Otherwise it checks to see if it is an integer value and does the same as above. 
 * If it is neither it will return and error and terminate.
 */ 
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
/* This is a function that takes a single input and converts it to a different number. 
 * Takes the inputted celsius and uses the conversion formula defined to return fahrenheit. 
 */
double celsius_to_fahrenheit(double celsius) {
    double fahrenheit = ((celsius * 9.0) / 5.0) + 32.0;
    return fahrenheit;
}
/* This is a function that takes a single input and converts it to a different number. 
 * Takes the inputted fahrenheit and uses the conversion formula defined to return celsius. 
 */
double fahrenheit_to_celsius(double fahrenheit) {
    double celsius = ((fahrenheit - 32) * (5/9));
    return celsius;
}
/* This function checks to see what value scale is associated with.
 * If it is a C then it will print celsius first and fahrenheit second. 
 * If it is an F it will do the opposite. 
 * If the scale values is not one that is expected it will print and error message.
 */
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
/* print_usage is function that is called when there is an error in the program. 
 * It prints a defined message from the top of the program. 
 * And then terminates the program after printing the message.
 */
void print_usage() {
    printf(USAGE);
    exit(EXIT_FAILURE);
}
/* The main function checks for the appropriate number of inputs. 
 * If there are ot it terminates the pogram by calling print_usage. 
 * If there are then it runs the validate function to return the inputted info. 
 * This info is stored in scale and temperature. 
 * If the validate function returns a 1 there was an error and the program calls print_usage.
 * Otherwise the scale value is found and used to call the proper conversion function. 
 * The converted number is stored in a new variable and printed using the print_output function.
 * Finally the program returns 0 and terminates. 
 */
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

