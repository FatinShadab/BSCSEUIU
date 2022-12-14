from typing import List

def algo(n : int) -> int:
    seq_len : int = 1

    while n != 1:

        if n % 2 == 1:
            n = (3*n + 1)
        else:
            n = n//2

        seq_len += 1
    
    return seq_len


if __name__ == "__main__":

    i = int; j = int
    lb = int; ub = int

    # 0 < i, j < 1,000,000
    i, j = map(int, input().split())

    lb, ub = sorted((i, j))

    seq_len_arr : List[int] = [algo(n) for n in range(lb, ub+1)]

    print(i, j, max(seq_len_arr))