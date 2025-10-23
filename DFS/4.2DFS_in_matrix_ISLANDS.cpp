#include<bits/stdc++.h>
using namespace std;


// leetcode : https://leetcode.com/problems/number-of-islands/description/

const int N = 1e3+10;
int grid[N][N];
bool visited[N][N];
int n,m, ct = 0;


void dfs(int i, int j){
    if(i < 1 || i > n || j < 1 || j > m || grid[i][j] == 0 || visited[i][j]) return;
    cout << i << " " << j << endl;
    visited[i][j] = true;
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}

void count_islands(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                cout << "start ---->>>>> " << i << " " << j << endl;
                ct++;
                dfs(i, j);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> grid[i][j];
            visited[i][j] = 0;
        }
    }

    count_islands();
    cout << "Number of island = " << ct << endl;
    return 0;
}