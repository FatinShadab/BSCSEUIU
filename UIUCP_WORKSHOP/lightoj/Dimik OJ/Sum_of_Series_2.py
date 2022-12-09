from math import factorial

testcase : int = int(input())

while testcase:

    n : int = int(input())

    print("{_sum:.4f}".format(_sum=sum([i/factorial(i) for i in range(1, n+1)])))

    testcase -= 1