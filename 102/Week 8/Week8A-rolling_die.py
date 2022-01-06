import random

user_wanted_rolls = int(input('Input the number of rolls to make:\nNUMBER>'))
num_rolls= [1]*user_wanted_rolls
rolled_6 = 0
rolled_5 = 0
rolled_4 = 0
rolled_3 = 0
rolled_2 = 0
rolled_1 = 0

print('Your %s rolls follow:' % (user_wanted_rolls))

for rolls in num_rolls:
    dice_roll = random.randint(1,7)
    if dice_roll == 6:
        rolled_6 += 1
    elif dice_roll == 5:
        rolled_5 += 1
    elif dice_roll == 4:
        rolled_4 += 1
    elif dice_roll == 3:
        rolled_3 += 1
    elif dice_roll == 2:
        rolled_2 += 1
    else:
        rolled_1 += 1
        
print('OUTPUT 1 occured %s times\nOUTPUT 2 occured %s times\nOUTPUT 3 occured %s times\nOUTPUT 4 occured %s times\nOUTPUT 5 occured %s times\nOUTPUT 6 occured %s times' % (rolled_1,rolled_2,rolled_3,rolled_4,rolled_5,rolled_6))
