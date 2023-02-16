T : int = int(input())

validBall = ('0', '1', '2', '3', '4', '5', '6', 'O')

for t in range(1, T+1):
    validBalls : int = 0

    overStr : str = input()

    for ball in overStr:
        if ball in validBall:
            validBalls += 1

    if validBalls <= 1:
        print(f"{validBalls} BALL")

    elif validBalls < 6:
        print(f"{validBalls} BALLS")

    else:
        over : int = 0
        
        while (validBalls >= 6):
            validBalls -= 6
            over += 1
        
        if over == 1:
            print(f"{over} OVER", end="")
        else:
            print(f"{over} OVERS", end="")

        if (validBalls >= 2):
            print(f" {validBalls} BALLS")
        elif (validBalls == 1):
            print(f" {validBalls} BALL")
        else:
            print()