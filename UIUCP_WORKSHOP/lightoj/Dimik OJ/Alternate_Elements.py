testcase = int(input())

while testcase:
    array = list(map(int, input().split()[1:]))
    
    [print(ele, end=' ') for idx, ele in enumerate(array) if idx % 2 == 0]
    print()
    
    testcase -= 1