#include<bits/stdc++.h>
using namespace std;

#define Alhamdulillah ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define db(i) cout << "db -> " << i << endl;
#define pv(v) for(auto e : v)   cout << e << " ";   cout << endl;
#define pm(m) for(auto [x,y] : m)   cout << x << " " << y << endl;   cout << endl;

stack<int>s;
bool found;
ll a, b;
const int N = 1e9+7;

void dfs(ll a){
    if(a > b || found)   return;
    s.push(a);
    if(a == b){
        found = true;
        vector<int> order;
        while(s.size()){
            order.push_back(s.top());
            s.pop();
        }
        reverse(order.begin(), order.end());
        cout << "YES\n" << order.size() << endl;
        pv(order);

    }
    dfs(2 * a);
    dfs(10 * a + 1);
    
    if(!found)  s.pop();
}

void solve(){
    cin >> a >> b;
    dfs(a);
    if(!found)  cout << "NO";
}

int main(){
    Alhamdulillah
    int t=1;    //cin >> t;
    while(t--)  solve();
    return 0;
}