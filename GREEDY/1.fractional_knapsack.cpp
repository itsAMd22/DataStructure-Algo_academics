#include<bits/stdc++.h>
using namespace std;

void merge(int l, int mid, int r, float profit[], float weight[], float ratio[]){
    int i = l, j = mid + 1, k = l;
    float Cprof[r + 1], Cweig[r + 1], Crat[r + 1]; 

    while(i <= mid && j <= r){
        if((ratio[i] > ratio[j]) || (ratio[i] == ratio[j] && profit[i] > profit[j])){
            Cprof[k] = profit[i], Cweig[k] = weight[i], Crat[k] = ratio[i];
            i++;
        }else{
            Cprof[k] = profit[j], Cweig[k] = weight[j], Crat[k] = ratio[j];
            j++;
        }
        k++;
    } 

    while(i <= mid){
        Cprof[k] = profit[i], Cweig[k] = weight[i], Crat[k] = ratio[i];
        i++, k++;
    }

    while(j <= r){
        Cprof[k] = profit[j], Cweig[k] = weight[j], Crat[k] = ratio[j];
        j++, k++;
    }

    for(int i = l ; i <= r ; i++){
        profit[i] = Cprof[i], weight[i] = Cweig[i], ratio[i] = Crat[i];
    }
}

void merge_sort(int l, int r, float profit[], float weight[], float ratio[]){
    if(l < r){
        int MID = (l + r) / 2;
        merge_sort(l, MID, profit, weight, ratio);
        merge_sort(MID + 1, r, profit, weight, ratio);
        merge(l, MID, r, profit, weight, ratio);
    }
}

int main(){
    int n;
    float m, tmp;
    cin >> n >> m;
    tmp = m;
    float profit[n], weight[n], ratio[n], X[n], tpf = 0.0;
    for(int i = 0 ; i < n ; i++){
        cin >> profit[i] >> weight[i];
        ratio[i] = profit[i] / weight[i];
    }

    merge_sort(0, n - 1, profit, weight, ratio);

    // cout << "Profit : ";
    // for(int i = 0 ; i < n ; i++)   cout << profit[i] << " "; cout << endl;
    // cout << "Weight : ";
    // for(int i = 0 ; i < n ; i++)   cout << weight[i] << " "; cout << endl;
    // cout << "Ratio : ";
    // for(int i = 0 ; i < n ; i++)   cout << ratio[i] << " "; cout << endl;
    

    int i = 0;
    while(i < n && m > 0.0){
        X[i] = min(1.0, 1.0 * m / weight[i]);
        m -= X[i] * weight[i], tpf += X[i] * profit[i];
        i++;
    }

    cout << "Maximum profit = " << tpf << '\n';
    cout << "Final sack weight = " << tmp - m << '\n';

    return 0;
}
