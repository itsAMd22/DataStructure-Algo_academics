#include<iostream>
using namespace std;


//remove all the vowels and special chars from the string and print it.

int main(){
    string a, b = "";
    cin >> a;

    for(int i=0;i<a.size();i++){ 
        if(isalpha(a[i])){
            if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
                continue;
            }else if(a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U'){
                continue;
            }else{
                b += a[i];
            }
        }
    }

    cout << "Before modification -> " << a << endl;
    if(b == "") cout << "Modified string is an empty string.";
    else    cout << "After modification -> " << b << endl;
    return 0;
}