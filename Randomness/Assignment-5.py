import random #Import Necessary Libaries

"""
Runs a single trial of the Attacker problem. Does it with or without switching 
after the attacker reveals nothing behind one of the unchosen cats.
"""
def run_initial_trial(switch_cats, cats):
    # Pick a random cat out of the cats available
    chosen_cat = random.randint(1, cats)
    if switch_cats:
        # Reveals nothing behind the cat
        revealed_cat = 3 if chosen_cat==2 else 2
        # Make the switch by choosing any other cat than the oringal
        available_cats = [num for num in range(1,cats+1) if num not in (chosen_cat, revealed_cat)]
        chosen_cat = random.choice(available_cats)
    # You win if you picked cat number 1
    return chosen_cat == 1

"""
Run many different trial iterations of the Attacker problem based on user input trials
Uses switching or no switching by defining switch_cats as true or false.
"""
def run_trials(trials, switch_cats, cats):
    wins = 0 # Sets original wins to 0
    for i in range(trials):
        if run_initial_trial(switch_cats, cats): #If we win the initial trial run we get a win
            wins += 1
    return wins


"""
Gathers inputs from the user for the number of trials to run the
"""
trials = int(input("Enter the number of trials to run: "))
"""

Runs number of inputted trials with switching. 
Then runs number of inputted trials without switching.
"""
wins_without_switch = run_trials(trials, False, cats=3)
wins_with_switch = run_trials(trials, True, cats=3)

"""
Prints out the number of won trials and the probability/proportions of winning
Based on if the player choose to switch or not the
"""
print('Attacker Problem with {} cats'.format(3))
print('Number of wins without switching: {}'.format(wins_without_switch))
print('Proportion of wins without switching: {:.4f}'.format(wins_without_switch/trials))
print('Number of wins with switching: {}'.format(wins_with_switch))
print('Proportion of wins with switching: {:.4f}'.format(wins_with_switch/trials))




