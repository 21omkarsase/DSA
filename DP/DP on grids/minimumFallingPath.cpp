#include <bits/stdc++.h> 
using namespace std;

int minFallingPathSumSpaceOptimization(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int ans = INT_MAX;
    vector<int> dp(n, 0), temp(n, 0);

    for(int i = 0; i < n; i++) dp[i] = matrix[0][i];

    for(int i = 1; i < m; i++){
        for(int j = 0; j < n; j++){
            int top = dp[j];
            int topRight = j + 1 < n ? dp[j + 1] : INT_MAX;
            int topLeft = j - 1 >= 0 ? dp[j - 1] : INT_MAX;

            temp[j] = min(top, min(topRight, topLeft)) + matrix[i][j];
        }
        dp = temp;
    }

    for(int i = 0; i < n; i++) ans = min(ans, dp[i]);

    return ans;
}

int minFallingPathSumTabulation(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = INT_MAX;
    
    for(int i = 0; i < n; i++) dp[0][i] = matrix[0][i];


    for(int i = 1; i < m; i++){
        for(int j = 0; j < n; j++){
            int top = dp[i - 1][j];
            int topRight = j + 1 < n ? dp[i - 1][j + 1] : INT_MAX;
            int topLeft = j - 1 >= 0 ? dp[i - 1][j - 1] : INT_MAX;

            dp[i][j] = min(top, min(topRight, topLeft)) + matrix[i][j];
        }
    }

    for(int i = 0; i < n; i++) ans = min(ans, dp[m - 1][i]);

    return ans;
}

int getMaxPathMemoizationHelper(vector<vector<int>> &matrix, vector<vector<int>> &dp, int m, int n){
    if(n < 0 || n > (matrix[0].size() - 1)) return INT_MAX;
    
    if(m == 0) return matrix[0][n];

    if(dp[m][n] != -1) return dp[m][n];

    int top = getMaxPathMemoizationHelper(matrix, dp, m - 1, n);
    int topRight = getMaxPathMemoizationHelper(matrix, dp, m - 1, n + 1);
    int topLeft = getMaxPathMemoizationHelper(matrix, dp, m - 1, n - 1);

    return dp[m][n] = min(top, min(topRight, topLeft)) + matrix[m][n];
}

int minFallingPathSumMemoization(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        ans = min(ans, getMaxPathMemoizationHelper(matrix, dp, m - 1, i));
    }
    return ans;
}


int getMaxPathRecursionHelper(vector<vector<int>> &matrix, vector<vector<int>> &dp, int m, int n){
    if(n < 0 || n > (matrix[0].size() - 1)) return INT_MAX;
    
    if(m == 0) return matrix[0][n];

    if(dp[m][n] != -1) return dp[m][n];

    int top = getMaxPathRecursionHelper(matrix, dp, m - 1, n);
    int topRight = getMaxPathRecursionHelper(matrix, dp, m - 1, n + 1);
    int topLeft = getMaxPathRecursionHelper(matrix, dp, m - 1, n - 1);

    return dp[m][n] = min(top, min(topRight, topLeft)) + matrix[m][n];
}

int minFallingPathSumRecursion(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        ans = min(ans, getMaxPathMemoizationHelper(matrix, dp, m - 1, i));
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

    cout<<"Recursion --> "<<minFallingPathSumRecursion(matrix)<<"\n";

    cout<<"Memoization --> "<<minFallingPathSumMemoization(matrix)<<"\n";

    cout<<"Tabulation --> "<<minFallingPathSumTabulation(matrix)<<"\n";

    cout<<"Space Optimization --> "<<minFallingPathSumSpaceOptimization(matrix)<<"\n";


    return 0;
}