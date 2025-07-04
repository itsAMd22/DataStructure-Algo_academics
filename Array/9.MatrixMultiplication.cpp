#include<iostream>
using namespace std;

int main(){
    int r1, c1, r2, c2; 

    cin >> r1 >> c1;
    int mat1[r1][c1];
    
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin >> mat1[i][j];
        }
    }
    
    cin >> r2 >> c2;
    int mat2[r2][c2];
    
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin >> mat2[i][j];
        }
    }

    int mat3[r1][c2];

    if(r2 != c1){
        cout << "Not possible.\n";
    }else{
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                mat3[i][j] = 0; //initialized to zero to avoid garbage value due to uninitialized declaration.
                for(int k=0;k<c1;k++){
                    mat3[i][j] += mat1[i][k] * mat2[k][j];
                }
                cout << mat3[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}