import random
import numpy
from decimal import *

def most_probable(d, a, b) :
    number_a = 0
    number_b = 0

    lim = 100*(6** (d));
    print("Number of times rolling ", d, " dice is ", lim)

    for i in range (0, lim) :
        sum_roll = 0;
        #print(i, "of ", lim)

        for j in range(1, d + 1) :
            roll = numpy.random.randint(1,7)
            #print("Die Roll = ", roll)
            sum_roll += roll;
            #print("Sum of Rolls: ", sum_roll, "After ", j, "rolls")

        if (sum_roll == a) :
            #print("Sum Roll is input a")
            number_a += 1;
            #print("Number of times sum = a is: ", number_a)
        if (sum_roll == b) :
            #print("Sum roll is input a")
            number_b += 1;
            #print("Number of times sum = a is: ", number_b)
   

    p_a = float(Decimal(number_a)/Decimal(lim))
    p_b = float(Decimal(number_b)/Decimal(lim))
    print(p_a)
    print(p_b)
    z_score = 1.96
    se_a = numpy.sqrt(p_a * (1-p_a) / lim)
    lca = p_a - (z_score * se_a)
    uca = p_a + (z_score * se_a)
    print(lca, uca)

    if (p_b >= lca and p_b <= uca) :
        print(" Number of ", a, "s is: ", number_a, " and Number of ", b, "s is: ", number_b)
        print(a, "and", b, "are Equally Likely");
    elif (number_b > number_a) :
        print(" Number of ", a, "s is: ", number_a, " and Number of ", b, "s is: ", number_b)
        print(b, "is more likley")
    else:
        print(" Number of ", a, "s is: ", number_a, " and Number of ", b, "s is: ", number_b)
        print(a, "is more likely")

d = int(input("Enter the number of dice: "));
a = int(input("Enter a first sum: "))
b = int(input("Enter a seccond sum: "))
most_probable(d, a, b)