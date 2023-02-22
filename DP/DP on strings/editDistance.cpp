#include<bits/stdc++.h>
using namespace std;

int minDistanceSpaceOptimization(string a, string b)
{
    int n = a.size(), m = b.size();
    
    if(n == 0 && m == 0) return 0;
    else if(n == 0) return m;
    else if(m == 0) return n; 

    vector<int> prev(m + 1 , 0), curr(m + 1, 0);
    
    for(int j = 0; j <= m; j++) prev[j] = j;

    for(int i = 1; i <= n; i++){
        curr[0] = i;
        for(int j = 1; j <= m; j++){
            if(a[i - 1] == b[j - 1]) curr[j] = prev[j - 1];
            else curr[j] =  1 + min(curr[j - 1], min(prev[j], prev[j- 1]));
        }
        prev = curr;
    }

    return prev[m];
}

int minDistanceTabulation(string a, string b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>>dp (n + 1, vector<int>(m + 1 , 0));
    
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] =  1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j- 1]));
        }
    }

    return dp[n][m];
}

int helperMemoization(string &a, string &b, vector<vector<int>> &dp, int n, int m){
    if(n == 0) return m;
    if(m == 0) return n;
    
    if(dp[n][m] != -1) return dp[n][m];

    if(a[n - 1] == b[m - 1]){
        return helperMemoization(a, b, dp, n - 1, m - 1);
    }

   return 1 + min(helperMemoization(a, b, dp, n, m - 1), min(helperMemoization(a, b, dp, n - 1, m), helperMemoization(a,b, dp, n - 1, m - 1)));
}

int editDistanceMemoization(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<int>>dp (n + 1, vector<int>(m + 1 , -1));
    return helperMemoization(str1, str2, dp, n, m);
}


int main(){
    string s1, s2;
    cin>> s1 >> s2;

    cout<<"Memiozation --> "<<editDistanceMemoization(s1, s2)<<"\n";

    cout<<"Tabulation --> "<<minDistanceTabulation(s1, s2)<<"\n";

    cout<<"Space Optimization --> "<<minDistanceSpaceOptimization(s1, s2)<<"\n";

    return 0;
}