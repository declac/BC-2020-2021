# Declan McGranahan - April 28, 2020
# Programming Assignment 3
import random
import math
import scipy

# Function that when called runs the top down random shuffle 
# Takes one input: Input list
def top_to_random(l):
    top = l[0]; #Initiates the List of top
    index = random.randint(0, len(l) - 1); #Adds to the list some random int
    l.remove(top); #Pops off the top index
    l.insert(index, top); #Inserts to the list the random index created
    return l; #Returns the list

#Function that flips a coin
def cflip():
    return random.randint(0,1); #Rnadom number 0 or 1 representing heads or tails

# Function that does the GSR shuffle
# Takes one input: Input list
def gsr(l):
    length = len(l); # Creates a list for length

    c_list = []; # A list for coin flipping 
    for i in range(0, length): # For the length of the list we have flip a coin
        c_list.append(cflip());

    # Then we will split the list into two different groups
    # We store the number of heads in the heads_list
    # And the number of tails in the tails_list
    
    heads_list = [];
    tails_list = [];
    num_heads = 0;
    num_tails = 0;

    # Loops to do as described about
    for i in range(0, length):
        if (c_list[i] == 0):
            num_heads+=1;
        else:
            num_tails+=1;

    for i in range(0, num_heads):
        heads_list.append(l[0]);
        l.remove(l[0]);
    for i in range(0, num_tails):
        tails_list.append(l[0]);
        l.remove(l[0]);
        
    # We will then use the coin flip sequence we found above
    # To them determine what packet to pull each of our cards out of in the shuffled deck
    head_index = 0;
    tail_index = 0;
    
    # Loop to do as descirbed above while updating index's 
    for i in range(0, length):
        if (c_list[i] == 0):
            l.append(heads_list[head_index]);
            head_index+=1;
        else:
            l.append(tails_list[tail_index]);
            tail_index+=1;

    return l;

# A function that tests the order of the shuffle to determine probability
# Takes three inputs for the loop, Card 1 Card 2, new list
def test(i, j, l):
    for k in range (0, len(l)):
        if (l[k] == i):
            return 1
        elif (l[k] == j):
            return 0
        
# Funcion that is a monte loop
# This is the main function we will run for the shuffles
# Takes the input of type of shuffle
# Number of Shuffle's
# Card1 and Card 2 as well as number of trials
def monte_loop(l, type_shuffle, num_shuffles, card1, card2, num_trials):
    yes = 0; # Sets the variables we want to there necessary numbers
    prob = 0.0;

    # Top Down shuffle is number one in our input
    # If we have 1 then we will run this shuffle
    if (type_shuffle == 1): 
        for i in range(0, num_trials): # Runs the number of trials we have
            copy_l = l.copy()
            new_list = [];
            for j in range (0, num_shuffles): # Runs the shuffle the number of inputted times
                new_list = top_to_random(copy_l); # Runs the shuffle 
            if (test(card1, card2, new_list) == 1):
                yes += 1;
                
        prob = yes/num_trials; #Finds the probability and returns
        return prob;

    # GSR is number two in our input
    # If we have 2 then we will run this shuffle
    else:
        for i in range(0, num_trials): # Runs the number of trials we have
            copy_l = l.copy()
            new_list = [];
            for j in range (0, num_shuffles): # Runs the shuffle the number of inputted times
                new_list = gsr(copy_l); # Runs the shuffle 
            if (test(card1, card2, new_list) == 1):
                yes += 1;

        prob = yes/num_trials; #Finds the probability and returns
        return prob;

# Main function for running the shuffles as described in the quiz
# Generates lists based on inputs
# 1 is top 2 is gsr         
def main():
    l1 = [0, 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17]
    prob1 = monte_loop(l1, 1, 9, 1, 8, 30000);
    print(prob1)
    print(" ")
    
    l2 = [0, 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10, 11, 12]
    prob2 = monte_loop(l2, 1, 9, 1, 9, 30000)
    print(prob2)
    print(" ")

    l3 = [0, 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10,
          11, 12, 13, 14]
    prob3 = monte_loop(l3, 1, 9, 2, 8, 30000)
    print(prob3)
    print(" ")
    
    l4 = [0, 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19]
    prob4 = monte_loop(l4, 1, 7, 0, 3, 30000)
    print(prob4)
    print(" ")

    l5 = [0, 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10, 11, 12, 13, 14]
    prob5 = monte_loop(l5, 2, 4, 9, 11, 30000)
    print(prob5)
    print(" ")
    
    l6 = [0, 1, 2, 3, 4 ,5, 6, 7, 8, 9]
    prob5 = monte_loop(l5, 2, 4, 1, 3, 30000)
    print(prob5)
    print(" ")
main()
