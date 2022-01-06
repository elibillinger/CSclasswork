import random

def break_list_of_rolls(list_rolls):
    i = 0
    while i < len(list_rolls):
        print('OUTPUT %d occurred %d times' % (i+1,list_rolls[i]))
        i += 1
    

def generate_rolls(num_roll):
    roll_6 = 0
    roll_5 = 0
    roll_4 = 0
    roll_3 = 0
    roll_2 = 0
    roll_1 = 0
    for roll in range(0,num_roll):
        dice_roll = random.randint(1,6)
        if dice_roll == 6:
            roll_6 += 1
        elif dice_roll == 5:
            roll_5 += 1
        elif dice_roll == 4:
            roll_4 += 1
        elif dice_roll == 3:
            roll_3 += 1
        elif dice_roll == 2:
            roll_2 += 1
        elif dice_roll == 1:
            roll_1 += 1
    rolls.append(roll_1)
    rolls.append(roll_2)
    rolls.append(roll_3)
    rolls.append(roll_4)
    rolls.append(roll_5)
    rolls.append(roll_6)
    return(rolls)

num_rolls = int(input('Input the number of rolls to make:\nNUMBER>'))
rolls = []

print('Your %d rolls follow:' % (num_rolls))
break_list_of_rolls(generate_rolls(num_rolls))
