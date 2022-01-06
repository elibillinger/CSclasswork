# Eli Billinger
# CSCI 102- Section C
# Week 8 - Part C
import random
import string

choice = int(input('Would you like to provide your own string or generate a random one? (1 or 2)\nCHOICE> '))
kevin_points = 0
stacy_points = 0
#Determine Choice and generate random string for choice 2
if choice == 1:
    string = input('Enter a string for the game:\nSTRING> ')
elif choice == 2:
    seed = int(input('Number to initialize the random generator:\nSEED> '))
    random.seed(seed)
    string = [random.choice(string.ascii_uppercase) for x in range(6)]
    string = ''.join(string)
    print('The randomly generated string for this game is %s:' % (string))

# Get all substrings
c = 0
substrings=[]
while True:
    for i in range(len(string)):
        if string[i:i+c] in substrings:
            continue
        else:
            substrings.append(string[i:i+c])
    if c == len(string):
        break
    c += 1

#Figure out Points
for i in substrings:
    if i == '':
        continue
    if i.startswith('A') or i.startswith('E') or i.startswith('I') or i.startswith('O') or i.startswith('U'):
        kevin_points = kevin_points + string.count(i)
    else:
        stacy_points = stacy_points + string.count(i)
    
print("With the string %s, Kevin's score is %d and Stacy's score is %d" % (string,kevin_points,stacy_points))
#Determine Winner
win_status = 0
if kevin_points > stacy_points:
    print('Kevin wins!')
    win_status = 'Kevin'
elif stacy_points > kevin_points:
    print('Stacy wins!')
    win_status = 'Stacy'
else:
    print("It's a tie!")
    win_status = 'Draw'

print('OUTPUT ',kevin_points)
print('OUTPUT ',stacy_points)
print('OUTPUT ',win_status)
