# Eli Billinger
# CSCI 102 - Section C
# Week 7 - Part B
name_long = input('What are your author names?\nNAMES>')
name_short = []


for i in name_long:
    if i.isupper():
        name_short.append(i)
print('OUTPUT', '' .join(name_short))
