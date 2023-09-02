/*
 Two weighted graph is given. You need to find the edge with maximum weight
 between the source and destination nodes. In term of the path from source
 to destination we will consider the number of edges needed and determine the
 shortest path and output the maximum cost encountered on that path.

 Input:
    1st line contains two integers 'n' and 'm',
        'n' -> number of nodes
        'm' -> number of edges
    
    next each 'm' lines contain's 3 integers 'u', 'v', 'c'
        'u' and 'v' represents node [-1 < u, v < n]
        'c' represents the cost of the edge [0 < c < 1e9]

        such that,

            u <--- (c) ---> v

    last line of the input contains two integer 's' and 'd',
        's' -> source node
        'd' -> destination node

        [s, d ∈ N] [N = set of nodes in the graph]

 Sample Input:
    5 4
    0 1 2
    0 2 1
    2 4 2
    1 3 3
    0 3
 Sample Output:
    3

 Sample Input:
    7 8
    0 1 5
    0 5 8
    1 2 2 
    2 3 1
    2 6 3
    3 4 6
    4 6 3
    5 6 4
    1 5
 Sample Output:
    8
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e2;

int n, m;
vector<pair<int, int>> adjList[N];
bool visited[N];

int edge_with_max_cost_in_sssp(int src, int dst){
    int max_cost_encountered = -1;
    queue <int> myQ;

    visited[src] = true;
    myQ.push(src);


    while (!myQ.empty()){
        int node = myQ.front();
        myQ.pop();

        for (pair<int, int> adjEntry : adjList[node]){
            int adjNode = adjEntry.first;
            int edgeCost = adjEntry.second;
            
            if (!visited[adjNode]){
                max_cost_encountered = max(max_cost_encountered, edgeCost);
                visited[adjNode] = true;
                myQ.push(adjNode);
            }

            if (visited[dst]){
                while (!myQ.empty()){
                    myQ.pop();
                }

                break;
            }
        }
    }


    return (visited[dst]) ? max_cost_encountered:-1;
}

int main(){
    int src, dst;

    cout << "Enter the number of nodes and edges (n, m): ";
    cin >> n >> m;

    cout << "Enter the edge with cost (u, v, c) => u <--c--> v [-1 < u, v < n]: \n";
    while (m--){
        int u, v, c;
        cin >> u >> v >> c;

        adjList[u].push_back(make_pair(v, c));
        adjList[v].push_back(make_pair(u, c));
    }

    cout << "Enter the source and destination node : ";
    cin >> src >> dst;

    cout << "Max cost encountered : " << edge_with_max_cost_in_sssp(src, dst) << "\n";

    return 0;
}