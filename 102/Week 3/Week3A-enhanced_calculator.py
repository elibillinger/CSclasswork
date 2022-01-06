operand_one = 0.0
operand_two = 0.0
sum = 0.0
difference = 0.0
product = 0.0
quotient = 0.0
remainder = 0.0
user_choice = 0

operand_one = float(input('Input the first operand.\n FIRST>'))
operand_two = float(input('Input the second operand.\n SECOND>'))
user_choice = int(input('Choose one of the following operations:\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\nOPERATION>'))
if user_choice == 1:
    sum = operand_one + operand_two
    print('result: ',sum)
elif user_choice == 2:
    difference = operand_one - operand_two
    print('result: ',difference)
elif user_choice == 3:
    product = operand_one * operand_two
    print('result: ',product)
else:
    quotient = operand_one//operand_two
    remainder = operand_one % operand_two
    print('result: ',int(quotient),'\nremainder: ',int(remainder))
