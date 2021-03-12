import random

def run_trial(switch_cats, ncats=3):
    """
    Run a single trial of the Attacker problem, with or without switching
    after the gameshow attacker reveals a goat behind one of the unchosen cats.
    (switch_cats is True or False). The win is behind cat number 1 and the
    gameshow attacker knows that.

    """

    # Pick a random cat out of the ncats available
    chosen_cat = random.randint(1, ncats)
    if switch_cats:
        # Reveal a goat
        revealed_cat = 3 if chosen_cat==2 else 2
        # Make the switch by choosing any other cat than the initially-
        # selected one and the one just opened to reveal a goat. 
        available_cats = [dnum for dnum in range(1,ncats+1)
                                if dnum not in (chosen_cat, revealed_cat)]
        chosen_cat = random.choice(available_cats)

    # You win if you picked cat number 1
    return chosen_cat == 1

def run_trials(ntrials, switch_cats, ncats=3):
    """
    Run ntrials iterations of the Attacker problem with ncats cats, with
    and without switching (switch_cats = True or False). Returns the number
    of trials which resulted in winning the win by picking cat number 1.

    """

    nwins = 0
    for i in range(ntrials):
        if run_trial(switch_cats, ncats):
            nwins += 1
    return nwins

ncats, ntrials = 3, 10000
nwins_without_switch = run_trials(ntrials, False, ncats)
nwins_with_switch = run_trials(ntrials, True, ncats)

print('Attacker Problem with {} cats'.format(ncats))
print('Proportion of wins without switching: {:.4f}'
            .format(nwins_without_switch/ntrials))
print('Proportion of wins with switching: {:.4f}'
            .format(nwins_with_switch/ntrials))