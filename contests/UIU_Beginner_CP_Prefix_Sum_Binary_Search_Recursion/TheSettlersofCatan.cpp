// Problem Link : https://vjudge.net/contest/544590?fbclid=IwAR0Q8_MVk0fLG6K3KZQZ2X5N6zCu5-tkArqfeX2j2itU8IBjljPs2qhkg9U#problem/Z

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 25;
int n, e, u, v, maxRoadLen = 0;

int edge[N][N];
int edgeVisited[N][N];

void dfs(int node, int currentRoadLen){
    
    maxRoadLen = (maxRoadLen < currentRoadLen) ? currentRoadLen:maxRoadLen;

    for (int adjNode=0; adjNode<n; adjNode++){
        if (edge[node][adjNode] && !edgeVisited[node][adjNode] && !edgeVisited[adjNode][node]){
            edgeVisited[node][adjNode] = 1;
            dfs(adjNode, currentRoadLen+1);
            edgeVisited[node][adjNode] = 0;
        }
    }


}

void resetGraph(){
    maxRoadLen = 0;
    fill(&edge[0][0], &edge[0][0] + N*N, 0);
    fill(&edgeVisited[0][0], &edgeVisited[0][0] + N*N, 0);
}

int main(){

    while (true){
        scanf("%d %d", &n, &e);

        if (!n && !e){
            break;
        }

        for (int i=0; i<e; i++){
            scanf("%d %d", &u, &v);
            edge[u][v] = 1;
            edge[v][u] = 1;
        }

        for (int node=0; node<n; node++){
            dfs(node, 0);
        }

        printf("%d\n", maxRoadLen);

        resetGraph();
    }

    return 0;
}
