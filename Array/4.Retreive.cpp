#include<iostream>
using namespace std;


int main(){
    int a[100], sz, index;;
    cin >> sz;

    for(int i=0;i<sz;i++){
        cin >> a[i];
    }

    cin >> index;
    cout << a[index];
    return 0;
}