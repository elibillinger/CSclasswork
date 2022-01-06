
with open('Caged.txt', 'r') as caged:
    lines = caged.readlines()
with open('caged_converted.txt' , 'w') as caged_converted:
    for line in lines:
        for char in line:
            if char == '&':
                caged_converted.write('%')
            elif char == '%':
                caged_converted.write('&')
            elif char == '/':
                caged_converted.write('~')
            else:
                caged_converted.write(char)

caged.close()

