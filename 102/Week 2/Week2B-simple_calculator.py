# Eli Billinger
# CSCI 102 - Section C
# Week 2 - Part B

operand_one = 0.0
operand_two = 0.0
sum = 0.0
difference = 0.0
product = 0.0
quotient = 0.0
remainder = 0.0

operand_one = int(input("Input the first operand. \n FIRST>"))
operand_two = int(input("Input the second operand. \n SECOUND>"))

sum = operand_one + operand_two
difference = operand_one - operand_two
product = operand_one*operand_two
quotient = int(operand_one/operand_two)
remainder = operand_one % operand_two


print('The sum of ' + str(operand_one) + ' and ' +str(operand_one)+ ' is: ' + str(sum))
print('The difference of ' + str(operand_one) + ' and ' +str(operand_two)+ ' is: ' + str(difference))
print('The product of ' + str(operand_one) + ' and ' +str(operand_two)+ ' is: ' + str(product))
print('The quotient of ' + str(operand_one) + ' and ' +str(operand_two)+ ' is: ' + str(quotient))
print('The remainder of ' + str(operand_one) + ' and ' +str(operand_two)+ ' is: ' + str(remainder))
