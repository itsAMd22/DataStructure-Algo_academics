#include<bits/stdc++.h>
using namespace std;

const int MX = 1e3 + 5;
int dp[MX][MX];

int knap(int i, int available_W, int profit[], int weight[]){
    int j = available_W;
    
    if(i < 1 || available_W <= 0)   return 0;   // not valid or not enough space in the sack.
    if(dp[i][j] != -1)         return dp[i][j];    // already calculated
    if(weight[i] > j)          return dp[i][j] = knap(i - 1, available_W, profit, weight);     // this weight cannot be taken
    
    // include weight[i]
    int inc = profit[i] + knap(i - 1, available_W - weight[i], profit, weight);

    // exclude weight[i]
    int exc = knap(i - 1, available_W, profit, weight);
    
    return dp[i][j] = max(inc, exc);
}

int main(){
    int n, m;
    cin >> n >> m;

    // dp table initialization
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            dp[i][j] = -1;
        }
    }


    int profit[n + 1], weight[n + 1];

    for(int i = 1 ; i <= n ; i++){
        cin >> profit[i] >> weight[i];
    }    
    
    cout << "\nMaximum profit = " << knap(n , m, profit, weight) << '\n';
    
    //print dp table
    cout << "\nMemorisation table :\n";
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }

    

    int i = n, j = m, X[n + 1] = {0};
    while(i > 0 && j > 0){
        if(dp[i][j] != dp[i - 1][j])    X[i] = 1, j -= weight[i];
        i--;
    }

    cout << "\nWeights taken : ";
    for(int i = 1 ; i <= n ; i++){
        if(X[i] == 1)   cout << weight[i] << " ";
    }
    cout << '\n';

    return 0;
}