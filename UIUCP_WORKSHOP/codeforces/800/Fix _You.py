from typing import List

testcase : int = int(input())

while (testcase):
    m : int = None
    n : int = None

    m, n = map(int, input().split())

    conveyor_belt : List[str] = [list(input()) for row in range(m)]
    
    # uncomment to see
    #print("\nBefore Fixing : \n")
    #for row in conveyor_belt:
    #    print(f"\t{row}")

    need2change : int = 0

    for row_idx in range(m):
        for col_idx in range(n):
            i = row_idx
            j = col_idx

            while True:
                if i >= m or j >= n:
                    #print(f"i:{i} m:{m}")
                    #print(f"j:{j} n:{n}")
                    if j >= n:
                        conveyor_belt[i][j-1] = 'R' if ele != 'R' else 'D'
                    if i >= m:
                        conveyor_belt[i-1][j] = 'R' if ele != 'R' else 'D'
                    
                    need2change += 1
                    
                    i = row_idx
                    j = col_idx
                
                ele = conveyor_belt[i][j]
                #print(ele, i, j)

                if ele == 'R':
                    j += 1
                if ele == 'D':
                    i += 1
                if ele == 'C':
                    break

    # uncomment to see         
    #print(f"\nAfter Fixing {need2change} cells: \n")
    #for row in conveyor_belt:
    #    print(f"\t{row}")

    print(need2change)

    testcase -= 1