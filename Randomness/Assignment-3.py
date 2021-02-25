import random
from scipy.stats import binom 

trial = 0
success = 0


v = False

while v != True:
    if 0.05 > (1-binom.cdf(success, trial, 0.5)) > 0.03 and 0.05 > (binom.cdf(success-1, trial, 0.7)) > 0.03:
        v = True
        break
    else:
        trial = random.randint(1,200)
        success = random.randint(1, trial)

print(trial, success, 1-binom.cdf(success, trial, 0.5), binom.cdf(success-1, trial, 0.7))
