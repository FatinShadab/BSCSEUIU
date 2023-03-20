# Problem link --> https://codeforces.com/contest/1807/problem/C
T : int = int(input())

while (T):
    n : int = int(input())
    str_input : str = input()
    bit : str = '0'

    for char in str_input:
        str_input = str_input.replace(char, bit)
        bit = '1' if bit == '0' else '0'

    flag : int = 1
    s : tuple = tuple(str_input)

    for idx, char in enumerate(s):
        if (idx != 0):
            if s[idx-1] == char:
                flag = 0; break
        if (idx+1 != n):
            if s[idx+1] == char:
                flag = 0; break

    print("YES" if flag else "NO")

    T -= 1