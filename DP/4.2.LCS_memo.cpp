#include<bits/stdc++.h>
using namespace std;

const int mx = 1e3;
int memo[mx][mx];

int LCS(int i, int j, string s1, string s2){
    if(i == s1.size() || j == s2.size())    return 0;
    else if(memo[i][j] != -1) return memo[i][j];
    else if(s1[i] == s2[j]) return memo[i][j] = 1 + LCS(i + 1, j + 1, s1, s2);
    else    return memo[i][j] = max(LCS(i + 1, j, s1, s2), LCS(i, j + 1, s1, s2));
}

int main(){
    int n, m;
    string s1, s2, res = "";
    getline(cin, s1), getline(cin, s2);
    n = s1.size(), m = s2.size();

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            memo[i][j] = -1;
        }
    }

    int len = LCS(0, 0, s1, s2);
    int ct = len, i = 0, j = 0;
    
    cout << "Memorisation table\n";
    for(int i = 0 ; i <= n ; i++){ 
        for(int j = 0 ; j <= m ; j++){
            cout << memo[i][j] << " ";
        }
        cout << '\n';
    }

    while(ct > 0){
        if(s1[i] == s2[j])  res += s1[i], i++, j++, ct--;
        else if(memo[i + 1][j] > memo[i][j + 1])    i++;
        else    j++;
    }


    cout << "\nmaximum similarity = " << len << '\n';
    cout << "LCS = " << res << '\n';
    return 0;
}
