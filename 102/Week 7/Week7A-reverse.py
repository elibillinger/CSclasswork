import copy
list_size = int(input('What size 2D list would you like to create?\nN> '))
my_list = []

# create 2-D list in N X N structure
c = 1
print('\nThe original list is:')
for i in range(list_size):
    row = []
    for i in range(list_size):
        row.append(c)
        c += 1
    my_list.append(row)
print('\n'.join([str(lst) for lst in my_list]))

#reverse using .reverse() function
reversed_v1 = copy.deepcopy(my_list)
print('\nThe reversed list is:')
reversed_v1.reverse()
for row in reversed_v1:
    row.reverse()
print('\n'.join([str(lst) for lst in reversed_v1]))

#reverse not using .reverse() function
reversed_v2 = []
print('\nThe reversed list is:')
for row in my_list:
    row2= []
    for element in row:
        row2.insert(0,element)
    reversed_v2.insert(0, row2)
print('\n'.join([str(lst) for lst in reversed_v2]))
