#include <bits/stdc++.h> 
using namespace std;

int longestPalindromeSubseqSpaceOptimization(string s) {
    string rs = s;
    reverse(rs.begin(), rs.end());
    int n = s.size();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i - 1] == rs[j - 1]) curr[j] = prev[j - 1] + 1;
            else curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    return prev[n];
}

int longestPalindromeSubseqTabulation(string s) {
    string rs = s;
    reverse(rs.begin(), rs.end());
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i - 1] == rs[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}

int lpsMemoization(string s1, string s2, vector<vector<int>> &dp, int n, int m){
    if(n == 0 || m == 0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n - 1] == s2[m - 1]) return dp[n][m] = lpsMemoization(s1, s2, dp, n - 1, m - 1) + 1;

    return dp[n][m] = max(lpsMemoization(s1, s2, dp, n - 1, m), lpsMemoization(s1, s2, dp, n, m - 1));
}
int longestPalinSubseqMemoization(string s) {
    string rs = s;
    reverse(rs.begin(), rs.end());
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return lpsMemoization(s, rs, dp, n, n);
}


int main(){
    string s;
    cin>> s;

    cout<<"Memoization--> "<<longestPalinSubseqMemoization(s)<<"\n";

    cout<<"Tabulation --> "<<longestPalindromeSubseqTabulation(s)<<"\n";

    cout<<"Space Optimization --> "<<longestPalindromeSubseqSpaceOptimization(s)<<"\n";

    return 0;
}