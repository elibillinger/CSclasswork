user_string = input("Enter a string of X's and O's:\nMARBLES>")
found_marbles = []
i = 0


for marbles in user_string:
    
    if user_string[i] == 'O':
        found_marbles.append(i)
    i += 1

print('Your Marbles are at the following indices: \nOUTPUT ',found_marbles)    
