testcase = int(input())

for tcase in range(testcase):
    numbers = 0
    number_str = input()

    for char in number_str.split(" "):
        try:
            int(char)
            numbers += 1
        except:
            pass
        
    print(numbers)