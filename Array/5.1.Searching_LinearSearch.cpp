#include<iostream>
using namespace std;

int main(){
    int a[100], sz, value;
    cin >> sz;
    
    for(int i = 0;i < sz; ++i){
        cin >> a[i];
    }
    
    cin >> value;

    bool found = false;

    for(int i = 0; i < sz;++i){
        if(a[i] == value){
            found  = true;
            break;
        }
    }

    cout << (found ? "Found.\n"  : "Not found.\n");
    return 0;
}