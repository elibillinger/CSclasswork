# Eli Billinger
# CSCI 102 - Section C
# Week 5 - Part C

dna_string = input('Enter a DNA String (of length < 1000):\nSTRING> ')
num_A = 0
num_G = 0
num_C = 0
num_T = 0
i = 0
error = False
rna = []
seperator = ''

for dna in dna_string:
    if i > len(dna_string):
        break
    if dna_string[i] == 'A':
        num_A += 1
        rna.append('A')
    elif dna_string[i] == 'C':
        num_C += 1
        rna.append('C')
    elif dna_string[i] == 'G':
        num_G += 1
        rna.append('G')
    elif dna_string[i] == 'T':
        num_T += 1
        rna.append('U')
    else:
        error = True 
        break 
    i += 1
if error == True:
    print('OUTPUT DNA string not valid')
else:
    print('OUTPUT',num_A,num_C,num_G,num_T)
print('OUTPUT',seperator.join(rna))
