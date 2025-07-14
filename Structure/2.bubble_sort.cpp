#include<iostream>
using namespace std;

struct book{
    string title, author;
    float price;
};

int main(){
    int n;  cin >> n;
    book arr[n];
    
    for(int i=0;i<n;i++){
        cin >> arr[i].title >> arr[i].author >> arr[i].price;
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j].price - arr[j+1].price > 1e-6){  
                // arr[j].price > arr[j+1].price as condition is also valid
                swap(arr[j], arr[j+1]);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << arr[i].title << " " << arr[i].author << " " << arr[i].price << endl; 
    }
    return 0;
}