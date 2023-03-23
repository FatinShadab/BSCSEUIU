
T : int = int(input())

while T:
    bulbs : list = list(input())
    ub : set = set(bulbs)
    unique_color_bulbs : int = len(ub)

    if unique_color_bulbs == 1:
        print(-1)

    elif unique_color_bulbs == 2:
        if bulbs.count(tuple(ub)[0]) == 2 and bulbs.count(tuple(ub)[1]) == 2:
            print(4)
        else:
            print(6)
        
    elif unique_color_bulbs == 3:
        print(4)

    elif unique_color_bulbs == 4:
        print(4)
    
    else:
        print(0)

    T -= 1