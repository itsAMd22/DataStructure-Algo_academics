#include<iostream>
using namespace std;

int main(){
    
    // taking input
    int r,c;    cin >> r >> c;
    int a[r][c];
    //int a[r][c] = {{1,2,3},{4,5,6},{7,8,9}};

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> a[i][j];
        }
    }

    // // row sum : outer loop will iterate over the row
    int row_sum;
    for(int i=0;i<r;i++){
        row_sum = 0;
        for(int j=0;j<c;j++){
            row_sum += a[i][j];
        }
        cout << "row - " << i << ": " << row_sum << endl;
    }
    cout << endl;


    // // column sum : outer loop will iterate over the column
    cout << "Column sum : \n";
    int col_sum;
    for(int i=0;i<c;i++){
        col_sum = 0;
        for(int j=0;j<r;j++){
            col_sum += a[j][i];
        }
        cout << "column - " << i << ": " << col_sum << endl;
    }
    cout << endl;


    // // transpose matrix
    cout << "Transpose matrix : \n";
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    
    cout << endl;


    //addition of two matix
    cout << "Sum of two matrix: \n";
    int b[3][3] = {{1,2,3},{4,5,6},{7,8,9}}, d[3][3]  = {{1,2,3},{4,5,6},{7,8,9}};
    int e[3][3];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            e[i][j] = (b[i][j] + d[i][j]);
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << e[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}