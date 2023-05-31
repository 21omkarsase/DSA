// 1162. As Far from Land as Possible
// Medium
// 3.9K
// 101
// Companies

// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

 

// Example 1:

// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

// Example 2:

// Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
// Output: 4
// Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.

 

// Constraints:

//     n == grid.length
//     n == grid[i].length
//     1 <= n <= 100
//     grid[i][j] is 0 or 1

// Accepted
// 139K
// Submissions
// 268.1K
// Acceptance Rate
// 51.8%

// *************************************TLE*****************************
class Solution {
    int calDist(int x1, int y1, int x2, int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int distance = -1;
        vector<vector<int>> dp(n, vector<int>(m, -1)); 
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0 && dp[i][j] == -1){ 
                    queue<pair<int, int>> q;
                    vector<vector<bool>> vis(n, vector<bool>(m, 0));
                    
                    q.push({i, j});
                    int ogRow = i, ogCol = j;
                    bool mainFlag = true;
                    int minDistance = INT_MAX;
                    
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        vis[x][y] = 1;
                        
                        for(int row = -1; row <= 1; row++){
                            for(int col = -1; col <= 1; col++){
                                int nrow = row + x, ncol = col + y;
                                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol]){
                                    if(grid[nrow][ncol] == 1){
                                        int dist = calDist(ogRow, ogCol, nrow, ncol);
                                        mainFlag = false;
                                        minDistance = min(minDistance, dist);
                                    }
                                    if(mainFlag) q.push({nrow, ncol});
                                }
                            }
                        }
                    }
                    
                    if(!mainFlag)
                        distance = max(distance, minDistance);
                    
                    dp[i][j] = minDistance; 
                }
            }
        }

        return distance;
    }
};

// *************************USING multi bfs and reverse approach****************************
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int distance = -1;
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            distance++;
            for(int x = 0; x < size; x++){
                int row = q.front().first, col = q.front().second;
                q.pop();
                for(int i = -1; i <= 1; i++){
                    for(int j = -1; j <= 1; j++){
                        if(abs(i) != abs(j)){
                            int nrow = row + i, ncol = col + j;
                            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 0){
                                q.push({nrow, ncol});
                                grid[nrow][ncol] = 1;
                                flag = false;
                            }
                        }
                    }
                }
            }
        }

        return flag ? -1 : distance;
    }
};






