#include<bits/stdc++.h>
using namespace std;

const int MX = 1e9;

int main(){
    int n, m;
    cin >> n >> m;
    int coins[n + 1], dp[n + 1][m + 1];
    
    for(int i = 1 ; i <= n ; i++)   cin >> coins[i];

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if(j == 0)  dp[i][j] = 0;
            else if(i == 0) dp[i][j] = MX;
            else if(j < coins[i])   dp[i][j] = dp[i - 1][j];
            else    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i]]);
        }
    }

    cout << "DP table :\n";
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }

    int i = n, j = m, X[n + 1] = {0};
    while(i > 0 && j > 0){
        if(dp[i][j] != dp[i - 1][j])    X[i]++, j -= coins[i];
        else    i--;
    }

    if(j != 0){
        cout << "No possible combination.";
    }else{
        cout << "\nCoin -> Frequency\n";
        for(int i = 1 ; i <= n ; i++){
            if(X[i] > 0)    cout << coins[i] << " -> " << X[i] << '\n';
        }
    }    
}