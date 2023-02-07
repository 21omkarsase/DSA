 #include<bits/stdc++.h>
 using namespace std;

//Space Optimization start
 int minPathSumSpaceOptimization(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    vector<int> prev(n, 0);
    for(int i = 0; i < n; i++){
        if(i == 0) prev[i] = grid[0][0];
        else prev[i] = prev[i - 1] + grid[0][i];
    }
    for(int i = 1; i < m; i++){
        vector<int> temp(n, 0);
        for(int j = 0; j < n; j++){
            int cost = 0;
            if(j - 1 < 0){
                cost = prev[j];
            }else  cost = min(prev[j], temp[j - 1]);

            temp[j] = cost + grid[i][j];
        }
        prev = temp;
    }

    return prev[n - 1];
}
//Space Optimization end

//Tabulation start
 int minPathSumTabulation(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>>dp (m, vector<int>(n, -1));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) dp[i][j] = grid[0][0];
            else{
                int cost = 0;
                if(i - 1 < 0){
                    cost = dp[i][j - 1];
                }
                else if(j - 1 < 0){
                    cost = dp[i - 1][j];
                }else  cost = min(dp[i - 1][j], dp[i][j - 1]);

                dp[i][j] = cost + grid[i][j];
            }
        }
    }

    return dp[m - 1][n - 1];
}
//Tabulation end

//Memoization start
int minPathSumMemoizationHelper(vector<vector<int>>& grid, vector<vector<int>>& dp, int m , int n){
    if(m == 0 && n == 0) return grid[m][n];

    if(m < 0 || n < 0) return 0;

    if(dp[m][n] != -1) return dp[m][n];

    int top = minPathSumMemoizationHelper(grid, dp, m - 1 , n);
    int left = minPathSumMemoizationHelper(grid, dp, m, n - 1);
    
    int sum = 0;

    if(m - 1 < 0) sum = left;
    else if(n - 1 < 0) sum = top;
    else  sum = min(top, left);

    return dp[m][n] = sum + grid[m][n];
}


int minPathSumMemoization(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>>dp (m, vector<int>(n, -1));
    return minPathSumMemoizationHelper(grid, dp, m - 1, n - 1);
}
//Memoization end

//Recursion start 
int minPathSumRecursionHelper(vector<vector<int>>& grid, int m , int n){
    if(m == 0 && n == 0) return grid[m][n];

    if(m < 0 || n < 0) return 0;

    int top = minPathSumRecursionHelper(grid, m - 1 , n);
    int left = minPathSumRecursionHelper(grid, m, n - 1);
    
    if(m - 1 < 0) return left + grid[m][n];
    if(n - 1 < 0) return top + grid[m][n];

    return min(top, left) + grid[m][n];
}

int minPathSumRecursion(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    return minPathSumRecursionHelper(grid, m - 1, n - 1);
}
//Recursion end



 int main(){
    int m, n;
    cin>>m>>n;

    vector<vector<int>>grid(m,vector<int>(n));
    for(int i = 0;i < m; i++)
        for(int j = 0; j < n; j++)
            cin>>grid[i][j];

    cout<<"minimum path sum (Recursion) --> "<<minPathSumRecursion(grid)<<"\n";

    cout<<"minimum path sum (Memoization) --> "<<minPathSumMemoization(grid)<<"\n";

    cout<<"minimum path sum (Tabulation) --> "<<minPathSumTabulation(grid)<<"\n";

    cout<<"minimum path sum (Space Optimization) --> "<<minPathSumSpaceOptimization(grid)<<"\n";

    return 0;
 }