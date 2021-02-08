#include <stdio.h> 
#include <stdlib.h> 

double convert (double celsius) { //Convert Function that takes a celcius input and converts it to fahrenheit
   double fahrenheit = ((celsius * 9) / 5) + 32;
   return fahrenheit; //Returns the fahrenheit number
}

int main(int argc, char **argv) { //Main cunction that takes on command line input and returns a conversion
    double celsius; //Defining the variables for the temperatures
    double fahrenheit;
    if (argc < 2) { //Checks that there is at least one command line argument including the name of the file
        printf("Please Enter At Least a Single Temperature for Conversion\n"); //IF this is not the case prints a frindly help message 
        return 0; //And returns 0
    }
    else if (argc > 2) { //Checks that there are no more than one command line argument including the name of the file
        printf("Please Enter Only a Single Temperature for Conversion\n"); //IF this is not the case prints a frindly help message 
        return 0; //And returns 0
    }
    else { //If there is only the proper amount of command line arguments the program converts 
        celsius = strtod(argv[1], NULL); //Grabs the number in the command line and assigns it to the celsius variable 
        fahrenheit = convert(celsius); //Runs the convert function defined above and assignns the result to the fahrenheit variable
        printf("%0.2lf Degrees Celsius Coverted to Fehrenheit is %0.2lf Degrees\n", celsius, fahrenheit); //Prints out the Originally entered number allong with the new converted number
    }
}