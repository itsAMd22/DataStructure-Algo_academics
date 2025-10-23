#include<bits/stdc++.h>
using namespace std;

void printArr(int c[], int sz){
    for(int i = 0 ; i < sz ; i++){
        cout << c[i] << " ";
    }
    cout << '\n';
}


void Merge(int a[], int l, int r, int mid){
    int i = l, j = mid + 1, k = l, c[r + 1];

    while(i <= mid && j <= r){
        if(a[i] < a[j]){
            c[k] = a[i];
            i++, k++;
        }else{
            c[k] = a[j];
            j++, k++;
        }
    }

    while(i <= mid){
        c[k] = a[i];
        i++, k++;
    }

    while(j <= r){
        c[k] = a[j];
        j++, k++;
    }
    for(int i = l ; i <= r ; i++){
        a[i] = c[i];
    }
}

void MergeSort(int a[], int l, int r){
    int mid = (l + r) / 2;
    if(l < r){
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, r);
        Merge(a, l, r, mid);
    }
}

void solve(){
    int n, m;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    MergeSort(a, 0, n - 1);
    printArr(a,  n);
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
