import random
import numpy
from decimal import *

def most_probable(d, a, b) :
    count_a = 0
    count_b = 0

    lim = 100*(6** (d))
    print('Rolling %d dice %d times' % (d, lim))

    for i in range (0, lim) :
        sum_roll = 0
        #print(i, "of ", lim)

        for j in range(1, d + 1) :
            roll = numpy.random.randint(1,7)
            #print("Die Roll = ", roll)
            sum_roll += roll
            #print("Sum of Rolls: ", sum_roll, "After ", j, "rolls")

        if (sum_roll == a) :
            #print("Sum Roll is input a")
            count_a += 1
            #print("Number of times sum = a is: ", count_a)
        if (sum_roll == b) :
            #print("Sum roll is input a")
            count_b += 1
            #print("Number of times sum = a is: ", count_b)
   

    def confidence_interval(a, b, runs) :
        z_score = 1.96
        probability_a = float(Decimal(a)/Decimal(runs))
        probability_b = float(Decimal(b)/Decimal(runs))
        standard_error_a = numpy.sqrt(probability_a * (1-probability_a) / runs)
        lca = probability_a - (z_score * standard_error_a)
        uca = probability_a + (z_score * standard_error_a)
        #print(lca, uca)
        if (probability_b >= lca and probability_b <= uca) :
            return 1
        else: 
            return 0

    if (confidence_interval(count_a, count_b, lim) == 1) :
        print("Number of %d's is %d and Number of %d's is %d" % (a, count_a, b, count_b))
        print("%d and %d are equally Likely!" % (a,b));
    elif (count_b > count_a) :
        print("Number of %d's is %d and Number of %d's is %d" % (a, count_a, b, count_b))
        print("%d is more likley." % (b))
    else:
        print("Number of %d's is %d and Number of %d's is %d" % (a, count_a, b, count_b))
        print("%d is more likely." % (a))

def main() :
    #d = int(input("Enter the number of dice: "));
    #a = int(input("Enter a first sum: "))
    #b = int(input("Enter a seccond sum: "))
    most_probable(1, 3, 4)

if (__name__ == "__main__") :
    main()
