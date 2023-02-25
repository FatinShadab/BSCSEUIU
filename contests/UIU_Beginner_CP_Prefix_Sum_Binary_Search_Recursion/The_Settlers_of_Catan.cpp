// https://vjudge.net/contest/544590?fbclid=IwAR1stOHEIoWUKzwkBHaxzxjQUNmRNjGF-4tujotFQcGsQpvfIfeh9WXP2IY#problem/Z

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 25;
int n, e, u, v;

vector <int> adj_list[N];
int visited[N];
int level[N];

void dfs(int src){
    visited[src] = 1;

    for (int adjNode : adj_list[src]){
        if (!visited[adjNode]){
            level[adjNode] = level[src] + 1;
            dfs(adjNode);
        }
    }
}

void reset(int u, int v){
    visited[u] = 0;
    visited[v] = 0;

    level[u] = 0;
    level[v] = 0;
}

int main(){

    while (true){
        scanf("%d %d", &n, &e);

        if (!n && !e){
            break;
        }

        for (int i=0; i<e; i++){
            scanf("%d %d", &u, &v);

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);

            reset(u, v);
        }

        for (int i=0;i<n; i++){
            if (!visited[i]){
                level[i] = 0;
                dfs(i);
            }
        }

        printf("%d\n", *max_element(level, level+n));
    }

    return 0;
}