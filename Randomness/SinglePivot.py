# Declan McGranahan- Apr 9, 2021
# Programming Assignment # 2
# Quick Select with Single Pivot

import random # Imports Random

num_calls = 0 # Defines number of calls to be 0 

# Main quickselect function
def quickselect(l, k):

    # Increments the number of calls each run and stores it globally
    global num_calls
    num_calls += 1
    
    length = len(l)

    # Picks a random pivot element from the list called in the function, with each being equally likely
    pivot_i = random.randint(0, length - 1)
    pivot = l[pivot_i]

    # Defines the two lists to append to 
    l_small = []
    l_big = []
    
    # Put all elements smaller than pivot into l_small and all larger elements into l_big
    for i in l:
        if (i < pivot):
            l_small.append(i)
        elif (i > pivot):
            l_big.append(i)

    # We assume all elements are distinct, so check that every element goes into l_small or l_big
    assert(length == len(l_small) + len(l_big) + 1)
    
    # Runs the recursion while looking for k
    if k <= len(l_big):
        # kth largest is in l_big
        res = quickselect(l_big, k)
        return res
    elif k > len(l_big) + 1:
        # kth largest is in l_small
        res = quickselect(l_small, k - len(l_big) - 1)
        return res
    else:
        return pivot


# Function to fins the average of the number of calls
def average(l):
    total = 0
    for i in l:
        total = total + i
    average = total/len(l)
    return average


# Function that runs the Monte Carlo Simulation
def MonteCarloSim():
    # Gets inputs from the users and sets them to defined variables
    length = int(input("Enter Length of List: "))
    k = int(input("Enter K for kth element: "))
    count_list = [] # Creates a list to hold count information 
    my_list = random.sample(range(length), length)  # Creates the size of the list according to user input

    # Populates a list of the different number of recursive calls
    for i in range(0, 20000):
        global num_calls
        num_calls = 0
        res = quickselect(my_list, k)
        count_list.append(num_calls)
    print("The kth largest element is: %2d" % (res))
    print("Average quickselect calls required =%5.2f" % average(count_list)) 
        
MonteCarloSim()
