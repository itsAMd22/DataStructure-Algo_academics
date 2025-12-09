#include<bits/stdc++.h>
using namespace std;

const int MX = 1e6;
int memo[MX];

int fib(int n){
    if(n <= 1){
        return n;
    }  
    int fib[n + 1];
    fib[0] = 0, fib[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        fib[i] = fib[i - 2] + fib[i - 1];
    }
    return fib[n];
}


int main(){
    int n;
    cin >> n;
    cout << fib(n) << '\n';
    return 0;

}
