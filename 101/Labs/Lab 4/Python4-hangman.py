# Eli Billinger
# CSCI 101 - Section G
# Python Lab 4

secret_word = str(input('Enter the secret word\nWORD>'))
num_guesses_allowed = int(input("Enter the number of guesses allowed:\nNUM>"))
guessed_chars = []
char = " "
char_found = ['_']*len(secret_word)

while num_guesses_allowed > 0:
    char = input("Please enter a character:\nINPUT>")
    guessed_chars.append(char)
    num_guesses_allowed -= 1
    if char in secret_word:
        location1 = secret_word.find(char)
        del char_found[location1]
        char_found.insert(location1, char)
        repeat_char = secret_word.count(char)
        
        if repeat_char > 1:
            location2 = secret_word.find(char, location1 + 1)
            del char_found[location2]
            char_found.insert(location2, char)
            
        if str(''.join(char_found)) == secret_word:
            print('Congratulations! You guessed the secret word!')
            print('%d guesses remaining' % (num_guesses_allowed))
            print("Character's guessed: ",','.join(guessed_chars))
            print('OUTPUT Secret word: ',''.join(char_found))
            break
        print('OUTPUT That character is in the word!')
        
    else:
        print('OUTPUT That character is not in the word')
        
    if num_guesses_allowed == 0:
        print('You ran out of guesses :(')
        print('OUTPUT Secret word: ', secret_word)
        break
    
    print('%d guesses remaining' % (num_guesses_allowed))
    print("Character's guessed: ",','.join(guessed_chars))
    print('OUTPUT Secret word: ',''.join(char_found))
