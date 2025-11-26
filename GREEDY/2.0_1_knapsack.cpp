#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    
    int profit[n + 1], weight[n + 1], dp[n + 1][m + 1];

    for(int i = 1 ; i <= n ; i++){
        cin >> profit[i] >> weight[i];
    }

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else if(j < weight[i]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + profit[i]);
            }
        }
    }

    // printing dp table
    cout << "DP Table:\n";
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }

    // result
    cout << "\nmaximum profit = " << dp[n][m] << endl;

    cout << "\nWeights taken: ";

    // using bottom-up approach
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(dp[i][j] != dp[i - 1][j]){
            cout << weight[i] << " ";
            j -= weight[i];
        }
        i--;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}