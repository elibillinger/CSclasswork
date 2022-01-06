# Eli Billinger
# CSCI 101 - Section G
# Python Lab 9

def Multiply(num1,num2,product):
    mult = num1 * num2
    if mult == product:
        return True
    else:
        return False
    
def BoundsChecking(lower_bound,upper_bound,list_length):
    if lower_bound < 0:
        return False
    if upper_bound > list_length:
        return False
    if upper_bound < lower_bound:
        return False
    else:
        return True
        
def DecimalPoints(number):
    number = str(number)
    split_string = number.split('.')
    if len(split_string[1]) == 3:
        return True
    else:
        return False
def ListSorted(test_list):
    test_list1 = test_list[:]
    test_list1.sort()
    if test_list == test_list1:
        return True
    else:
        return False
def ReversedList(list1,list2):
    list1.reverse()
    if list1 == list2:
        return True
    else:
        return False
def NumZeros(num_o,xo_list):
    num_of_o = 0
    for row in xo_list:
        for i in row:
            if i == 'o' or i == 'O':
                num_of_o += 1
    if num_of_o == num_o:
        return True
    else:
        return False
    
def CheckCS(word):
    c = False
    for i in word:
        if i == 'c':
            c = True
        if c == True and i == 's':
            return True
    return False
                
