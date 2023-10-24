Using the Bernoulli distribution this terminal app works by passing
arguments for the total instance count, positive instances out of those
total ones, positive variants, total variants.

This is particularly useful for stuff like rolling a die and wanting
to get a specific number for example:

$ bernoulli 1 1 1 6 

1 - amount of attempts (n)
1 - positive outcome (k)
1 - possible variant, 6 - total variants (p, in this case 1/6) | q = 1-p

Math formula:
P - probability.
P = C(k)(n) * p * q
