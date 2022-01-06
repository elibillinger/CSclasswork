# Eli Billinger
# CSCI 101 - Section G
# Python Lab 5A
number_grades = int(input('NUMBER> '))
grades = [] 
i = 0
while i < number_grades:
    grade = int(input('GRADE> '))
    grades.append(grade)
    i += 1


while i > 0:
    print('OUTPUT',grades[i-1])
    i -= 1
    
