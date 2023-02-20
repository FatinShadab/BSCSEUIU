for idx, char in enumerate(input()):
    if idx == 0 and char.isalpha():
        print(char.upper(), end="")
        continue
    
    elif char == 's':
        print('$', end="")
    
    elif char == 'i':
        print('!', end="")

    elif char == 'o':
        print('()', end="")

    else:
        print(char, end="")

print(".")


