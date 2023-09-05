# PB LINK : https://www.hackerrank.com/contests/ycpc-by-phitron-a-2nd-round-contest-1-a-2023/challenges/jingle-bell

if __name__ == "__main__":
    N : int = int(input())

    tree = []
    space_count = 0
    
    while space_count < (10+N):
        row = ""

        for idx in range(int(space_count/2)):
           row += " " 

        for i in range(10+N-space_count):
            row += "*"

        for idx in range(int(space_count/2)):
           row += " "

        tree.append(row)
        space_count += 2


    for ele in tree[::-1]:
        print(ele)


    for i in range(5):
        print("     "+("*"*N))