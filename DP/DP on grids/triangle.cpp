#include<bits/stdc++.h>
using namespace std;

int x = 0, y = 0;

int minimumTotalSpaceOptimization(vector<vector<int>>& triangle){
    int m = triangle.size(), n = triangle[0].size();
    vector<int>dp(1, triangle[0][0]);

    for(int i = 1; i < m; i++){
        vector<int> temp(i + 1, 0);
        for(int j = 0; j < i + 1; j++){
            int cost = 0;
            if(j - 1 >= 0 && j < i) cost = min(dp[j], dp[j - 1]);
            else if(j == 0) cost = dp[j];
            else cost = dp[j - 1];
            temp[j] = cost + triangle[i][j]; 
        }
        dp = temp;
    }

    int ans = INT_MAX;
    for(int i = 0; i < dp.size(); i++){
        ans = min(ans, dp[i]);
    }

    return ans;
}

//Tabulation Start
// Time complexity -->    Space complexity --> o(n) recursion stack space i.e number of rows
int minimumTotalTabulation(vector<vector<int>>& triangle) {
    int m = triangle.size(), n = triangle[0].size();
    vector<vector<int>> dp(m, vector<int>());
    for(int i = 0; i < m ; i++){
        vector<int>v(i + 1, INT_MIN);
        dp[i] = v;
    }
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < m; i++){
        for(int j = 0; j < i + 1; j++){
            int cost = 0;
            if(j - 1 >= 0 && j < i) cost = min(dp[i - 1][j], dp[i - 1][j - 1]);
            else if(j == 0) cost = dp[i - 1][j];
            else cost = dp[i - 1][j - 1];
            dp[i][j] = cost + triangle[i][j];
        }
    }

    int ans = INT_MAX;
    for(int i = 0; i < m; i++){
        ans = min(ans, dp[m - 1][i]);
    }

    return ans;
}
//Tabulation end

//Memoization Start
// Time complexity --> o(m * n)   Space complexity --> o(n) o(m * n) recursion stack space i.e number of rows
int minimumPathMemoizationHelper(vector<vector<int>>& triangle, vector<vector<int>>& dp , int r, int c, int m, int n){
    x++;
    if(r > m || c > n) return 0;
    if(r == m && c == n) return triangle[r][c];
    

    if(dp[r][c] != INT_MIN) return dp[r][c];
    int down = minimumPathMemoizationHelper(triangle, dp, r + 1, c, m, n + 1);
    int downRight = minimumPathMemoizationHelper(triangle, dp, r + 1, c + 1, m, n + 1);
    
    int cost = 0;
    if(c + 1 > n + 1) cost = down;
    else cost = min(down, downRight);

    return dp[r][c] = cost + triangle[r][c];
}
int minimumTotalMemoization(vector<vector<int>>& triangle) {
    int m = triangle.size(), n = triangle[0].size();
    vector<vector<int>> dp(m, vector<int>());
    for(int i = 0; i < m ; i++){
        vector<int>v(i + 1, INT_MIN);
        dp[i] = v;
    }

    return minimumPathMemoizationHelper(triangle, dp, 0, 0, m - 1, 0);
}
//Memoization end


//Recursion Start
// Time complexity --> 2 ^ (1 + 2 + ... + n)   Space complexity --> o(n) recursion stack space i.e number of rows
int minimumPathRecursionHelper(vector<vector<int>>& triangle, int r, int c, int m, int n){
    y++;
    if(r > m || c > n) return 0;
    if(r == m && c == n) return triangle[r][c];

    int down = minimumPathRecursionHelper(triangle, r + 1, c, m, n + 1);
    int downRight = minimumPathRecursionHelper(triangle, r + 1, c + 1, m, n + 1);
    
    int cost = 0;
    if(c + 1 > n + 1) cost = down;
    else cost = min(down, downRight);

    return cost + triangle[r][c];
}
int minimumTotalRecursion(vector<vector<int>>& triangle) {
    int m = triangle.size(), n = triangle[0].size();
    return minimumPathRecursionHelper(triangle, 0, 0, m - 1, 0);
}
//Recursion end

int main(){
    int n;cin>>n;
    vector<vector<int>> triangle;
    for(int i = 0; i < n; i++){
        vector<int>v(i+1,0);
        for(int j = 0; j < i + 1; j++){
            cin>>v[j];
        }
        triangle.push_back(v);
    }

   cout<<"Minimum path cost : Recursion --> "<<minimumTotalRecursion(triangle)<<"\n";
   cout<<"Minimum path cost : Memoization --> "<<minimumTotalMemoization(triangle)<<"\n";
   cout<<"Minimum path cost : Memoization --> "<<minimumTotalTabulation(triangle)<<"\n";
   cout<<"Minimum path cost : Space Optimization --> "<<minimumTotalSpaceOptimization(triangle)<<"\n";
    
   cout<<x<<" : "<<y<<"\n";
   return 0;
}