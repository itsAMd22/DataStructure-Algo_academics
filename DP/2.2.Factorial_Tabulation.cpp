#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n <= 1){
        return 1;
    }  
    int fact[n + 1];
    fact[0] = 1, fact[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        fact[i] = i * fact[i - 1];
    }
    return fact[n];
}


int main(){
    int n;
    cin >> n;
    cout << fact(n) << '\n';
    return 0;

}
