testcase = int(input())

for tcase in range(testcase):
    string = [ch for ch in input()]
    for idx, char in enumerate(string):
        if char == 'L':
            string[idx] = string[idx-1]
        elif char == 'R':
           string[idx] = string[idx+1]

    print(''.join(string))