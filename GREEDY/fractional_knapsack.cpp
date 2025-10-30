#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int n, int profit[], int weight[], float Ratio[]);
void Merge(int profit[], int weight[], float Ratio[], int l, int mid, int r);
void MergeSort(int profit[], int weight[], float Ratio[], int l, int r);

void fknapsack(int n, int m, int profit[], int weight[], float Ratio[]){
    float X[n] = {0.0}, t_profit = 0, left = m;
    int i = 0;

    while(i < n){
        if(weight[i] <= left){
            left -= weight[i], X[i] = 1.0;
            t_profit += profit[i];
        }else{
            break;
        }
        i++;
    }

    if(i < n){
        X[i] = left / weight[i];
        t_profit += profit[i] * X[i], left -= X[i] * weight[i];
    }
    
    cout << "Sack weight = " << m - left << '\n';
    cout << "Total profit = " << t_profit << '\n';
}

void solve(){
    int n, m;
    cin >> n >> m;
    int profit[n], weight[n];
    float Ratio[n];

    for(int i = 0 ; i < n ; i++){
        cin >> profit[i] >> weight[i];
        Ratio[i] = (1.0 * profit[i]) / weight[i];
    }
    // SelectionSort(n, profit, weight, Ratio); // results in O(n^2) complexity for the whole code.
    MergeSort(profit, weight, Ratio, 0, n - 1); // results in O(n logn) complexity for the whole code.
    
    fknapsack(n, m, profit, weight, Ratio);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}



void SelectionSort(int n, int profit[], int weight[], float Ratio[]){
    // O(n ^ 2)
    int j;
    for(int i = 0 ; i < n ; i++){
        j = i + 1;
        while(j < n){
            if(Ratio[i] < Ratio[j] || (Ratio[i] == Ratio[j] && profit[i] < profit[j])){
                swap(profit[i], profit[j]); 
                swap(weight[i], weight[j]);
                swap(Ratio[i], Ratio[j]);
            }
            j++;
        }
    }
}

void Merge(int profit[], int weight[], float Ratio[], int l, int mid, int r){
    int i, j, k, c1[r + 1], c2[r + 1];
    float c3[r + 1];

    i = k = l, j = mid + 1;

    while(i <= mid && j <= r){
        if(Ratio[i] > Ratio[j]){
            c1[k] = profit[i], c2[k] = weight[i], c3[k] = Ratio[i];
            i++, k++;
        }else if(Ratio[i] == Ratio[j] && profit[i] > profit[j]){
            c1[k] = profit[i], c2[k] = weight[i], c3[k] = Ratio[i];
            i++, k++;
        }else{
            c1[k] = profit[j], c2[k] = weight[j], c3[k] = Ratio[j];
            j++, k++;
        }
    }

    while(i <= mid){
        c1[k] = profit[i], c2[k] = weight[i], c3[k] = Ratio[i];
        i++, k++;
    }

    while(j <= r){
        c1[k] = profit[j], c2[k] = weight[j], c3[k] = Ratio[j];
        j++, k++;
    }

    for(int i = l ; i <= r ; i++){
        profit[i] = c1[i], weight[i] = c2[i], Ratio[i] = c3[i];
    }
}

void MergeSort(int profit[], int weight[], float Ratio[], int l, int r){
    //O (n log n)
    if(l < r){
        int mid = (l + r) / 2;
        MergeSort(profit, weight, Ratio, l, mid);
        MergeSort(profit, weight, Ratio, mid + 1, r);
        Merge(profit, weight, Ratio, l, mid, r);
    }
}

