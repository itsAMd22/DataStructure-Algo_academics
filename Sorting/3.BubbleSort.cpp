#include<bits/stdc++.h>
using namespace std;

void printArr(int a[], int n){
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }
    cout << '\n';
}

int BubbleSort(int n, int a[]){
    int sp = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - 1 - i ; j++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                sp++;
            }
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
    
    int swap_ct = BubbleSort(n, a);    
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