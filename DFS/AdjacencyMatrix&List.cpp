#include<bits/stdc++.h>
using namespace std;

// undirected graph
// a[i][j] = 1 if i is connected to j


// Adjacancy matrix provides faster accessing
// Adjacency list allows a bigger number of nodes in the graph then matrix.

const int N = 1e3+5;

// adjacency matrix
int matrix[N][N];

// adjacency list
vector<vector<pair<int, int>>> llist(N+N);

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int node_ct, edge_ct, v1, v2, w;
    cin >> node_ct >> edge_ct;

    for(int i=1;i<=node_ct;i++){
        cin >> v1 >> v2;

        // cin >> w; // here w -> weight
        w = 1;

        //adjacency matrix
        matrix[v1][v2] = w;
        matrix[v1][v1] = w;

        //adjacency list
        llist[v1].push_back({v2,w});
        llist[v2].push_back({v1,w});
    }

    return 0;
}