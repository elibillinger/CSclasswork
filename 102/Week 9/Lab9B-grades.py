# Eli Billinger
# CSCI 102 - Section C
# Week 9 - Part B
import csv
import sys
student_grades = []
grade = []
output_file = []
average = 0
max_num = 0
min_num = 100

file = input('Please enter the CSV file name with student grades:\nFILE> ')
student = input('Please enter the name of the student to calculate grades:\nSTUDENT> ')
check = 0
with open(file , 'r') as gradecsv:
    reader = csv.reader(gradecsv)
    student_grades = list(reader)
    

with open('output.txt', 'w') as output:
    for row in student_grades:
        if student not in row:
            check += 1
        for part in row:
            if part == student:
                print(part)
                output_file.append(part)
                continue
            elif part.isnumeric():
                grade.append(int(part))
            else:
                break
    if check >= len(student_grades):
        print('Student not found. No output file created\nOUTPUT error')
        sys.exit()
    for num in grade:
        average = (average + num)
        if num > max_num:
            max_num = num
        if num < min_num:
            min_num = num
    average = average/len(grade)
    output_file.append(str(int(average)))
    output_file.append(str(max_num))
    output_file.append(str(min_num))
    x = ', '
    output_str = x.join(output_file)
    output.write(output_str)

    print('The average grade for %s is: %d\nOUTPUT %s' % (student,average,average))
    print('The maximum grade for %s is: %d\nOUTPUT %s' % (student,max_num,max_num))
    print('The minimum grade for %s is: %d\nOUTPUT %s' % (student,min_num,min_num))

