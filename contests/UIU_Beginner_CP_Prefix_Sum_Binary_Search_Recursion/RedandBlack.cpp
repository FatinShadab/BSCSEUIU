// Problem : https://vjudge.net/contest/544590?fbclid=IwAR1stOHEIoWUKzwkBHaxzxjQUNmRNjGF-4tujotFQcGsQpvfIfeh9WXP2IY#problem/X

//#include <bits/stdc++.h>
#include <cstdio> // for scanf, printf
#include <utility> // for pair
#include <cstring> // for memset
#include <stdbool.h> // for bool
using namespace std;

const int H = 21, W = 21;

int w, h;
char row[W];

int maze[H][W];
int visited[H][W];

const int dX[] = {-1, 1, 0, 0};
const int dY[] = {0, 0, -1, 1};

pair <int, int> srcNode;

bool inMaze(pair <int, int> node){
    int x = node.first;
    int y = node.second;

    return (x >= 0 && x < h) && (y >= 0 && y < w);
}

bool available(pair <int, int> node){
    int x = node.first;
    int y = node.second;

    return maze[x][y] == 1;
}

void dfs(pair <int, int> src){
    int nodeX = src.first;
    int nodeY = src.second;

    visited[nodeX][nodeY] = 1;

    for (int i=0; i<4; i++){
        pair <int, int> adj_node = make_pair(nodeX + dX[i], nodeY + dY[i]);

        if (inMaze(adj_node) && available(adj_node) && !visited[adj_node.first][adj_node.second]){
            dfs(adj_node);
        }
    }

    return;
}

int floorVisited(){
    int blackTile = 1;

    dfs(srcNode);

    for (int r=0; r<h; r++){
        for (int c=0; c<w; c++){
            if (maze[r][c] == 1 && visited[r][c]){
                blackTile++;
            }
        }
    }

    return blackTile;
}

int main(){
    while (true){
        scanf("%d %d", &w, &h);

        if (!w && !h){
            break;
        }

        getchar();
        for (int r=0; r<h; r++){
            scanf("%s", row);
            for (int c=0; c<w; c++){
                switch (row[c]){
                    case '.':
                        maze[r][c] = 1;
                        break;
                    
                    case '#':
                        maze[r][c] = 0;
                        break;
                
                    default:
                        maze[r][c] = 2;
                        srcNode = make_pair(r, c);
                }
                visited[r][c] = 0;
            }
        }

        printf("%d\n", floorVisited());

        /*for (int r=0; r<h; r++){
            for (int c=0; c<w; c++){
                printf("%d ", maze[r][c]);
            }
            printf("\n");
        }
        printf("\n\n");*/

    }
    
    return 0;
}