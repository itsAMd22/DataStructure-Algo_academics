#include<bits/stdc++.h>
using namespace std;

//leetcode : https://leetcode.com/problems/flood-fill/description/

const int N = 1e3+10;
int matrix[N][N];
int n,m, sr, sc, scolor, newcolor;

void dfs(int i, int j){
    if(i < 1 || i > n || j < 1 || j > m || matrix[i][j] != scolor)  return;
    matrix[i][j] = newcolor;
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    cin >> sr >> sc >> scolor >> newcolor;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> matrix[i][j];
            // matrix[i][j] denotes the initial color.
        }   
    }

    dfs(sr, sc);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout <<  matrix[i][j] << " ";
            // matrix[i][j] denotes the initial color.
        }   
        cout << '\n';
    }
    return 0;
}