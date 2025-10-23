#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
bool visited[N];
vector<int> graph[N];
int cnt = 0, n, m;


bool dfs(int node, int par){
    visited[node] = true;
    bool loopExists = false;
    for(auto child : graph[node]){
        if(visited[child] && child == par)  continue;
        if(visited[child])  return true;
        loopExists |=  dfs(child, node);
    }
    return loopExists;
}

bool components(){
    for(int i=1;i<=n;i++){
        if(visited[i])  continue;
        if(dfs(i, 0)){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    int n1, n2;
    for(int i=1;i<=m;i++){
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    components();
    cout << "Number of connected component = " << cnt << endl;
    cout << boolalpha << components() << endl;
    return 0;
}