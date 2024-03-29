/*  The Maze of Mysteries - Finding Paths with Treasures (Mark 10)
---------------------------------------------------------------------
    
    You find yourself in a mysterious maze filled with twists and turns,
dead ends, and hidden treasures. Your task is to navigate through the
maze to find paths from the starting position to the exit that contain
hidden treasures. The maze is represented as a 2D grid where each cell
can have the following values:

                        0 -> path
                        1 -> wall
                        2 -> exit
                        3 -> treasure

    Write a function find_paths_with_treasures(maze, start_row, start_col)
that takes the maze grid and your starting position as inputs. The function
should print all the paths from the starting position to the exit (2) that
contain treasures (3). If no such path is possible, the function should 
print "No path with treasure found."

    Your function should implement either BFS or DFS to explore the maze,
avoid walls (1), and identify paths containing treasures. If no such path
is found, the function should print "No path with treasure found."

    input :
    --------------------------------------------------
        5           <- value of 'n', maze size (nxn)
        0 1 2 0 0   <- maze
        0 0 0 1 0
        0 3 1 0 0
        0 1 0 1 0
        0 0 0 0 0
        1 0         <- start point coords

    output : (*** any valid path)
    --------------------------------------------------

        Path with treasure: 
            (1, 0) -> (2, 0) -> (2, 1) > (1, 1) -> (1,2) ->(0,2)

    *** NOTE:
    --------------------------------------------------
    while your dfs implementation will give correct answer but, it might not always find 
    the most optimal path if there are multiple possible paths. Depth-First Search doesn't
    guarantee the shortest path, unlike Breadth-First Search (BFS) which is usually better
    suited for finding the shortest path in a maze.

*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3;

int n;
int maze[N][N];
pair<int, int> parent[N][N];
bool visited[N][N];
int startLoc[2], exitLoc[2], treasureLoc[2];

int dX[] = {0, 0, -1, 1};
int dY[] = {-1, 1, 0, 0};

stack <pair<int, int>> pathStack;
char header[150];

void printMaze(int current_cell_i, int current_cell_j) {
    // clear for linux
    system("clear");
    
    // cls for windows
    //system("cls");
    printf("*** %s\n\n", header);
    printf("|");
    for (int i = 0; i < n; i++){
        printf("===");
    }
    printf("|\n");

    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < n; j++) {
            if (i == current_cell_i && j == current_cell_j) {
                printf(" X ");
            } else {
                if (visited[i][j]){
                    if (maze[i][j] == 3){
                        printf(" ! ");
                        continue;
                    }
                    if (maze[i][j] == 2){
                        printf(" E ");
                        continue;
                    }
                    printf(" * ");
                    continue;
                }

                switch (maze[i][j]) {
                    case 0:
                        printf(" . ");
                        break;
                    case 1:
                        printf(" # ");
                        break;
                    case 2:
                        printf(" E ");
                        break;
                    case 3:
                        printf(" T ");
                        break;
                    default:
                        printf(" ? ");
                        break;
                }
            }
        }
        printf("|\n");
    }

    printf("|");
    for (int i = 0; i < n; i++){
        printf("===");
    }
    printf("|\n");

}

void resetVisited(){
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            visited[i][j] = false;
        }
    }

    return;
}

bool valid_path(int block[]){
    return ((block[0] >= 0 && block[0] < n) && (block[1] >= 0 && block[1] < n) && maze[block[0]][block[1]] != 1);
}

bool valid_maze(){
    if (startLoc[0] == -1 && startLoc[1] == -1) return false;
    if (exitLoc[0] == -1 && exitLoc[1] == -1) return false;
    if (treasureLoc[0] == -1 && treasureLoc[1] == -1) return false;

    return true;
}

void printStackPath(bool intermediate){
    while (!pathStack.empty()){
        pair <int, int> pathCoords = pathStack.top();
        pathStack.pop();

        if (!intermediate){
            if (pathStack.size() > 0)
                printf("(%d, %d) -> ", pathCoords.first, pathCoords.second);
            else
                printf("(%d, %d)\n", pathCoords.first, pathCoords.second); 
        } else {
            printf("(%d, %d) -> ", pathCoords.first, pathCoords.second);
        }

    }
}

/* ------------------ using dfs -------------------- */
void dfs(int src[], int dst[], int initSrc[], bool simulate){
    visited[src[0]][src[1]] = true;

    if (simulate){
        printMaze(src[0], src[1]);
        printf("\n enter to continue ...");
        getchar();
    }

    if (src[0] == dst[0] && src[1] == dst[1]){
        if (!simulate){
            pair<int, int> block = make_pair(dst[0], dst[1]);

            while (!(block.first == initSrc[0] && block.second == initSrc[1])){
                pathStack.push(block);
                
                block = parent[block.first][block.second];
            }

            pathStack.push(make_pair(initSrc[0], initSrc[1]));
        }

        return;
    }

    for (int i = 0; i < 4; i++){
        int nextBlock[2] = {src[0]+dY[i], src[1]+dX[i]};
        
        if (valid_path(nextBlock) && !visited[nextBlock[0]][nextBlock[1]]){
            parent[nextBlock[0]][nextBlock[1]] = make_pair(src[0], src[1]);
            dfs(nextBlock, dst, initSrc, simulate);

            if (visited[dst[0]][dst[1]]){
                return;
            }
        }
    }

    return;
}

