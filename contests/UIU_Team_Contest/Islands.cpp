#include <bits/stdc++.h>
using namespace std;

const int N = 50, M = 50;
int n, m;
int visited[N][M];
int MAP[N][M];

int dX[] = {0, 0, -1, 1};
int dY[] = {1, -1, 0, 0};

int inMap(pair <int, int> node){
    int nodeX = node.first;
    int nodeY = node.second;

    return (nodeX >= 0 && nodeX < n) && (nodeY >= 0 && nodeY < m);
}

void DFS(pair<int, int> node){
    int nodeX = node.first;
    int nodeY = node.second;

    visited[nodeX][nodeY] = 1;

    for (int i=0; i<4; i++){
        pair <int, int> adjNode = {nodeX + dX[i], nodeY + dY[i]};

        if (inMap(adjNode) && MAP[adjNode.first][adjNode.second] && !visited[adjNode.first][adjNode.second]){
            DFS(adjNode);
        }
    }

    return;
}

int main(){
    int islands = 0;
    int landFound = 0;
    pair <int, int> node;

    scanf("%d %d", &n, &m);
    getchar();

    for (int row=0; row<n; row++){
        char rowStr[m+1];
        gets(rowStr);

        for (int col=0; col<m; col++){
            switch (rowStr[col]){
                case 'L':
                    MAP[row][col] = 1;
                    if (!landFound) landFound = 1;
                    break;
                case 'W':
                    MAP[row][col] = 0;
                    break;
                case 'C':
                    MAP[row][col] = 2;
                    break;
            }
        }
    }

    /*
    puts("");
    for (int row=0; row<n; row++){
        for (int col=0; col<m; col++){
            printf("%d ", MAP[row][col]);
        }
        puts("");
    }
    puts("");
    */

    if (!landFound){
        puts("0");
        return 0;
    }

    for (int row=0; row<n; row++){
        for (int col=0; col<m; col++){
            if ((MAP[row][col] == 1) && !visited[row][col]){
                islands++;
                node = {row, col};
                DFS(node);
            }
        }
    }

    printf("%d\n", islands);

    return 0;
}