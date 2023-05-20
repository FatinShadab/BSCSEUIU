import sys

for line in sys.stdin:
    n = int(line.strip())
    p = 0
    num = 0

    while True:
        num += 1 * 10**p
        p += 1

        #print(f"\t num:{num}, p:{p}")

        if num % n == 0:
            break

    print(p)