"""
Link : https://vjudge.net/contest/616828#problem/A

Let A(n) = sin(1–sin(2+sin(3–sin(4+…sin(n))…)
Let S(n) = (…(A1+n)A2+n–1)A3+…+2)An+1

For given N print S(N)

Input
    One integer N. 1 ≤ N ≤ 200
Output
    Line containing SN

Sample 1
Input	        Output
3               ((sin(1)+3)sin(1–sin(2))+2)sin(1–sin(2+sin(3)))+1
"""

def A(c, n):
    print(f"sin({c}", end="")

    if c == n or n == 1:
        print(")", end="")
        return
    
    print("-", end="") if c%2 == 1 else print("+", end="")
    A(c + 1, n)
    print(")", end="")

def S(n, c):
    if n == 1:
        A(1, c)
        print("+1")
        return
    
    A(1, c)
    print(f"+{n})", end="")

    S(n-1, c+1)

def main():
    n : int = int(input())
    print("("*(n-1), end="")
    S(n, 1)

if __name__ == "__main__":
    main()