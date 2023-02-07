#include <bits/stdc++.h> 
using namespace std;


int maximumChocolatesSpaceOptimization(int n, int m, vector<vector<int>> &grid) {
    // Time Complexity: O(N*M*M)*9
    // Space Complexity: O(M*M)

    vector<vector<int>>prev (m, vector<int>(m, 0)), temp (m, vector<int>(m, 0));

    for(int j1 = 0; j1 < m; j1++){
        for(int j2 = 0; j2 < m; j2++){
           if(j1 == j2) prev[j1][j2] = grid[n - 1][j1];
           else prev[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                int cost = -1e8;
                for(int it1 = -1; it1 <= 1; it1++){
                    for(int it2 = -1; it2 <= 1; it2++){
                        int value = 0;
                        if(j1 == j2){
                            value = grid[i][j2];
                        }else{
                            value = grid[i][j1] + grid[i][j2];
                        }
                        if(j1 + it1 >= 0 && j1 + it1 < m && j2 + it2 >= 0 && j2 + it2 < m)
                            value += prev[j1 + it1][j2 + it2];
                        else value += (-1e8);

                        cost = max(cost, value);
                    }  
                }
                temp[j1][j2] = cost;
            }
        }
        prev = temp;
    }
    return prev[0][m - 1];
}

int maximumChocolatesTabulation(int n, int m, vector<vector<int>> &grid) {
    // Time Complexity: O(N*M*M)*9
    // Space Complexity: O(N*M*M)

    vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for(int j1 = 0; j1 < m; j1++){
        for(int j2 = 0; j2 < m; j2++){
           if(j1 == j2) dp[n - 1][j1][j2] = grid[n - 1][j1];
           else dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                int cost = -1e8;
                for(int it1 = -1; it1 <= 1; it1++){
                    for(int it2 = -1; it2 <= 1; it2++){
                        int value = 0;
                        if(j1 == j2){
                            value = grid[i][j2];
                        }else{
                            value = grid[i][j1] + grid[i][j2];
                        }
                        if(j1 + it1 >= 0 && j1 + it1 < m && j2 + it2 >= 0 && j2 + it2 < m)
                            value += dp[i + 1][j1 + it1][j2 + it2];
                        else value += (-1e8);

                        cost = max(cost, value);
                    }  
                }
                dp[i][j1][j2] = cost;
            }
        }
    }
    return dp[0][0][m - 1];
}

int maxChocMemoizationHelper(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int r, int c1, int c2, int m, int n){
    if((c1 < 0 || c1 > n) || (c2 < 0 || c2 > n)) return -1e8;

    if(r == m && c1 != c2) return grid[r][c1] + grid[r][c2];
    else if(r == m && c1 == c2) return grid[r][c1];
    
    if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
    int cost = -1e8;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            cost = max(cost, maxChocMemoizationHelper(grid, dp, r + 1, c1 + i, c2 + j, m, n));
        }
    }

    if(c1 != c2) return dp[r][c1][c2] = cost + grid[r][c1] + grid[r][c2] ; 
    
    return dp[r][c1][c2] = cost + grid[r][c1];
}

int maximumChocolatesMemoization(int r, int c, vector<vector<int>> &grid) {
   // Time Complexity: O(N*M*M) * 9
    // Space Complexity: O(N) + O(N*M*M)

    int m = grid.size(), n = grid[0].size();
    vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    return maxChocMemoizationHelper(grid, dp, 0, 0, n - 1, m - 1, n - 1);
}

int maxChocRecursionHelper(vector<vector<int>> &grid, int r, int c1, int c2, int m, int n){
    if((c1 < 0 || c1 > n) || (c2 < 0 || c2 > n)) return INT_MIN;

    if(r == m && c1 != c2) return grid[r][c1] + grid[r][c2];
    else if(r == m && c1 == c2) return grid[r][c1];

    int cost = INT_MIN;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int x = maxChocRecursionHelper(grid,r + 1, c1 + i, c2 + j, m, n);
            cost = max(cost, x);
        }
    }
    if(c1 != c2) return cost + grid[r][c1] + grid[r][c2] ; 

    return cost + grid[r][c1];
}

int maximumChocolatesRecursion(int r, int c, vector<vector<int>> &grid) {
    // Time Complexity: O(3^N * 3^N)
    // Space Complexity: O(N) + O(N*M*M)
    int m = grid.size(), n = grid[0].size();
    return maxChocRecursionHelper(grid, 0, 0, n - 1, m - 1, n - 1);
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

    cout<<"Recursion --> "<<maximumChocolatesRecursion(m, n, matrix)<<"\n";

    cout<<"Memoization --> "<<maximumChocolatesMemoization(m, n, matrix)<<"\n";

    cout<<"Tabulation --> "<<maximumChocolatesTabulation(m, n, matrix)<<"\n";

    cout<<"Space Optimization --> "<<maximumChocolatesSpaceOptimization(m, n, matrix)<<"\n";
    return 0;
}