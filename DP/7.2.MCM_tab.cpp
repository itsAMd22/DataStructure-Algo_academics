#include<bits/stdc++.h>
using namespace std;

const int MX = 1e3;
long long dp[MX][MX];


int main(){
    int n, dif = 1, l, r;
    cin >> n;
    
    int d[n + 1];
    for(int i = 0 ; i <= n ; i++){
        cin >> d[i];
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i == j){
                dp[i][j] = 0;
            }else{
                dp[i][j] = INT_MAX;
            }    
        }
    }

    
    for(int i = n ; i >= 1 ; i--){
        for(int j = i + 1 ; j <= n ; j++){
            for(int k = i ; k < j ; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + d[i - 1] * d[k] * d[j]);
            }
        }
    }

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++)   cout << dp[i][j] << " " ;
        cout << endl;
    }

    cout << "lowest cost = " << dp[1][n] << '\n';
    
    return 0;
}