#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquareSpaceOptimization(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        int ans = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int up = prev[j];
                int left = curr[j - 1];
                int diagonal = prev[j - 1];

                if(matrix[i - 1][j - 1] == '1'){
                    int side = 1 + min(up, min(left, diagonal));
                    ans = max(ans, side);
                    curr[j] = side;
                }
                else curr[j] = 0;
            }
            prev = curr;
        }

        return ans * ans;
    }

    int maximalSquareTabulation(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int ans = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int up = dp[i - 1][j];
                int left = dp[i][j - 1];
                int diagonal = dp[i - 1][j - 1];

                if(matrix[i - 1][j - 1] == '1'){
                    int side = 1 + min(up, min(left, diagonal));
                    ans = max(ans, side);
                    dp[i][j] = side;
                }
                else dp[i][j] = 0;
            }
        }

        return ans * ans;
    }
    int msHelperMemoization(vector<vector<char>> &matrix, vector<vector<int>> &dp, int i, int j, int &ans){
        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int up = msHelperMemoization(matrix, dp, i - 1, j, ans);
        int left = msHelperMemoization(matrix, dp, i, j - 1, ans);
        int diagonal = msHelperMemoization(matrix, dp, i - 1, j - 1, ans);

        if(matrix[i][j] == '1'){
            int side = 1 + min(up, min(left, diagonal));
            ans = max(ans, side);
            return dp[i][j] = side;
        }

        return dp[i][j] = 0;
    }

    int maximalSquareMemoization(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;
        msHelperMemoization(matrix, dp, n - 1, m - 1, ans);
        return ans * ans;
    }
};


int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> matrix(n, vector<char>(m, '0'));
    for(auto &v : matrix)
        for(auto &e : v)
            cin >> e;

    Solution* s = new Solution();

    cout<<s->maximalSquareMemoization(matrix)<<"\n";

    cout<<s->maximalSquareTabulation(matrix)<<"\n";

    cout<<s->maximalSquareSpaceOptimization(matrix)<<"\n";

    return 0;
}