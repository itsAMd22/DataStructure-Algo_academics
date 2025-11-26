#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    
    string s1, s2, res = "";
    getline(cin, s1), getline(cin, s2);

    n = (int) s1.size(), m = (int) s2.size();

    s1 = '\0' + s1, s2 = '\0' + s2;

    int dp[n + 1][m + 1];
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else if(s1[i] == s2[j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // printing dp table
    cout << "DP Table:\n";
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }

    // abcdefghi
    // ecdgi

    // result
    cout << "\nmaximum similarity = " << dp[n][m] << endl;

    // using bottom-up approach
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(s1[i] == s2[j]){
            res = s1[i] + res;
            i--, j--;
        }else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }else{
            j--;
        }
    }
    cout << "LCS = " << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    cin.ignore();
    while(t--){
        solve();
    }
    return 0;
}