#include<bits/stdc++.h>
using namespace std;

void printArr(int a[], int n){
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }
    cout << '\n';
}

int SelectionSort(int n, int a[]){
    int e, j, sp = 0;
    for(int i = 0; i < n ; i++){
        j = i + 1;
        while(j < n){
            if(a[i] > a[j]){
                swap(a[i], a[j]);
                sp++;
            }
            j++;
        }
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
    int swap_ct = SelectionSort(n, a);    
    cout << "Swap count = " << swap_ct << "\nSorted Array : ";
    printArr(a, n);
    cout << '\n';
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