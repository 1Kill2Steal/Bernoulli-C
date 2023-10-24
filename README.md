Using the Bernoulli Distribution this terminal app works by passing
arguments for the total instance count, positive instances out of those
total ones, positive variants, total variants.

This is particularly useful for stuff like rolling 2 dices and wanting
to get a specific number for example:

$ bernoulli 6 1 1 6 

6 - possible outcomes (n)
1 - positive outcome (k)
1 - possible variant, 6 - total variants (p, in this case 1/6) | q = 1-p

Math formula:
P - probability.
P = C(k)(n) * p * q
