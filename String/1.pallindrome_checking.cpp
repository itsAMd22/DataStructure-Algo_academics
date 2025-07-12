#include<iostream>
using namespace std;

int main(){
    string str1, str2 = "";
    cin >> str1;

    int sz = str1.size();
    char c;
    for(int i=0;i<sz;i++){
        str2 += (str1[sz - 1 - i] += (str1[sz - 1 - i] < 'a' ? 32 : 0));
        //converting all to lower case.
    }

    cout << str1 << " " << str2 << endl;

    if(str1 == str2)    cout << "Palindrome.";
    else    cout << "Not Palindrome.";

    return 0;
}