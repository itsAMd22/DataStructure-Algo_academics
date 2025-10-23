#include<bits/stdc++.h>
using namespace std;

#define Alhamdulillah ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define db(i) cout << "db -> " << i << endl;
#define pv(v) for(auto e : v)   cout << e << " ";   cout << endl;
#define pm(m) for(auto [x,y] : m)   cout << x << " " << y << endl;   cout << endl;

const int N = 1e3+10;
bool visited[N];
vector<pair<int, int>> graph[N];
int cost = 0;

void dfs(int node){
    if(visited[node])   return;
    visited[node] = true;
    bool found = false;
    for(auto vp : graph[node]){
        if(!visited[vp.first]){
            found = true;
            dfs(vp.first);
            cost += vp.second;
        }
    }

    if(!found){
        for(auto vp : graph[node]){
            if(vp.first == 1){
                cost += vp.second;
                return;
            } 
        }
    }
}

void solve(){
    int n;  cin >> n;
    int n1, n2, w, total = 0;
    while(n--){
        cin >> n1 >> n2 >> w;
        // cout << n1 << n2 << w << endl;
        graph[n1].push_back({n2, 0});
        graph[n2].push_back({n1, w});
        total += w;
    }
    dfs(1);
    cout << min(cost , total - cost);
}

int main(){
    Alhamdulillah
    int t=1;    //cin >> t;
    while(t--)  solve();
    return 0;
}