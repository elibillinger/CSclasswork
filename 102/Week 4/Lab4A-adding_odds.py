a = int(input('Insert a positive integer\nINPUT>'))
b = int(input('Insert a positive integer\nINPUT>'))
sum = 0
if a % 2 == 0:
    a += 1
while a <= b:
    sum = sum + a
    a += 2
print('OUTPUT>',sum)
