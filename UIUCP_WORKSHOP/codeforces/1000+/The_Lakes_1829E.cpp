// PB Link : https://codeforces.com/problemset/problem/1829/E

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define __fastIO__ ios_base::sync_with_stdio(false); cin.tie(NULL);

const int dX[] = {0, 0, 1, -1};
const int dY[] = {1, -1, 0, 0};

int n, m;
int max_volume = 0;

int dfs(int r, int c, int volume, vector<vector<int>>& land_map, vector<vector<bool>>& visited){
    volume += land_map[r][c];
    visited[r][c] = true;

    for (int i=0; i<4; i++){
        if (
            (r+dX[i] >= 0 && r+dX[i] < n)
            && (c+dY[i] >= 0 && c+dY[i] < m)
            && land_map[r+dX[i]][c+dY[i]]
            && !visited[r+dX[i]][c+dY[i]]
            ){
            volume = dfs(r+dX[i], c+dY[i], volume, land_map, visited);
        }
    }

    return volume;
}

void solve(){
    cin >> n >> m;

    vector<vector<int>> land_map(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> land_map[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (land_map[i][j] && !visited[i][j]){
                int v = dfs(i, j, 0, land_map, visited);
                max_volume = max(max_volume, v);
            }
        }
    }

    cout << max_volume << endl;

    return;
}

int main(){
    __fastIO__
    
    int T; cin >> T;

    while (T--){
        solve();
        max_volume = 0;
    }

    return 0;
}