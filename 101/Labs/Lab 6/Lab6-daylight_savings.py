# Eli Billinger
# CSCI 101 - Section G
# Python Lab 6
num_cases = int(input('Enter number of test cases\nN>'))
                
user_input = ''
min_change = 0
new_hour = 0
new_min = 0
i = 0


while i < num_cases:
    user_input = input('INPUT>')
    user_input = list(user_input.split(" "))
    i += 1
    if user_input[0] == 'B' and user_input[2] == '0':
        user_input.pop(2)
        user_input.insert(2, '24')
    current_min = (int(user_input[2]) * 60) + (int(user_input[3]))
    if user_input[0] == 'B': 
        min_change = current_min - int(user_input[1])
    elif user_input[0] == 'F':
        min_change = current_min + int(user_input[1])
    new_min = min_change % 60
    new_hour = int(min_change / 60)
    if new_hour == 24 and user_input[0] == 'F':
        new_hour = 0
        
    print('OUTPUT ', new_hour, new_min)
