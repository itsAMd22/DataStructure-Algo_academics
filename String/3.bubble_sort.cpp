#include<iostream>
using namespace std;


//bubble sort the first 8 letters of a name.

int main(){
    string name;
    char backup[] = {'Z','P','X','T','Y'};
    cin >> name;
    
    int i=0;
    while(name.size() < 8){ 
        //(size >= 8) => this loop stops/never starts
        name += backup[i];
        i++;
    }

    //bubble sort : it happens based on ascii values
    
    for(int i=0;i<7;i++){
        for(int j=0;j<7-i;j++){
            if(tolower(name[j]) > tolower(name[j+1])){
                // swap(name[j], name[j+1]);
                char tmp = name[j];
                name[j] = name[j+1];
                name[j+1] = tmp;
            }
        }
    }

    cout << name << endl;

    return 0;
}