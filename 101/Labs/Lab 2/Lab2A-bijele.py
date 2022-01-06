# Eli Billinger
# CSCI 101 - Section G
# Python Lab 2A

print('Please enter the number of white chess pieces that you have of each type:')
found_king = int(input('KINGS>'))
found_queen = int(input('QUEENS>'))
found_rooks = int(input('ROOKS>'))
found_bishops = int(input('BISHOPS>'))
found_knights = int(input('KNIGHTS>'))
found_pawns = int(input('PAWNS>'))

need_king = 1-found_king
need_queen = 1-found_queen
need_rooks = 2-found_rooks
need_bishops = 2-found_bishops
need_knights = 2-found_knights
need_pawns = 8-found_pawns

print('The output below provides the number of each type you have (over or under):')
print('OUTPUT ' + str(need_king )+ " " + str(need_queen ) +" " + str(need_rooks ) +" " + str(need_bishops ) +" " + str(need_knights ) +" " + str(need_pawns ) +" ")
