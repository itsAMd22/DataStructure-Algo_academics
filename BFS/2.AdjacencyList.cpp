#include<bits/stdc++.h>
using namespace std;

const int mx = 1e3 + 5;
int vis[mx], par, node, edge, j;
vector< vector<int> > G(mx);

void BFS(int s){
    queue<int> Q;
    Q.push(s), vis[s] = 1;
    cout << s << ' ';

    while(!Q.empty()){
        par = Q.front();
        Q.pop();
    
        for(int i = 0 ; i < G[par].size() ; i++){
            j = G[par][i];
            if(!vis[j]){
                cout << j << ' ';
                Q.push(j), vis[j] = 1;
            }
        }
    }
}

int main(){
    int u, v, sz;
    cin >> node >> edge;
    for(int i = 0 ; i < edge ; i++){
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }

    cout << "Adjacency list :" << endl; 

    for(int i = 0 ; i < node ; i++){
        sz = G[i].size();
        // sort(G[i].begin(), G[i].end());
        cout << i << " -> ";
        for(int j = 0 ; j < sz ; j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
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

