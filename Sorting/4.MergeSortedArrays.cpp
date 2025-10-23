#include<bits/stdc++.h>
using namespace std;

void printArr(int c[], int sz){
    for(int i = 0 ; i < sz ; i++){
        cout << c[i] << " ";
    }
    cout << '\n';
}


void Merge(int a[], int b[], int c[], int n, int m){
    int i = 0, j = 0, k = 0;

    while(i < n && j < m){
        if(a[i] < b[j]){
            c[k] = a[i];
            i++, k++; 
        }else{
            c[k] = b[j];
            j++, k++; 
        }
    }

    while(i < n){
        c[k] = a[i];
        i++, k++; 
    }

    while(j < m){
        c[k] = b[j];
        j++, k++; 
    }
}


void solve(){
    int n, m;
    cin >> n >> m;
    int a[n], b[m], c[n + m];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < m ; i++){
        cin >> b[i];
    }

    Merge(a, b, c, n, m);
    printArr(c,  n + m);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}