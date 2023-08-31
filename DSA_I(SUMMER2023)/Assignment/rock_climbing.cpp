// PB Link : https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing

/*
Raka wants to climb a rock from a starting point to the destination point. Given a MAP of the rock
mountain which N = height, M = width. In the MAP, character '-' is the possible foot place spot 
(where he can climb). He can freely move up/down at vertical spots which '-' exists sequentially.
It's impossible to move horizontally in case '-' is not consecutive in the same height level.
The maximum height of moving from the starting point to the destination point is the level of 
difficulty of rock climbing . The total distance of movement is not important. There is more than
one path from the starting point to the destination point. Output: The minimum level of difficulty
of all rock climbing paths level.

Hint: Start with difficulty level 0 and then keep increasing it one by one. Raka always starts from
bottom left position.

Input Format
------------------
First line contains n,m number of rows, columns respectively Next n lines each containg m integers.
interger 3 represenets goal point, interger 1 represent '-', 0 represent "no step".

Constraints
-----------------
1 <= N,M <= 10

Output Format
-----------------
Single interger "level"

Sample Input 0
----------------
5 8
1 1 1 1 0 0 0 0
0 0 0 3 0 1 1 1
1 1 1 0 0 1 0 0
0 0 0 0 0 0 1 0
1 1 1 1 1 1 1 1

Sample Output 0
----------------
2
*/

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define __fastIO__ ios_base::sync_with_stdio(false); cin.tie(NULL);

int n = 10, m = 10, min_level = 11, dfs_called = 0;

vector<vector<int>> MAP(n,vector<int>(m,0));
vector<vector<int>> visited(n,vector<int>(m,0));

void print_map(int i, int j) {
    system("clear");

    printf("The MAP Status -> \n\n");
    for (int _i = 0; _i < n; _i++){
        for (int _j = 0; _j < m; _j++){
            if (_i == i && _j == j){
                printf("_P_");
                continue;
            }
            switch (MAP[_i][_j]){
                case 0:
                    printf(" ~ ");
                    break;
                case 1:
                    printf("___");
                    break;
                case 3:
                    printf("_G_");
                    break;
            }
        }
        printf("\n");
    }

    printf("\n");

    printf("\nEnter to continue ...");
    getchar();
}

bool valid_cell(int i, int j){
    return (i < n || i >= 0) 
            && (j < m && j >= 0)
                && (MAP[i][j] != 0);
}

void run(int i,int j,int cell_jumped) { 
    dfs_called++;
    //print_map(i, j);

    // base case - 1
    if (!valid_cell(i, j) || visited[i][j])  return;
    
    // base csae - 2
    if (MAP[i][j]==3) {
        if(cell_jumped < min_level) {
            min_level = cell_jumped;
            return;
        }
    }

    // marking the cell as visited to avoid loops
    visited[i][j] = 1; 
    
    // checking if, by jumping (to any height) from the current cell, I can reach to the goal
    // or to a higher step to stand on.
    for(int _i = 0; _i < n; _i++) {
        if(MAP[_i][j] == 0 || visited[_i][j] == 1) continue;
        run(_i, j, max(abs(i - _i), cell_jumped));
    }
    
    // moving horizontally
    if(valid_cell(i, j - 1)) run(i, j - 1, cell_jumped);
    if(valid_cell(i, j + 1)) run(i, j + 1, cell_jumped);
    
    // when done exploring reset the visited status of the node used in the path
    visited[i][j] = 0;
    
}

int main() {
    __fastIO__

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>MAP[i][j];
        }    
    }

    run(n-1,0,0);

    cout << min_level << endl;

    printf("dfs called -> %d times\n", dfs_called);

    return 0;
}