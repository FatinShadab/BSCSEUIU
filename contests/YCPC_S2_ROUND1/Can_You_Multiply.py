# PB LINK : https://www.hackerrank.com/contests/ycpc-by-phitron-a-2nd-round-contest-1-a-2023/challenges/can-you-multiply

if __name__ == "__main__":
    T : int = int(input())

    for _ in range(T):
        A, B = tuple(map(int, input().split()))
        res = str(A*B)
        print(int(res[len(res)-2:]))