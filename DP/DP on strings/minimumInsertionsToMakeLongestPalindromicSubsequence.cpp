#include <bits/stdc++.h> 
using namespace std;

int minInsertionsSpaceOptimization(string s) {
    int n = s.size();
    string rs = s;
    reverse(rs.begin(), rs.end());
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i - 1] == rs[j - 1]) curr[j] = prev[j - 1] + 1;
            else curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    return n - prev[n];
}

int minInsertionsTabulation(string s) {
    int n = s.size();
    string rs = s;
    reverse(rs.begin(), rs.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i - 1] == rs[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return n - dp[n][n];
}

int lcsMemoization(string s1, string s2, vector<vector<int>> &dp, int n, int m){
    if(n == 0 || m == 0) return 0;
    
    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n - 1] == s2[m - 1]) return dp[n][m] = 1 + lcsMemoization(s1, s2, dp, n - 1, m - 1);

    return dp[n][m] = max(lcsMemoization(s1, s2, dp, n - 1, m), lcsMemoization(s1, s2, dp, n, m - 1));
}
int minInsertionsMemoization(string s) {
    int n = s.size();
    string rs = s;
    reverse(rs.begin(), rs.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return n - lcsMemoization(s, rs, dp, n, n);
}

int main(){
    string s;
    cin>> s;

    cout<<"Memoization--> "<<minInsertionsMemoization(s)<<"\n";

    cout<<"Tabulation --> "<<minInsertionsTabulation(s)<<"\n";

    cout<<"Space Optimization --> "<<minInsertionsSpaceOptimization(s)<<"\n";

    return 0;
}