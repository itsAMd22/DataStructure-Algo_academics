#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    
    string in, fin, res = "";
    getline(cin, in), getline(cin, fin);
    n = (int) fin.size(), m = (int) in.size();

    in = '\0' + in, fin = '\0' + fin;

    int dp[n + 1][m + 1];

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if(i == 0 || j == 0){
                dp[i][j] = max(i, j);
            }else if(fin[i] == in[j]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    
    cout << "DP Table:\n";
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }

    cout << "\nMinimum operations = " << dp[n][m] << "\n\n";

    if(dp[n][m] > 0){
        cout << "Operations: \n";
    }
    int i = n, j = m;
    
    while(i >= 0 || j >= 0){
        if(fin[i] == in[j]){
            res = fin[i] + res;
            i--, j--;
        }else{
            if(dp[i][j] == 1 + dp[i][j - 1] || i == 0){
                // delete
                cout << "delete -> " << in[j] << '\n';
                j--;
            }else if(dp[i][j] == 1 + dp[i - 1][j - 1]){
                // swap
                cout << "swap -> " << in[j] << " <<->> " << fin[i] << '\n';
                res = fin[i] + res;
                i--, j--;
            }else{
                // insert
                cout << "insert -> " << fin[i] << '\n';
                res = fin[i] + res;
                i--;
            }
        } 
    }

    cout << "\nResult = " << res << '\n';
    return 0;

}
