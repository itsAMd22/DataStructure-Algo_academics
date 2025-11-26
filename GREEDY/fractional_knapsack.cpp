#include<bits/stdc++.h>
using namespace std;

void MergeArray(int l, int mid, int r, int profit[], int weight[], float ratio[]){
    int i = l, k = l, j = mid + 1, ex1[r + 1], ex2[r + 1];
    float ex3[r + 1];

    while(i <= mid && j <= r){
        if((ratio[i] > ratio[j]) || (ratio[i] == ratio[j] && profit[i] >= profit[j])){
            ex1[k] = profit[i], ex2[k] = weight[i], ex3[k] = ratio[i];
            i++;
        }else{
            ex1[k] = profit[j], ex2[k] = weight[j], ex3[k] = ratio[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        ex1[k] = profit[i], ex2[k] = weight[i], ex3[k] = ratio[i];
        i++, k++;
    }

    while(j <= r){
        ex1[k] = profit[j], ex2[k] = weight[j], ex3[k] = ratio[j];
        j++, k++;
    }

    for(int p = l ; p <= r ; p++){
        profit[p] = ex1[p], weight[p] = ex2[p], ratio[p] = ex3[p];
    }
}


void mergeSort(int l, int r, int profit[], int weight[], float ratio[]){
    if(l < r){
        int mid = (l + r) / 2;
        mergeSort(l, mid, profit, weight, ratio);
        mergeSort(mid + 1, r, profit, weight, ratio);
        MergeArray(l, mid, r, profit, weight, ratio);
    }
}


void fknapsack(int n, int m, int profit[], int weight[], float ratio[]){
    int i = 1, W = m;
    float prof = 0.0, X[n + 1] = {0.0};
    
    while(i <= n && m > 0){
        X[i] = min(1.0, 1.0 * m / weight[i]);
        m -= (X[i] * weight[i]);
        i++;
    }

    for(int i = 1 ; i <= n ; i++){
        prof += (X[i] * profit[i]);
    }

    cout << "\nMax profit = " << prof << '\n';
    cout << "Sack weight = " << W - m << '\n';
}

void solve(){
    int n;
    float m;
    cin >> n >> m;

    int profit[n + 1], weight[n + 1];
    float ratio[n + 1];

    for(int i = 1 ; i <= n ; i++){
        cin >> profit[i] >> weight[i];
        ratio[i] = 1.0 * profit[i] / weight[i];
    }
        
    mergeSort(1, n, profit, weight, ratio);

    // cout << "Profit : ";
    // for(int i = 1 ; i <= n ; i++)   cout << profit[i] << " "; cout << endl;
    // cout << "Weight : ";
    // for(int i = 1 ; i <= n ; i++)   cout << weight[i] << " "; cout << endl;
    // cout << "Ratio : ";
    // for(int i = 1 ; i <= n ; i++)   cout << ratio[i] << " "; cout << endl;

    fknapsack(n, m, profit, weight, ratio);
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
