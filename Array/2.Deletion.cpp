#include<iostream>
using namespace std;

void print_ar(int a[], int sz){
    for(int i=0;i<sz;++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[100], sz, index;;
    cin >> sz;

    for(int i=0;i<sz;i++){
        cin >> a[i];
    }

    cin >> index;

    for(int i = index;i < sz - 1;++i){
        a[i] = a[i+1];
    }
    --sz;
    
    print_ar(a, sz);
    return 0;
}