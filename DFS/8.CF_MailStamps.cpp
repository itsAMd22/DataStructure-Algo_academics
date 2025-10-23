#include<bits/stdc++.h>
using namespace std;

#define Alhamdulillah ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define db(i) cout << "db -> " << i << endl;
#define pv(v) for(auto e : v)   cout << e << " ";   cout << endl;
#define pm(m) for(auto [x,y] : m)   cout << x << " " << y << endl;   cout << endl;

const ll N = 1e9+6;
// vector<int> graph[N];
// bool visited[N], vis2[N];
map<int, vector<int>> graph;
map<int, bool> vis2;

deque<int> route;
bool end_reached, rht, cen_crossed;
int centre;

void dfs(int node){
    if(vis2[node])   return;
    vis2[node] = true;
    bool found = false;
    for(auto child : graph[node]){

        if(!vis2[child]){
            found = true;
            if(end_reached){
                cout << child << " ";
                rht = true;
            } 
            dfs(child);
            if(end_reached && !rht) cout << child << " ";
        }

        if(node == centre && !cen_crossed){
            cout << node << " ";
            cen_crossed = true;
        } 
    }
    if(!found)  end_reached = true;
}

void solve(){
    int n;  cin >> n;
    int n1, n2;
    while(n--){
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }   
    centre = n1;
    dfs(n1);
}

int main(){
    Alhamdulillah
    int t=1;    // cin >> t;
    while(t--)  solve();
    return 0;
}