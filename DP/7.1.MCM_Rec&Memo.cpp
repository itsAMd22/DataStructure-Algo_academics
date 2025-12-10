#include<bits/stdc++.h>
using namespace std;

const int MX = 1e3;
long long memo[MX][MX];

long long C(int l, int r, long long d[]){
    if(l == r)  return 0;
    if(memo[l][r] != -1)    return memo[l][r];

    long long mn = INT_MAX, C_lkr;

    for(int k = l ; k < r ; k++){
        C_lkr = C(l, k, d) + C(k + 1, r, d) + (d[l - 1] * d[k] * d[r]);
        mn = min(mn, C_lkr);
    }

    return memo[l][r] = mn;
}

int main(){
    int n;
    cin >> n;
    
    for(int i = 0 ; i <= n ; i++){
        for(int j = i ; j <= n ; j++){
            memo[i][j] = -1;
        }
    }

    long long d[n + 1] = {0};

    for(int i = 0 ; i <= n ; i++){
        cin >> d[i];
    }

    int lowest_cost = C(1, n, d);
    
    cout << "lowest cost = " << lowest_cost << '\n';
    
    return 0;
}