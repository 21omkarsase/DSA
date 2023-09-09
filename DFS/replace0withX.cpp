// Replace O's with X's
// MediumAccuracy: 34.0%Submissions: 69K+Points: 4

// Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' with 'X' that are surrounded by 'X'.

// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

// Example 1:

// Input: 
// n = 5, m = 4
// mat = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Output: 
// ans = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Explanation: 
// Following the rule the above matrix is the resultant matrix. 

// Example 2:

 

// Input: 
// n = 5, m = 4
// mat = {{'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Output: 
// ans = {{'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Explanation: 
// Following the rule the above matrix is the resultant matrix.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function fill() which takes N, M and mat as input parameters ad returns a 2D array representing the resultant matrix.

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500


// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

class Solution{
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    void dfs(int row, int col, const char &var, const int &n, const int &m, vector<vector<bool>> &visited, vector<vector<char>> &mat) {
        visited[row][col] = 1;
        mat[row][col] = var;
        
        for (auto dir : dirs) {
            int nrow = row + dir.first, ncol = col + dir.second;

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, var, n, m, visited, mat);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        const char var = 'A';
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if ((row == 0 || col == 0 || row == n - 1 || col == m - 1) && !visited[row][col] && mat[row][col] == 'O') {
                    dfs(row, col, var, n, m, visited, mat);
                }
            }
        }

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (mat[row][col] == 'O') {
                    mat[row][col] = 'X';
                }
                
                if (mat[row][col] == var) {
                    mat[row][col] = 'O';
                }
            }
        }
        
        return mat;
    }
};