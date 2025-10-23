#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int n, float Ratio[], int profit[], int weight[]){
    int e, j;
    for(int i = 0; i < n ; i++){
        j = i + 1;
        while(j < n){
            if(Ratio[i] < Ratio[j]){
                swap(Ratio[i], Ratio[j]);
                swap(profit[i], profit[j]);
                swap(weight[i], weight[j]);
            }
            j++;
        }
    }
}

void knacpsack(int n, int m, float Ratio[], int profit[], int weight[]){
    float x[n] = {0.0}, u = m, total = 0.0;
    int i = 0;
    for(i = 0 ; i < n ; i++){
        if(weight[i] > u){
            break;
        }else{
            x[i] = 1.0;
            total += x[i] * profit[i];
            u -= weight[i];
        }
    }

    if(i < n){
        x[i] = u / weight[i];
        total += (x[i] * profit[i]);
    }

    cout << "Total profit = " << total << '\n';
}

void solve(){
    int n, m;
    cin >> n >> m;;
    int profit[n], weight[n];
    float Ratio[n];

    for(int i = 0 ; i < n ; i++){
        cin >> profit[i];
    }

    for(int i = 0 ; i < n ; i++){
        cin >> weight[i];
        Ratio[i] = 1.0 * profit[i] / weight[i];
    }

    SelectionSort(n, Ratio, profit, weight);

    knacpsack(n, m, Ratio, profit, weight);
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