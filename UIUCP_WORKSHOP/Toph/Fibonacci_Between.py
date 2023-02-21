l, r = tuple(map(int, input().split()))

p1 = 0
p2 = 1

ele = 0

while (ele <= r):
    if ele >= l:
        print(ele)
    
    ele = p1 + p2
    p1 = p2
    p2 = ele