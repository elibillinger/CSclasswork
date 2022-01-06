# Eli Billinger
# CSCI 102 - Section C
# Week 3 - Part C

amino_acid = " "
carbon = input('Input the chemical elements of the amino acid:\nCARBON>')
hydrogen = input("HYDROGEN>")
nitrogen = input('NITROGEN>')
oxygen = input('OXYGEN>')
sulfer = input('SULFER>')

if carbon == '4':
    if hydrogen == '8':
        if nitrogen == '2':
            if oxygen == '3':
                if sulfer == '0':
                    amino_acid = 'Asparagine'
if carbon == '3':
    if hydrogen == '7':
        if nitrogen == '1':
            if oxygen == '2':
                if sulfer == '0':
                    amino_acid = 'Alanine'
                elif sulfer == '1':
                    amino_acid = 'Cysteine'
if carbon == '5':
    if hydrogen == '10':
        if nitrogen == '2':
            if oxygen == '3':
                if sulfer == '0':
                    amino_acid = 'Glutamine'
if carbon == '6':
    if hydrogen == '9':
        if nitrogen == '3':
            if oxygen == '2':
                if sulfer == '0':
                    amino_acid = 'Histidine'
        
    elif hydrogen == '14':
        if nitrogen == '4':
            if oxygen == '2':
                if sulfer == '0':
                    amino_acid = 'Arginine'


print('The amino acid for C_%sH_%sN_%sO_%sS_%s is %s' % (carbon,hydrogen,nitrogen,oxygen,sulfer,amino_acid))
print('OUTPUT C_%sH_%sN_%sO_%sS_%s' % (carbon,hydrogen,nitrogen,oxygen,sulfer))
print('OUTPUT', amino_acid)
