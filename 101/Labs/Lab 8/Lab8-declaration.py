# Eli Billinger
# CSCI 101 - Section G
# Python Lab 8
import random
import string

user_choice = input('Would you like to print the number of times a specific word appears OR print the number of words of a specific length? (1 or 2)\nCHOICE> ')
count = 0
word_of_length = []
with open('Declaration_of_independence.txt','r') as DoI:
    if user_choice == '1':
        user_word = input('Enter a word;\nWORD> ')
        for line in DoI:
            for part in line.split():
                if user_word in part:
                    count += 1
        print('The number of times %s appears in the document is: %d\nOUTPUT %s' % (user_word,count,count))
        
    elif user_choice == '2':
        length = int(input('Enter a length:\nLength> '))
        for line in DoI:
            for part in line.split():
                for char in part:
                     if char in set(string.punctuation):
                        part = part.replace(char,'')
                        
                if len(part) == length:
                    count += 1
                    word_of_length.append(part)
        
        if count == 0:
            print('The number of words in the document with length %d is: 0' % (length))
            print('No example random word of this length exists\nOUTPUT error')
            
        else:
            print('The number of words in the document with length %d is: %d\nOUTPUT %d' % (length,count,count))
            random_word = random.choice(word_of_length)
            print('One example random word of this length is: %s\nOUPUT %s' % (random_word,random_word))
        
DoI.close()
