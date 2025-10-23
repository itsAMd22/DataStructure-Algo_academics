#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
bool visited[N];
vector<int> graph[N];
int cnt = 0, n, m;


void dfs(int node){
    if(visited[node])   return;
    cout << node << " ";
    visited[node] = true;
    for(auto child : graph[node]){
        dfs(child);
    }
}

void component_cnt(){
    for(int i=1;i<=n;i++){
        if(visited[i])   continue;
        cout << i << " -> ";
        cnt++;
        dfs(i);
        cout << '\n';
    }
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
    component_cnt();
    cout << "Number of connected component = " << cnt << endl;
    return 0;
}