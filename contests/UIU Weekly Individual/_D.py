# PB Link : https://vjudge.net/contest/561667#problem/D

testcase = int(input())

while testcase:
    valid = True

    array_len = int(input())
    array = list(map(int, input().split()))

    even_idx = [0, 0]
    odd_idx = [0, 0]

    for idx, ele in enumerate(array):
        if idx%2 == 0:
            even_idx[ele%2] += 1
        else:
            odd_idx[ele%2] += 1

    #print(even_idx, odd_idx)

    if even_idx[0]*even_idx[1] != 0:
        valid = False

    if odd_idx[0]*odd_idx[1] != 0:
        valid = False

    print("YES" if valid else "NO")

    testcase -= 1