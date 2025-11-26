#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    
    int coin[n + 1], taken[m], k = 0;

    for(int i = 1 ; i <= n ; i++){
        cin >> coin[i];
    }

    int dp[n + 1][m + 1];

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if(j == 0){
                dp[i][j] = 0;
            }else if(i == 0){
                dp[i][j] = 1e9;
            }else if(j < coin[i]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coin[i]]);
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

    // using bottom-up approach
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(dp[i][j] != dp[i - 1][j]){
            taken[k] = coin[i];
            m -= coin[i], j -= coin[i], k++;
        }else{
            i--;
        }
    }


    if(m != 0){
        cout << "\nNo valid combinations.\n";
    }else{
        cout << "\nMinimum number of coins = " << k << "\nCoins taken : ";
        for(int i = 0 ; i < k ; i++){
            cout << taken[i] << " " ;
        }
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