# Eli Billinger
# CSCI 102 - Section C
# Week 7 - Part C
s = input('Enter a DNA string:\nS>')
sc = list(s)
complement_lst = []

sc.reverse()

for i in sc:
    if i == 'A':
        complement_lst.append('T')
    elif i == 'T':
        complement_lst.append('A')
    elif i == 'G':
        complement_lst.append('C')
    elif i == 'C':
        complement_lst.append('G')

print('OUTPUT', ''.join(complement_lst))
