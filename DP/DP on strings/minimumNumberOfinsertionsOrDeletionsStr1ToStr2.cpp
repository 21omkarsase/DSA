#include <bits/stdc++.h> 
using namespace std;

int canYouMakeSpaceOptimization(string &str, string &ptr)
{
    int n = str.size(), m = ptr.size();
    
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str[i - 1] == ptr[j - 1])
                curr[j] = prev[j - 1] + 1;
            else curr[j] = max(prev[j],curr[j - 1]);
        }
        prev = curr;
    }
    
    return n + m - 2*prev[m];
}

int canYouMakeTabulation(string &str, string &ptr)
{
    int n = str.size(), m = ptr.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str[i - 1] == ptr[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    return n + m - 2*dp[n][m];
}

int lcsMemoization(string s1, string s2, vector<vector<int>> &dp, int n, int m){
    if(n == 0 || m == 0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n - 1] == s2[m - 1])
       return dp[n][m] = lcsMemoization(s1, s2, dp, n - 1, m - 1) + 1;
    
    return dp[n][m] = max(lcsMemoization(s1, s2, dp, n - 1, m), lcsMemoization(s1, s2, dp, n, m - 1));
}
int canYouMakeMemoization(string &str, string &ptr)
{
    int n = str.size(), m = ptr.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return n + m - 2*lcsMemoization(str, ptr, dp, n, m);
}

int main(){
    string s1, s2;
    cin>> s1 >> s2;

    cout<<"Memoization--> "<<canYouMakeMemoization(s1, s2)<<"\n";

    cout<<"Tabulation --> "<<canYouMakeTabulation(s1, s2)<<"\n";

    cout<<"Space Optimization --> "<<canYouMakeSpaceOptimization(s1, s2)<<"\n";

    return 0;
}