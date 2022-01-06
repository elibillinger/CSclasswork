number_of_tasks = 0
tasks = [input('Enter the tasks you need to do. When you are done enter DONE\nTask>')]
lots_to_do = 7
not_much_to_do = 4
i=0


while tasks[i] != 'DONE':
    tasks.append(input('TASK>'))
    i+=1
    
if i > lots_to_do:
    print('You have %d tasks to do. You have a lot to do! You better get to work!' % (i))
    print('OUTPUT> %d\nOUTPUT> BUSY' % (i))
elif i < not_much_to_do:
    print("You have %d tasks to do. You don't have much to do, enjoy a break!" % (i))
    print('OUTPUT> %d\nOUTPUT> FREE' % (i))
elif not_much_to_do <= i <= lots_to_do:
    print('You have %d tasks to do. You have some work you need to do. Better to get it over with' % (i))
    print('OUTPUT> %d\nOUTPUT> MODERATELY' % (i))
