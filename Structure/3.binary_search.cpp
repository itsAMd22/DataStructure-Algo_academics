#include<iostream>
using namespace std;


// find the number of books under a given price

struct book{
    string title, author;
    float price;
};

int main(){
    int n;
    float affordable_price;

    cin >> n >> affordable_price;

    book arr[n];
    
    for(int i=0;i<n;i++){
        cin >> arr[i].title >> arr[i].author >> arr[i].price;
    }

    //sorting before applying binary search
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j].price - arr[j+1].price > 1e-6){  
                // arr[j].price > arr[j+1].price as condition is also valid
                swap(arr[j], arr[j+1]);
            }
        }
    }


    int lo = 0, hi = n-1, mid, ans = -1;

    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(arr[mid].price <= affordable_price){
            ans = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    cout << "affordable book count = " << ans + 1 << endl;
    return 0;
}