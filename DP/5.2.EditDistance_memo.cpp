#include<bits/stdc++.h>
using namespace std;

const int mx = 1e3;
int dp[mx][mx];

int ED(int i, int j, string a, string b){
    if(i == a.size() || j == b.size())  return max(a.size() - i, b.size() - j);
    else if(dp[i][j] != -1) return dp[i][j];
    else if(a[j] == b[i])   return dp[i][j] = ED(i + 1, j + 1, a, b);
    else return dp[i][j] = 1 + min({ED(i, j + 1, a, b), ED(i + 1, j, a, b), ED(i + 1, j + 1, a, b)});
}

int main(){
    int n, m;
    string a, b, res = "";
    getline(cin, a), getline(cin, b);
    n = b.size(), m = a.size();
    
    for(int i = 0 ; i < mx ; i++){
        for(int j = 0 ; j < mx ; j++){
            dp[i][j] = -1;
        }
    }
    int min_changes = ED(0, 0, a, b);
    
    cout << "Memorisation Table: \n";
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            cout << dp[i][j] << " " ;
        }
        cout << '\n';
    }

    cout << "\nOperations: \n";
    int i = 0, j = 0;
    while(i < n || j < m){
        if(a[j] == b[i]){
            res += b[i], i++, j++;
        }else{
            if(dp[i][j] == 1 + dp[i + 1][j + 1]){
                cout << "Swap : " << a[j] << " <--> " << b[i] << '\n';
                res += b[i];
                i++, j++;
            }else if(dp[i][j] == 1 + dp[i][j + 1] || j < m){
                cout << "Delete : " << a[j] << '\n';
                j++;
            }else if(dp[i][j] == 1 + dp[i + 1][j] || i < n){
                cout << "Insert : " << b[i] << '\n';
                res += b[i], i++;
            }
        }
    }   
    cout << "Final : " << res;
}