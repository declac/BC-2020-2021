import random #Import the necessary libraries to run the program
import numpy
from decimal import *

def most_probable(d, a, b) : #Function that takes the number of die to roll and two sums and simulates rolling
    count_a = 0 # Counts of how many times the rolls equal the inputed sums 
    count_b = 0

    lim = 1000*(6** (d)) #Number of rolls to execute is is 6^die * 1000 
    print('Rolling %d dice %d times' % (d, lim))

    for i in range (0, lim) : #For the number of rolls within our roll limit we will roll d die
        sum_roll = 0 #For each new roll of d die resent sum of the roll to 0

        for j in range(1, d + 1) : #for each die in each roll we will set a random number and add them together
            roll = numpy.random.randint(1,7) #For each die assigns a number 1-6 randomly
            sum_roll += roll #adds all the rolls together to get a sum for d die

        if (sum_roll == a) : #If the sum is equal to either of the inputed sums up the counter
            count_a += 1
        if (sum_roll == b) :
            count_b += 1
   

    def confidence_interval(a, b, runs) : #Inner function to determine the 95% confidence interval
        z_score = 1.96 #Set the z-score to 1.96 for 95% CI
        probability_a = float(Decimal(a)/Decimal(runs)) #Find the probability of rolling sum A
        probability_b = float(Decimal(b)/Decimal(runs)) #Find the probability of rolling sum B
        standard_error_a = numpy.sqrt(probability_a * (1-probability_a) / runs) #Find the standard error of sum a
        lca = probability_a - (z_score * standard_error_a) #Find the lower confidence interval of sum a
        uca = probability_a + (z_score * standard_error_a) #Find the upper bound for the confidence interval of sum a
        if (probability_b >= lca and probability_b <= uca) : #If the probability of b falls within a's confidence interval then we know they are equally likley
            return 1 #if yes return 1 
        else: 
            return 0 #Otherwiuse return 0

    if (confidence_interval(count_a, count_b, lim) == 1) : #If the function returns 1 then we know they are equally likely 
        print("The number of %d's rolled is %d and the number of %d's rolled is %d" % (a, count_a, b, count_b))
        return("Final Answer: %d and %d are equally likely!" % (a,b)) #Return the final result to people
    elif (count_b > count_a) : #If it does not fall in the confidence interval then check to see if number of b rolls is greater than a 
        print("The number of %d's rolled is %d and the number of %d's rolled is %d" % (a, count_a, b, count_b))
        return("Final Answer: %d is more likely." % (b)) #if this is the case then we know that sum b is more likely 
    else: #Otherwise the sum of a is more likely
        print("The number of %d's rolled is %d and the number of %d's rolled is %d" % (a, count_a, b, count_b))
        return("Final Answer: %d is more likely." % (a))

def main() : #Defines a main functions that takes in the arguments from the user in teh command line and runs the probability function
    die = int(input("Enter the number of dice: "));
    sum_a = int(input("Enter a first sum: "))
    sum_b = int(input("Enter a second sum: "))
    print(most_probable(die, sum_a, sum_b)) #Inputs the inouts intot he function and runs it

if (__name__ == "__main__") : #Runs the main function
    main()
