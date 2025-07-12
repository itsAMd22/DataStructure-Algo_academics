#include<iostream>
using namespace std;

void print_ar(int a[], int sz){
    for(int i=0;i<sz;++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[100], sz, element, index;;
    cin >> sz;

    for(int i=0;i<sz;i++){
        cin >> a[i];
    }

    cin >> index >> element;

    for(int i = sz - 1;i >= index;--i){
        a[i+1] = a[i];
    }
    a[index] = element, ++sz;

    print_ar(a, sz);
    return 0;
}
