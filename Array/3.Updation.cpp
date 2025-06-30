#include<iostream>
using namespace std;

void print_ar(int a[], int sz){
    for(int i=0;i<sz;++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[100], sz, index, value;
    cin >> sz;

    for(int i=0;i<sz;i++){
        cin >> a[i];
    }

    cin >> index >> value;

    a[index] = value;
    
    print_ar(a, sz);
    return 0;
}