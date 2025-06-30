#include<iostream>
using namespace std;

int main(){
    int n, tg, lo, hi, mid;  cin >> n;
    int a[n];
    for(int i=0;i<n;i++)    cin >> a[i];
    
    cin >> tg;
    lo = 0, hi = n-1;
    
    bool found  = false;

    while(lo <= hi){
        mid = ((lo + hi) >> 1);
        if(a[mid] == tg){
            cout << "Found\n";
            found = true;
            break;
        }else if(a[mid] > tg){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }

    if(!found)  cout << "Not found.\n";
    
    return 0;
}