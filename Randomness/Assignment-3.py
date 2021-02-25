import random
from scipy.stats import binom 

trial = 0
success = 0

v = False

while v != True:
    if 0.05 > binom.pmf(success, trial, 0.5) > 0.03 and 0.05 > (binom.pmf(success-1, trial, 0.7)) > 0.03:
        v = True
        break
    else:
        trial = random.randint(1,200)
        success = random.randint(1, trial)

print(trial, success, binom.pmf(success, trial, 0.5), binom.pmf(success-1, trial, 0.5))
