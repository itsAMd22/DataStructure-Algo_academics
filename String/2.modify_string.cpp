#include<iostream>
using namespace std;

//remove all the vowels and special chars from the string and print it.

void modify(string *str, int index, int sz){
    // approach 2
    for(int i = index;i<sz;i++){
        (*str)[i] = (*str)[i+1];
    }
}

void print(string a, int sz){
    // approach 2
    for(int i=0;i<sz;i++){
        cout << a[i];
    }
    cout << endl;
}

int main(){

    // Approach 1 : using a new string

    // string a, b = "";
    // cin >> a;

    // for(int i=0;i<a.size();i++){ 
    //     if(isalpha(a[i])){
    //         if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
    //             continue;
    //         }else if(a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U'){
    //             continue;
    //         }else{
    //             b += a[i];
    //         }
    //     }
    // }

    // cout << b << endl;

    
    // Approach 2 : one string
    string a;   cin >> a;
    char current;
    int sz = a.size();
    for(int i=0;i<sz;i++){
        if(isalpha(a[i])){
            current = tolower(a[i]);
            if(current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u'){
                modify(&a, i--, --sz);
            }
        }else{
            modify(&a, i--, --sz);
        }
    }
    
    print(a, sz);

    return 0;
}
