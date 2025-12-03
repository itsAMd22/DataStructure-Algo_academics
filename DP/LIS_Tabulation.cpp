#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int LIS[n], len = -1, prev[n], ind = n + 1;
    for(int i = 0 ; i < n ; i++){
    
        LIS[i] = 1, prev[i] = -1;
        if(i == 0)  continue;
        
        for(int j = 0 ; j < i ; j++){
            if(arr[j] < arr[i]){
                if(1 + LIS[j] > LIS[i]){
                    LIS[i] = 1 + LIS[j];
                    prev[i] = j;
                    if(LIS[i] > len){
                        len = LIS[i], ind = i;
                    }
                } 
            }
        }
    }
    cout << "Max length = " << len << endl;
    cout << "LIS : ";
    int  ans[len], i = len - 1, j = ind;
    while(i >= 0){
        ans[i] = arr[j];
        i--, j = prev[j];
    }
    for(int i = 0 ; i < len ; i++)   cout << ans[i] << " ";
    return 0;;
}
