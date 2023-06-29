// 994. Rotting Oranges
// Medium
// 10.8K
// 348
// Companies

// You are given an m x n grid where each cell can have one of three values:

//     0 representing an empty cell,
//     1 representing a fresh orange, or
//     2 representing a rotten orange.

// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

 

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 10
//     grid[i][j] is 0, 1, or 2.

// Accepted
// 622.2K
// Submissions
// 1.2M
// Acceptance Rate
// 53.2%

// Time Complexity : O(N * M)
// Space Complexity : O(N * M) 

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        queue<pair<int, pair<int, int>>> rottenQueue;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 2) {
                    rottenQueue.push({0, {row, col}});
                    visited[row][col] = 1;
                }
                
                if (grid[row][col] == 0)
                    visited[row][col] = 1;
            }
        }

        int time = 0;

        while (!rottenQueue.empty()) {
            int qSize = rottenQueue.size();

            while (qSize--) {

                int row = rottenQueue.front().second.first;
                int col = rottenQueue.front().second.second;
                int t = rottenQueue.front().first;
                
                time = max(time, t);

                rottenQueue.pop();

                for (int idx1 = -1; idx1 < 2; idx1++) {
                    for (int idx2 = -1; idx2 < 2; idx2++) {
                        if (abs(idx1) != abs(idx2)) {
                            int nRow = row + idx1, nCol = col + idx2;

                            if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && grid[nRow][nCol] == 1 && visited[nRow][nCol] == 0) {
                                visited[nRow][nCol] = 1;
                                rottenQueue.push({t + 1, {nRow, nCol}});
                            }
                        }
                    }
                }
            }
        }

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1 && visited[row][col] == 0) 
                    return -1;
            }
        }

        return time;
    }
};











