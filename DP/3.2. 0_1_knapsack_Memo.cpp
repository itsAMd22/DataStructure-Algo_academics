#include<bits/stdc++.h>
using namespace std;

const int mx = 1e3 + 5;
int n, m, memo[mx][mx];

int knap(int i, int avW, int p[], int w[]){
    if(i > n || avW <= 0)   return 0;
    if(memo[i][avW] != -1)  return memo[i][avW];
    if(w[i] > avW)  return memo[i][avW] = knap(i + 1, avW, p, w);
    
    int inc = p[i] + knap(i + 1, avW - w[i], p, w), exc = knap(i + 1, avW, p, w);
    return memo[i][avW] = max(inc, exc);
}

int main(){
    cin >> n >> m;

    // dp table initialization
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            memo[i][j] = -1;
        }
    }
    
    int profit[n + 1], weight[n + 1];
    for(int i = 1 ; i <= n ; i++){
        cin >> profit[i] >> weight[i];
    }    
    
    cout << "\nMaximum profit = " << knap(1 , m, profit, weight) << '\n';
    
    //print dp table
    cout << "\nMemorisation table :\n";
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            cout << memo[i][j] << " ";
        }
        cout << '\n';
    }

    

    int i = 1, j = m, X[n + 1] = {0};
    while(j > 0){
        if(memo[i][j] != memo[i + 1][j])    X[i] = 1, j -= weight[i];
        i++;
    }

    cout << "\nWeights taken : ";
    for(int i = 1 ; i <= n ; i++){
        if(X[i] == 1)   cout << weight[i] << " ";
    }
    cout << '\n';

    return 0;
}
