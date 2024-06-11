# Big Integer Addition
***Start:** March 30<sup>th</sup> 2023, **Finish:** April 2<sup>nd</sup> 2023*

For a second-year course: Algorithms & Data Structures

This program adds two positive big integers in decimal format. Here *big integer* means integers that can be much larger than the biggest integer datatype in C++.

## Procedure
1) Load individual digits of two input numbers in two stack.
2) a. Carry out integer addition, adding each digit in the same place-number together and storing the resultant place-number in a new stack.
b. If the resulting number from this mini-addition is greater than 10, the carryover (`result/10`) is taken away from the result and is stored for the next mini-addition.
3) If there is one number that hasn't been fully read, the leftover is added to the stack, considering the carryover from 2b.
4) If there is still carryover stored, this is added to the stack.


## What I learnt:
- Using stacks to calculate carry-over integer addition.
