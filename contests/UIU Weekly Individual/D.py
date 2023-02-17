# Problem Link : https://vjudge.net/contest/543519#problem/D
from typing import List

i : int; bar : int
_ : int = input()

bars : List = list(map(int, input().split()))

barFrq : List = [0 for i in range(max(bars)+1)]

for bar in bars:
    barFrq[bar] += 1

print(max(barFrq), len(set(bars)))