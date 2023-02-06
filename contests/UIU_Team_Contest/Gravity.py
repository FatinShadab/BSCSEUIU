"""
    Input           Output
    10 10
    ...ooo...#      .....o...#
    #o#..#.o.o      #.#..#....
    ..........      ..........
    oooooooooo      .o.o...o.o
    ..........      .o.o.o.o.o
    .#.#.#.#.#      .#.#.#.#.#
    ..........      ....o.....
    ...oo.....      ....o.....
    ...oo.....      ...oo.o.o.
    .....#####      o.ooo#####
"""

n : int; m : int; i : int; rowIdx : int; charIdx : int; row : str; char : str

n, m = tuple(map(int, input().split()))

maze : list = [list(input()) for i in range(n)]

while True:
    changed : int = 0
    for rowIdx, row in enumerate(maze):
        for charIdx, char in enumerate(row):
            if char == 'o':
                if rowIdx != n-1:
                    if maze[rowIdx+1][charIdx] == '.':
                        maze[rowIdx+1][charIdx] = 'o'
                        maze[rowIdx][charIdx] = '.'
                        changed = 1
    
    if changed == 0:
        break

for row in maze:
    print("".join(row))