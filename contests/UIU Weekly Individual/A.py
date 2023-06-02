# PB Link : https://vjudge.net/contest/561667#problem/A

def chop(logs : list[int]) -> int:

    turn = 0

    for log in logs:
        turn += log-1

    return turn

testcase = int(input())

while testcase:
    _ = input()
    logs = list(map(int, input().split()))

    total_turn = chop(logs)

    print("maomao90" if total_turn%2 == 0 else "errorgorn")

    testcase -= 1