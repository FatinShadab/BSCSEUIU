T : int = int(input())

for t in range(1, T+1):
    N : int = int(input())

    gradeSum : float = 0.00

    for i in range(N):
        gradeSum += float(input())

    print(f"Case {t}: {round(gradeSum/N, 3)}")