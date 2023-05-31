// Number of Distinct Islands
// MediumAccuracy: 62.29%Submissions: 34K+Points: 4
// Last Week Of Job Fair 2023. Explore Unlimited Opportunities Now!

// Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

// Example 1:

// Input:
// grid[][] = {{1, 1, 0, 0, 0},
//             {1, 1, 0, 0, 0},
//             {0, 0, 0, 1, 1},
//             {0, 0, 0, 1, 1}}
// Output:
// 1
// Explanation:
// grid[][] = {{1, 1, 0, 0, 0}, 
//             {1, 1, 0, 0, 0}, 
//             {0, 0, 0, 1, 1}, 
//             {0, 0, 0, 1, 1}}
// Same colored islands are equal.
// We have 2 equal islands, so we 
// have only 1 distinct island.

// Example 2:

// Input:
// grid[][] = {{1, 1, 0, 1, 1},
//             {1, 0, 0, 0, 0},
//             {0, 0, 0, 0, 1},
//             {1, 1, 0, 1, 1}}
// Output:
// 3
// Explanation:
// grid[][] = {{1, 1, 0, 1, 1}, 
//             {1, 0, 0, 0, 0}, 
//             {0, 0, 0, 0, 1}, 
//             {1, 1, 0, 1, 1}}
// Same colored islands are equal.
// We have 4 islands, but 2 of them
// are equal, So we have 3 distinct islands.

// Your Task:

// You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

// Expected Time Complexity: O(n * m)
// Expected Space Complexity: O(n * m)

// Constraints:
// 1 ≤ n, m ≤ 500
// grid[i][j] == 0 or grid[i][j] == 1


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, vector<pair<int, int>>& island) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            island.push_back({r - row, c - col});

            for (const auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
    }

    string getIslandString(const vector<pair<int, int>>& island) {
        string islandStr;
        for (const auto& p : island) {
            islandStr += to_string(p.first) + to_string(p.second);
        }
        return islandStr;
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        unordered_set<string> distIslands;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> island;
                    bfs(grid, vis, i, j, island);
                    string islandStr = getIslandString(island);
                    distIslands.insert(islandStr);
                }
            }
        }

        return distIslands.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends