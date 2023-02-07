#include <bits/stdc++.h> 
using namespace std;

int getMaxPathSumSpaceOptimization(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int ans = INT_MIN;
    vector<int> dp(n, 0), temp(n, 0);

    for(int i = 0; i < n; i++) dp[i] = matrix[0][i];

    for(int i = 1; i < m; i++){
        for(int j = 0; j < n; j++){
            int top = dp[j];
            int topRight = j + 1 < n ? dp[j + 1] : INT_MIN;
            int topLeft = j - 1 >= 0 ? dp[j - 1] : INT_MIN;

            temp[j] = max(top, max(topRight, topLeft)) + matrix[i][j];
        }
        dp = temp;
    }

    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);

    return ans;
}

int getMaxPathSumTabulation(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = INT_MIN;
    
    for(int i = 0; i < n; i++) dp[0][i] = matrix[0][i];

    for(int i = 1; i < m; i++){
        for(int j = 0; j < n; j++){
            int top = dp[i - 1][j];
            int topRight = j + 1 < n ? dp[i - 1][j + 1] : INT_MIN;
            int topLeft = j - 1 >= 0 ? dp[i - 1][j - 1] : INT_MIN;

            dp[i][j] = max(top, max(topRight, topLeft)) + matrix[i][j];
        }
    }

    for(int i = 0; i < n; i++) ans = max(ans, dp[m - 1][i]);
    
    return ans;
}

int getMaxPathSumMemoizationHelper(vector<vector<int>> &matrix, vector<vector<int>> &dp, int m, int n){
    if(n < 0 || n >= matrix[0].size()) return INT_MIN;

    if(m == 0) return matrix[0][n];

    if(dp[m][n] != -1) return dp[m][n];

    int t = getMaxPathSumMemoizationHelper(matrix, dp, m - 1, n);
    int tr = getMaxPathSumMemoizationHelper(matrix, dp, m - 1, n - 1);
    int tl = getMaxPathSumMemoizationHelper(matrix, dp, m - 1, n + 1);

    return dp[m][n] = max(t, max(tl, tr)) + matrix[m][n];
}

int getMaxPathSumMemoization(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        ans = max(ans, getMaxPathSumMemoizationHelper(matrix, dp, m - 1, i));
    }
    return ans;
}

int main(){
    int m, n;
    cin>>m>>n;

    vector<vector<int>> matrix(m, vector<int>(n,0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>matrix[i][j];
        }
    }

    cout<<"Memoization --> "<<getMaxPathSumMemoization(matrix)<<"\n";

    cout<<"Tabulation --> "<<getMaxPathSumTabulation(matrix)<<"\n";

    cout<<"Space Optimization --> "<<getMaxPathSumSpaceOptimization(matrix)<<"\n";

    return 0;
}