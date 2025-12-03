#include<bits/stdc++.h>
using namespace std;

const int MX = 1e6;
int memo[MX];

int fib(int n){
    if(n <= 1){
        return n;
    }  

    return fib(n - 2) + fib(n - 1);
}

int fib_memo(int n){
    if(n <= 1)  return n;
    if(memo[n] >= 0){
        return memo[n];
    }

    return memo[n] = fib_memo(n - 2) + fib_memo(n - 1);
}

int main(){
    int n;
    cin >> n;
    cout << "Without memorisation : " << fib(n) << '\n';
    
    for(int i = 0 ; i <= n ; i++){
        if(i <= 1)  memo[i] = i;
        else    memo[i] = -1;
    }   
    cout << "With memorisation : " << fib_memo(n) << '\n';
}