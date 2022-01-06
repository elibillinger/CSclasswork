users_number = 0.0

users_number = int(input('Input a positive number for the siblings to consider:\nNUMBER>'))

print('The sibling(s) who will work with %d follow:' % (users_number))
if not users_number % 2 == 0:
    print('OUTPUT> Jimmy')
if 100 >= users_number >= 10:
    print('OUTPUT> Jared')
if (100 > users_number >= 10) and ((int(users_number/10)+(users_number % 10)) == 8):
    print('OUTPUT> Josephine')
