# Eli Billinger
# CSCI 102 - Section C
# Week 6 - Part A


integer = int(input('Enter a positive integer to generate its Collatz Conjecture:\n INPUT>'))
collatz_output = []
seperator = ' '

collatz_output.append(integer)

while integer != 1:
    if integer % 2 != 0:
        integer = (3 * integer) + 1
        collatz_output.append(integer)
    else:
        integer = int(integer / 2)
        collatz_output.append(integer)
collatz_str = ' '.join(map(str, collatz_output))
print('OUTPUT ', collatz_str)
