#include<bits/stdc++.h>
using namespace std;


int uniquePathsMemoizationHelper(vector<vector<int>> &grid, vector<vector<int>> &dp, int m, int n){
    
    if(m >= 0 && n >= 0 && grid[m][n] == -1) return 0;

    if(m == 0 && n == 0)return 1;

    if(m < 0 || n < 0) return 0;

    if(dp[m][n] != -1) return dp[m][n];

    int left = uniquePathsMemoizationHelper(grid, dp, m - 1, n);
    int up = uniquePathsMemoizationHelper(grid, dp, m, n - 1);

    return dp[m][n] = left + up;
}
int uniquePathsMemoization(vector<vector<int>> &grid) {
    vector<vector<int>>dp (grid.size(), vector<int>(grid[0].size(), -1));
    return uniquePathsMemoizationHelper(grid, dp, grid.size() - 1, grid[0].size() - 1);
}

int uniquePathRecursionHelper(vector<vector<int>>& grid, int m, int n){

    if(m >= 0 && n >= 0 && grid[m][n] == -1) return 0;

    if(m == 0 && n == 0)return 1;

    if(n < 0 || m < 0) return 0;
    int right = uniquePathRecursionHelper(grid, m - 1, n);
    int down =  uniquePathRecursionHelper(grid, m, n - 1);

    return right + down;
}
int uniquePathsRecursion(vector<vector<int>>& grid) {
    return uniquePathRecursionHelper(grid, grid.size() - 1, grid[0].size() - 1);
}



int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>grid[i][j];
        }
    }

    cout<<"uniquePaths : Recursion count --> "<<uniquePathsRecursion(grid)<<"\n";
    
    cout<<"uniquePaths : Memoization count --> "<<uniquePathsMemoization(grid)<<"\n";
}