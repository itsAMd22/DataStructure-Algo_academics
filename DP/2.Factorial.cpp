#include<bits/stdc++.h>
using namespace std;

const int MX = 1e6;
int memo[MX];

int fact(int n){
    if(n <= 1){
        return 1;
    }  

    return n * fact(n - 1);
}

int fact_memo(int n){
    if(memo[n] >= 0){
        return memo[n];
    }

    return memo[n] = n * fact_memo(n - 1);
}

int main(){
    int n;
    cin >> n;
    cout << "Without memorisation : " << fact(n) << '\n';
    
    for(int i = 0 ; i <= n ; i++){
        if(i <= 1)  memo[i] = 1;
        else    memo[i] = -1;
    }   
    cout << "With memorisation : " << fact_memo(n) << '\n';
}