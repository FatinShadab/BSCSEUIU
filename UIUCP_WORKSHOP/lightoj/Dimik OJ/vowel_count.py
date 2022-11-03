vowels = ('a', 'e', 'i', 'o', 'u')
testcase = int(input())

for tcase in range(testcase):
    vowels_number = 0
    string = input()
    
    for char in string:
        if char.lower() in vowels:
            vowels_number += 1
            
    print(f"Number of vowels = {vowels_number}")