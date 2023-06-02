# PB Link : https://vjudge.net/contest/561093?fbclid=IwAR0mAKGKvcRnald64QWvLWCvAs_uIIXeHrMCL04sP0bAiUqIHRefuVVlg_k#problem/C

combinations = [0] * 2001
combinations[1] = 1
combinations[2] = 3

for i in range(3, 2001):
    combinations[i] = (3 * combinations[i-1]) - combinations[i-2]

while True:
    n = int(input())
    
    if n == 0:
        break
        
    print(combinations[n])