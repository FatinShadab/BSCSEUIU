draw_broken = False

A, B = tuple(map(int, input().split()))

if A > B:
    print("Argentina")
elif A < B:
    print("Brazil")
else:
    while not draw_broken:
        planty_bs_a = input()
        planty_bs_b = input()

        planty_goals_a = planty_bs_a.count('1')
        planty_goals_b = planty_bs_b.count('1')

        if (planty_goals_a > planty_goals_b):
            print("Argentina")
            draw_broken = True
        elif (planty_goals_b > planty_goals_a):
            print("Brazil")
            draw_broken = True