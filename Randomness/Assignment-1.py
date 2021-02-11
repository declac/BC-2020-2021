import random
import numpy

def most_probable(d, a, b) :
    number_a = 0
    number_b = 0

    lim = 100*(6** (d));

    for i in range (1, lim) :
        sum_roll = 0;

        for j in range(1, d +1) :
            sum_roll += numpy.random.randint(1,7)
            print(sum_roll)

        if (sum_roll == a) :
            number_a += 1
            print(number_a)
        if (sum_roll == b) :
            number_b += 1
            print(number_b)

    if (number_a == number_b) :
        print(a, "and", b, "are Equally Likely");
    elif (number_b > number_a) :
        print(b, "is more likley")
    else:
        print(a, "is more likely")

d = int(input("Enter the number of dice: "));
a = int(input("Enter a first sum: "))
b = int(input("Enter a second sum: "))
most_probable(d, a, b)