# 3sum
Algorithm to find 3 numbers in list that sum to a target. I.e. ai + aj + ak = c

Uses fact ai + aj = c - ak to reduce problem into n 2Sum iterations. Runs in O(n^2).

Note: Allows for repeated indices. To remove, set line 24 to L < R and ensure j and k are not i in two_sum.
