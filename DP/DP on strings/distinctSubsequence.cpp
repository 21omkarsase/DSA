#include<bits/stdc++.h>
using namespace std;



int numDistinctTabulation(string s, string t) {
    int n = s.size(), m = t.size(), mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i <= n; i++) dp[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod;
            else dp[i][j] = dp[i - 1][j] % mod;
        }
    }

    return dp[n][m];
}


int numDistinctHelperMemoization(string s, string t, vector<vector<int>> &dp, int n, int m){
    if(m < 0) return 1;
    if(n < 0) return 0;
    
    if(dp[n][m] != -1) return dp[n][m];

    if(s[n] == t[m]) return dp[n][m] = numDistinctHelperMemoization(s, t , dp, n - 1, m - 1) + numDistinctHelperMemoization(s, t , dp, n - 1, m);

    return dp[n][m] = numDistinctHelperMemoization(s, t , dp, n - 1, m);
}

int numDistinctMemoization(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return numDistinctHelperMemoization(s, t , dp, n - 1, m - 1);
}


int main(){
    string s1, s2;
    cin>> s1 >> s2;

    cout<<"Memiozation --> "<<numDistinctMemoization(s1, s2)<<"\n";

    cout<<"Tabulation --> "<<numDistinctTabulation(s1, s2)<<"\n";

    return 0;
}