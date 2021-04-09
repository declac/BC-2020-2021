# Declan McGranahan- Apr 9, 2021
# Programming Assignment # 2
# Quick Select with Double Pivot

import random # Imports Random

# Main quickselect function
def quickselect(l, k):
    length = len(l)

    #If both length and k are both 1 then return pivotA list w
    # ith 0 and set num_calls to 1
    if (length == 1 and k == 1):
        return l[0], 1

    # Picks a random pivot element from the list called in the function, with each being equally likely
    pivotA = random.choice(l)
    pivotB = random.choice(l)

    # While pivotA is bigger than pivotB we want to find new pivots
    while (pivotA >= pivotB):
        pivotA = random.choice(l)
        pivotB = random.choice(l)

    # Defines the three lists to append to 
    l_small = []
    l_middle = []
    l_big = []

    # Put all elements smaller than pivotA into l_small, all elements larger
    # than pivotA and smaller than pivotB in l_middle, and all elements larger
    # than pivotB into l_big
    for i in l:
        if (i < pivotA):
            l_small.append(i)
        elif (i > pivotA and i < pivotB):
            l_middle.append(i)
        elif (i > pivotB):
            l_big.append(i)
    
    # Put all elements smaller than pivot into l_small, 
    # all larger elements into l_big, and all else in l_middle
    assert(length == len(l_small) + len(l_middle) + len(l_big) + 2)

    # k is in big
    # Increments number of calls in return function as well
    if (k <= len(l_big)):
        res, num_calls = quickselect(l_big, k)
        return res, num_calls + 1

    # k is in middle or small
    # Increments number of calls in return function as well
    else:
        k = k - len(l_big) - 1
        if (k == 0):
            if (pivotA < pivotB):
                return pivotB, 1
            else:
                return pivotA, 1
        elif (pivotA == pivotB):
            res, num_calls  = quickselect(l_small, k)
            return res, num_calls + 1
        elif (k <= len(l_middle)):
            res, num_calls = quickselect(l_middle, k)
            return res, num_calls + 1

        # k is in small
        # Increments number of calls in return function as well
        else:
            k = k - len(l_middle) - 1
            if (k == 0):
                if (pivotA < pivotB):
                    return pivotA, 1
                else:
                    return pivotB, 1
            elif (pivotA == pivotB):
                res, num_calls = quickselect(l_small, k)
                return res, num_calls + 1
            else:
                res, num_calls = quickselect(l_small, k)
                return res, num_calls + 1

# Function that runs the Monte Carlo Simulation
def MonteCarloSim():
    l = [] # Create list that will be used for simulation

    # Get User input for size and k
    length = int(input("Enter Length of List: "))
    k = int(input("Enter K for kth element: "))

    # Creates the size of the list according to user input
    for i in range(length):
        l.append(i)

    avgcalls = 0

    # Populates a list of the different number of recursive calls
    for i in range(20000):
        res, num_calls = quickselect(l, k) # Sets the value and num of calls
        avgcalls += num_calls # Makes average calls the same as number of calls

    avgcalls /= 20000 # Gets the average calls by dividing by 20000
    print("The kth largest element is: %2d" % (res))
    print("Average quickselect calls required =%5.2f" % (avgcalls))

MonteCarloSim()




