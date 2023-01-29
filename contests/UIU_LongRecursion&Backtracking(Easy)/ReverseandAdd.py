"""
    Problem link : https://vjudge.net/problem/UVA-10018/origin
"""

def isPalindrome(num : str) -> bool:
    if (len(num) == 0):
        return True
    
    if (num[0] == num[-1]):
        return isPalindrome(num[1:-1])
    else:
        return False

def getPalindrome(num : int, count = 0) -> "Tuple[int, int]":

    if isPalindrome(str(num)):
        return (num, count)

    revNum : int = int(str(num)[::-1])

    additionRes = num + revNum

    return getPalindrome(additionRes, count+1)


N : int = int(input())

while (N):
    info = getPalindrome(int(input()))
    print(f"{info[1]} {info[0]}")
    N -= 1
