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
vector<pair<int,int>>   graph[N];
int mx = INT_MIN, nd, cst, cost = 0;

void dfs(int node){
    if(visited[node])   return;
    visited[node] = true;
    bool found = false;
    for(auto vp : graph[node]){
        if(!visited[vp.first]){
            found = true;
            cost += vp.second;
            dfs(vp.first);
            cost -= vp.second;
        }
    }
    if(!found){
        mx = max(mx, cost);
        return;
    }
}

void solve(){
    int n, node1, node2, exp;  cin >> n;
    n--;
    while(n--){
        cin >> node1 >> node2 >> exp;
        graph[node1].push_back({node2, exp});
        graph[node2].push_back({node1, exp});
    }
    dfs(0);
    cout << mx;
}

int main(){
    Alhamdulillah
    int t=1;    //cin >> t;
    while(t--)  solve();
    return 0;
}