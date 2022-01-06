# Eli Billinger
# CSCI 102 - Section C
# Week 1 - Part C Body-Mass Index Calculator
print('Please enter your weight in pounds:')
Wlb = int(input('WEIGHT> '))
print('Please enter your heihgt in inches:')
Hin=int(input('HEIGHT> '))
m = Wlb * 0.454
h = Hin * 0.0254
BMI = m / (h**2)
print('Your Body-Mass Index is:')
print("OUTPUT", BMI)
