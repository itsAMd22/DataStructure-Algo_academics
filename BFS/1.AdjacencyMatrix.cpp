#include<bits/stdc++.h>
using namespace std;

const int mx = 1e3 + 5;
int vis[mx], par, node, edge;
int G[mx][mx];

void BFS(int s){
    queue<int> Q;
    Q.push(s), vis[s] = 1;
    cout << s << ' ';
    
    while(!Q.empty()){
        par = Q.front();
        Q.pop();
    
        for(int i = 0 ; i < node ; i++){
            if(G[par][i] == 1 && !vis[i]){
                cout << i << ' ';
                Q.push(i), vis[i] = 1;
            }
        }
    }
}

int main(){
    int u, v, sz;
    cin >> node >> edge;
    for(int i = 0 ; i < edge ; i++){
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }

    cout << "Adjacency Matrix :" << endl; 
    
    for(int i = 0 ; i < node ; i++){
        for(int j = 0 ; j < node ; j++){
            cout << G[i][j] << " ";
        }
        cout << '\n';
    }
    cout << endl;

    cout << "BFS Traversal: ";
    
    for(int i = 0 ; i < node ; i++){
        if(!vis[i]){
            BFS(i);
        }
    }

    cout << endl;
    return 0;
}