void find_paths_with_treasure_dfs(){

    if (!valid_maze()){
        printf("No path with treasure found.\n");
        return;
    }

    dfs(startLoc, treasureLoc, startLoc, false);

    if (!visited[treasureLoc[0]][treasureLoc[1]]){
        printf("No path with treasure found.\n");
        return;     
    }

    printf("Path with treasure: \n\t");
    printStackPath(true);

    resetVisited();
    dfs(treasureLoc, exitLoc, treasureLoc, false);

    if (!visited[exitLoc[0]][exitLoc[1]]){
        printf("No path with treasure found.\n");
        return;
    }

    pathStack.pop();
    printStackPath(false);

    return;
}
/* ------------------------------------------------- */


/* ------------------ using bfs -------------------- */
void bfs(int src[], int dst[], bool simulate){
    queue <pair<int, int>> container;

    container.push(make_pair(src[0], src[1]));
    visited[src[0]][src[1]] = true;

    while (!container.empty()){
        pair<int, int> block = container.front();
        container.pop();

        if (simulate){
            printMaze(block.first, block.second);
            printf("\n enter to continue ...");
            getchar();
        }

        for (int i = 0; i < 4; i++){
            int nextBlock[2] = {block.first+dY[i], block.second+dX[i]};
            
            if (valid_path(nextBlock) && !visited[nextBlock[0]][nextBlock[1]]){
                visited[nextBlock[0]][nextBlock[1]] = true;
                container.push(make_pair(nextBlock[0], nextBlock[1]));
                parent[nextBlock[0]][nextBlock[1]] = make_pair(block.first, block.second);

                if (visited[dst[0]][dst[1]]){
                    while (!container.empty()){
                        container.pop();
                    }
                    break;
                }
            }
        }

        if (simulate){
            printMaze(block.first, block.second);
            printf("\n enter to continue ...");
            getchar();
        }
    }

    if (visited[dst[0]][dst[1]] && simulate){
        printMaze(dst[0], dst[1]);
        printf("\n enter to continue ...");
        getchar();
    }

    if (visited[dst[0]][dst[1]] && !simulate){
        pair<int, int> block = make_pair(dst[0], dst[1]);

        while (!(block.first == src[0] && block.second == src[1])){
            pathStack.push(block);
            
            block = parent[block.first][block.second];
        }

        pathStack.push(make_pair(src[0], src[1]));
    }

    return;
}

void find_paths_with_treasure_bfs(){

    if (!valid_maze()){
        printf("No path with treasure found.\n");
        return;
    }

    bfs(startLoc, treasureLoc, false);

    if (!visited[treasureLoc[0]][treasureLoc[1]]){
        printf("No path with treasure found.\n");
        return;     
    }

    printf("Path with treasure: \n\t");
    printStackPath(true);

    resetVisited();
    bfs(treasureLoc, exitLoc, false);

    if (!visited[exitLoc[0]][exitLoc[1]]){
        printf("No path with treasure found.\n");
        return;
    }

    pathStack.pop();
    printStackPath(false);

    return;
}
/* ------------------ using bfs -------------------- */

void simulation(int withDFS){

    if (withDFS){
        strcpy(header, "Finding the treasure from the start location (using DFS):");
        dfs(startLoc, treasureLoc, startLoc, true);
        resetVisited();
        strcpy(header, "Finding the exit from the treasure location (using DFS):");
        dfs(treasureLoc, exitLoc, treasureLoc, true);
    } else {
        strcpy(header, "Finding the treasure from the start location (using BFS):");
        bfs(startLoc, treasureLoc, true);
        resetVisited();
        strcpy(header, "Finding the exit from the treasure location (using BFS):");
        bfs(treasureLoc, exitLoc, true);
    }

    return;
}

int main(){
    
    memset(startLoc, -1, sizeof(int) * 2);
    memset(exitLoc, -1, sizeof(int) * 2);
    memset(treasureLoc, -1, sizeof(int) * 2);

    printf("Enter the value of 'n' for maze (n x n) :");
    scanf("%d", &n);

    printf("Enter the maze layout (separated by space):\n\t0 -> path\n\t1 -> wall\n\t2 -> exit\n\t3 -> treasure\n\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &maze[i][j]);

            switch (maze[i][j]){
                case 0:
                    case 1:
                        break;

                case 2:
                    exitLoc[0] = i;
                    exitLoc[1] = j;
                    break;

                case 3:
                    treasureLoc[0] = i;
                    treasureLoc[1] = j;
                    break;

                default:
                    maze[i][j] = 0;
            }
        }
    }

    SRCINPUT:
        printf("\nEnter the start location's coords (i, j) : ");
        scanf("%d%d", &startLoc[0], &startLoc[1]);

        if (!valid_path(startLoc)){
            goto SRCINPUT;
        }


    USERSELECTION:
        int user_selection = -1;
        int show_simulation = 0;

        printf("\nEnter 1 to use bfs and 0 to use dfs (1/0): ");
        scanf("%d", &user_selection);
        printf("Show simulation ? (0/1) : ");
        scanf("%d", &show_simulation);
        getchar();

        
        switch (user_selection){
            case 0:
                if (!(show_simulation == 0)){
                    simulation(1);
                    resetVisited();
                }

                find_paths_with_treasure_dfs();

                break;

            case 1:
                if(!(show_simulation == 0)){
                    simulation(0);
                    resetVisited();
                }

                find_paths_with_treasure_bfs();

                break;

            default:
                printf("Invalid Option !\n");
                goto USERSELECTION;
        }
        
    return 0;
}