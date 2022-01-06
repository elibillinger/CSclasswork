# Eli Billinger
# CSCI 101 - Section G
# Python Lab 7
import string
import random
import sys
choice = int(input('Would you like to check your password or a random one? (1 or 2)\nCHOICE> '))
score = 0
strength = ''
#Determine choice, check if valid for choice 1, generate for choice 2
if choice == 1:
    password = input('Enter a password to validate:\nPASSWORD> ')
    print('Validating the password %s' % (password))

    if len(password) < 8:
           print('The password %s is an invalid password' % (password)) 
           print('Password must be 8 characters long\nOUTPUT INVALID')
           sys.exit()
    elif not any(char.isdigit() for char in password):
           print('The password %s is an invalid password' % (password))
           print('Password must contain at least one number\nOUTPUT INVALID')
           sys.exit()
    elif not any(char in string.punctuation for char in password):
            print('The password %s is an invalid password' % (password))
            print('Password must contain at least one special character\nOUTPUT INVALID')
            sys.exit()
elif choice == 2:
    seed = int(input('Number it initialize the random generator:\nSEED> '))
    random.seed(seed)
    random_letters = [random.choice(string.ascii_letters) for x in range(8)]
    random_num = [random.choice(string.digits) for x in range(2)]
    random_special = [random.choice(string.punctuation) for x in range(2)]
    password = ''.join(random_letters + random_num + random_special)
    print('Validating the password')
# Determine Score
vowels = ['a','e','i','o','u','A','E','I','O','U']
uppercase = 0
lowercase = 0
for i in password:
    if i in string.ascii_letters:
        score += 4
    if i  in string.digits:
        score += 5
    if i in string.punctuation:
        score += 6
    if i in vowels:
        score -= 3
    if i in string.ascii_lowercase:
        lowercase += 1
    if i in string.ascii_uppercase:
        uppercase += 1
x = uppercase-lowercase
score += x*2
#Determine strength based on score
if score < 20:
    strength = 'Weak+'
elif 20 <= score < 40:
    strength = 'Weak'
elif 40 <= score < 60:
    strength = 'Good'
elif 60 <= score < 80:
    strength = 'Strong'
elif 80 <= score:
    strength = 'Strong+'

print('The password %s is a %s password\nOUTPUT %s' % (password,strength,strength))
