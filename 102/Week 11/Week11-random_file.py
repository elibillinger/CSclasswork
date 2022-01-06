# Eli Billinger
# CSCI 102 - Section C
# Week 11 - Part A
import string
import random

def clean_word(string1):
    for char in string1:
        if char in set(string.punctuation):
            string1 = string1.replace(char,'')
        string1 = string1.lower()
    return string1

def read_file(path):
    word_list = []
    with open(path,'r') as file:
        for line in file:
            for part in line.split():
                part = clean_word(part)
                word_list.append(part)
    return word_list

def write_file(list_words,path,num_words,seed):
    random.seed(seed)
    i=0
    with open(path,'w') as new_file:
        while i < num_words:
            word = random.choice(list_words)
            new_file.write(word)
            new_file.write(' ')
            i += 1
       
            
