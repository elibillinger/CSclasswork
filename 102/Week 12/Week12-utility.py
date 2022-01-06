# https://github.com/elibillinger/csci102-week12
# Eli Billinger
# CSCI 102 - Section C
# Week 12 - Part B


def PrintOutput(string):
    print('OUTPUT',string)
    
def LoadFile(filename):
    with open(filename, 'r') as file:
        line_list = file.read().splitlines()
    return line_list

def UpdateString(string1, string2, index):
    string = list(string1)
    for n,i in enumerate(string):
        if n == int(index):
            string[n] = string2
    new_string = ''.join(string)
    PrintOutput(new_string)

def FindWordCount(listt,word):
    count = 0
    for i in listt:
        sublist = i.split()
        for n in sublist:
            if n == word:
                count += 1
    return count

def ScoreFinder(player_names, player_scores, player_to_find):
    player_to_find.lower()
    in_list = False
    for n, i in enumerate(player_names):
        t = i.lower()
        if t == player_to_find:
            name = i
            place = n
            in_list = True
    if in_list:
        for n, i in enumerate(player_scores):
            if n == place:
                score = i
                PrintOutput('%s got a score of %d' % (name,score))
    else:
        PrintOutput('player not found')
        
def Union(list1, list2):
    for n, i in enumerate(list1):
        if i in list2:
            list1.pop(n)
    list1 += list2
    return list1

def Intersection(list1, list2):
    new_list = []
    for i in list1:
        if i in list2:
            new_list.append(i)
    return new_list
    
def NotIn(list1, list2):
    new_list = []
    for i in list1:
        if i not in list2:
            new_list.append(i)
    return new_list
    
            
    
