# Eli Billinger
# CSCI 102 - Section C
# Week 4 - Part C

import random
my_seed = int(input("Number to initialize the random generator: ")) 
random.seed( my_seed ) 
random_num = random.randint(1,100)

user_num_guess = int(input('Guess a number between 1 and 100: '))

while user_num_guess != random_num:
    
    if user_num_guess > 100:
        print('OUTPUT Please enter a number between 1 and 100')
    if user_num_guess < 1:
        print('OUTPUT Please enter a number between 1 and 100')
    if abs(user_num_guess - random_num) >= 50:
        print("OUTPUT You're cold!\n")
    if 25 <= abs(user_num_guess - random_num) < 50:
        print("OUTPUT You're lukewarm!\n")
    if 15 <= abs(user_num_guess - random_num) < 25:
        print("OUTPUT You're getting warm!\n")
    if 5 <= abs(user_num_guess - random_num) < 15:
        print("OUTPUT You're getting hot!\n")
    if 0 < abs(user_num_guess - random_num) < 5:
        print("OUTPUT You're geeting so close!\n")
    user_num_guess = int(input('Guess a number between 1 and 100: '))   
print('OUTPUT Congrats! You Won!')
