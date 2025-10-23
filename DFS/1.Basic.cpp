#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> graph[N];
bool visited[N];

// recursive approach
void dfs(int node){
    //if(visited[node])   return;
    cout << "node = " << node << endl;
    visited[node] = true;
    for(auto child : graph[node]){
        cout << "par -> " << node << '\n' << "child -> " << child << endl;
        if(visited[child])   continue;
        dfs(child);
    }
}


//iterative approach
void dfs_using_stack(int node){
    stack<int> st;
    st.push(node);
    while(st.size() > 0){
        node = st.top();
        st.pop();
        if(!visited[node]){
            cout << "node = " << node << endl;
            visited[node] = true;
            for(auto child : graph[node]){
                cout << "par -> " << node << '\n' << "child -> " << child << endl;
                st.push(child);
            }   
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, n1, n2;   cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> n1 >> n2;
        // undirected graph
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    dfs_using_stack(1);
    return 0;
}