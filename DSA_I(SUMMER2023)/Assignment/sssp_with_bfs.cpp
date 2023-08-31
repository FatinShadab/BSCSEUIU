/*
You are given a graph G with N vertices. Implement a function to find the shortest path
(minimum number of edges) between two given vertices u and v using Breadth-First Search.

input:
there will be two integers 'n' and 'm' in the 1st line,
    n -> number of nodes
    m -> number of edges

Next each 'm' lines contain's two integers 'u' and 'v', the means there is a bidirected
edge between 'u' and 'v',
            u <---> v


**** n <= 10 and n >= 1
**** u, v < n and u, v >= 0

for all test case:
    source : 0
    target : n - 1

Sample Input : [1]
7 8
0 1
0 5
1 2
3 4
2 3
4 6
5 6
2 6

Sample Output : [1]
0 -> 5 -> 6

Sample Input : [2]
5 4
0 1
0 2
1 3
2 4

Sample Output : [2]
0 -> 2 -> 4
*/

#include <bits/stdc++.h>

using namespace std;
const int N =  10;

vector<int> AGJLST[N];
bool visited[N];
int parent[N];
stack <int> stk;
int n, m;


void bfs(int src) {
    queue <int> Q;

    Q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!Q.empty()){
        int node = Q.front();
        Q.pop();

        for (int adj_node : AGJLST[node]){
            if (!visited[adj_node]) {
                visited[adj_node] = true;
                Q.push(adj_node);
                parent[adj_node] = node;
            }
        }
    }

    return;
}

void printSSSP(int src, int dst) {
    bfs(src);

    // building the path
    if (visited[dst]){
        int node = dst;

        while (node != src){
            stk.push(node);

            node = parent[node];
        }

        stk.push(src);
    }

    //cout << "parent array\n";
    //for (int i = 0; i < n; i++){
    //    cout << parent[i] << "\n";
    //}
    //cout << "\n";

    // print the path
    while (!stk.empty()){
        cout << stk.top();
        stk.pop();

        if (stk.size() != 0){
            cout << " -> ";
        }
        else{
            cout << "\n";
        }
    }
}


int main() {
    cin >> n >> m;

    while (m--){
        int u, v;
        cin >> u >> v;

        AGJLST[u].push_back(v);
        AGJLST[v].push_back(u);
    }

    int src = 0;
    int dst = n-1;

    printSSSP(src, dst);

    return 0;
}