# PB Link : https://vjudge.net/contest/561667#problem/B

testcase = int(input())

while testcase:
    string = input()

    valid = True

    if len(string) == 1:
        valid = False

    if 'B' not in string:
        valid = False

    if string[0] == 'B':
        valid = False

    if string[-1] == 'A':
        valid = False

    a_count = 0
    for char in string:
        if char == 'A':
            a_count += 1
        else:
            a_count -= 1

        if a_count < 0:
            valid = False
            break

    print("YES" if valid else "NO")

    testcase -= 1