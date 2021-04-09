import random

num_calls = 0;
    
def quickselect(l, k) :

    #increment number of calls
    global num_calls
    num_calls += 1
    
    length = len(l)
    # Pick a random pivot element from the list, each
    # equally likely

    pivotA = random.choice(l)
    pivotB = random.choice(l)

    while (pivotA >= pivotB):
        pivotA = random.choice(l)
        pivotB = random.choice(l)

    l_small = []
    l_middle = []
    l_big = []

    
    # Put all elements smaller than pivotA into l_small, all elements larger
    # than pivotA and smaller than pivotB in l_middle, and all elements larger
    # than pivotB into l_big
    # A < B
    for i in l:
        if (i < pivotA):
            l_small.append(i)
        elif (i > pivotA and i < pivotB):
            l_middle.append(i)
        elif (i > pivotB):
            l_big.append(i)

    # We assume all elements are distinct, so (besides the two pivots) every element
    # should go into l_small, l_middle, or l_big
    assert(length == len(l_small) + len(l_middle) + len(l_big) + 2)

    # k is in small, middle, or big
    if (k <= len(l_big)):
        res = quickselect(l_big, k)
        return res

    # k is in middle or small
    else:
        k = k - len(l_big) - 1
        if (k == 0):
            if (pivotA < pivotB):
                return pivotB
            else:
                return pivotA
        elif (pivotA == pivotB):
            res = quickselect(l_small, k)
            return res
        elif (k <= len(l_middle)):
            res = quickselect(l_middle, k)
            return res

        # k is in small
        else:
            k = k - len(l_middle) - 1
            if (k == 0):
                if (pivotA < pivotB):
                    return pivotA
                else:
                    return pivotB
            elif (pivotA == pivotB):
                res = quickselect(l_small, k)
                return res
            else:
                res = quickselect(l_small, k)
                return res
    

def average(l):
    total = 0;
    for i in l:
        total = total + i
        
    average = total/len(l)
    return average

def MonteCarloSim():
    length = int(input("Enter Length of List "))
    key = int(input("Enter k for kth largest element "))
    count_list = []
    my_list = random.sample(range(length), length)

    # populate a list of the different number of recursive calls
    for i in range(0, 20000):
        global num_calls
        num_calls = 0
        quickselect(my_list, key)
        #print (num_calls)
        count_list.append(num_calls)

    print(average(count_list))  
        
MonteCarloSim()

