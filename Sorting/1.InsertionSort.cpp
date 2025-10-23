#include<bits/stdc++.h>
using namespace std;

void printArr(int a[], int n){
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }
    cout << '\n';
}

int InsertionSort(int n, int a[]){
    int e, j, sp = 0;
    for(int i = 1; i < n ; i++){
        e = a[i], j = i - 1;
        while(j >= 0 && e < a[j]){
            a[j + 1] = a[j];
            j--;
        }
        sp += (i - 1 - j);
        a[j + 1] = e; 
    }
    return sp;
}

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    int swap_ct = InsertionSort(n, a);    
    cout << "Swap count = " << swap_ct << "\nSorted Array : ";
    printArr(a, n);
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