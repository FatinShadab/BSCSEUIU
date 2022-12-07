testcase = int(input())

while testcase:
    p, q, c = map(int, input().split())
    print(f"Result = {(p**q)%c}")
    testcase -= 1