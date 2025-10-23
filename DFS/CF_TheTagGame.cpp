#include<bits/stdc++.h>
using namespace std;

#define Alhamdulillah ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define db(i) cout << "db -> " << i << endl;
#define pv(v) for(auto e : v)   cout << e << " ";   cout << endl;
#define pm(m) for(auto [x,y] : m)   cout << x << " " << y << endl;   cout << endl;

const int N = 1e5+6;
vector<int> graph[N];
bool visited[N];
int max_distance = INT_MIN;

void dfs(int node ,int cur_distance){
    if(visited[node])    return;
    visited[node] = true;
    bool found = false;
    for(auto child : graph[node]){
        if(!visited[child]){
            found = true;
            dfs(child, cur_distance + 1);
        }
    }
    if(!found){
        max_distance = max(max_distance, cur_distance);
    }
}



void solve(){
    int n, x, n1, n2;  cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    dfs(1, 0);
    cout << max_distance * 2;
}

int main(){
    Alhamdulillah
    int t=1;    //cin >> t;
    while(t--)  solve();
    return 0;
}