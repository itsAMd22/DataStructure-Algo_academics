#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int profit[n + 1], weight[n + 1];
    int dp[n + 1][m + 1];

    for(int i = 1 ; i <= n ; i++){
        cin >> profit[i] >> weight[i];
    }    

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if(i == 0 || j == 0)    dp[i][j] = 0;
            else if(j < weight[i])  dp[i][j] = dp[i - 1][j];
            else    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + profit[i]);
        }
    }

    //print dp table
    cout << "DP table :\n";
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    
    cout << "\nMaximum profit = " << dp[n][m] << '\n';
    
    int i = n, j = m, X[n + 1] = {0};
    while(i > 0 && j > 0){
        if(dp[i][j] != dp[i - 1][j])    X[i] = 1, j -= weight[i];
        i--;
    }

    cout << "Weights taken : ";
    for(int i = 1 ; i <= n ; i++){
        if(X[i] == 1)   cout << weight[i] << " ";
    }
    cout << '\n';

    return 0;
}