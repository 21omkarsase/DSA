// Find all possible paths from top to bottom
// EasyAccuracy: 77.56%Submissions: 6015Points: 2
// Given a N x M grid. Find All possible paths from top left to bottom right.From each cell you can either move only to right or down.

// Example 1:

// Input: 1 2 3
//        4 5 6
// Output: 1 4 5 6
//         1 2 5 6
//         1 2 3 6
// Explanation: We can see that there are 3
// paths from the cell (0,0) to (1,2).
// Example 2:

// Input: 1 2
//        3 4
// Output: 1 2 4
//         1 3 4
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findAllPossiblePaths() which takes two integers n,m and grid[][]  as input parameters and returns all possible paths from the top left cell to bottom right cell in a 2d array.

// Expected Time Complexity: O(2^N*M)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= n,m <= 10
// 1 <= grid[i][j] <= n*m
// n * m < 20

// View Bookmarked Problems
// Topic Tags
// BacktrackingMatrix

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void generateSolution(vector<vector<int>> &v, int row, int col, int n, int m, vector<vector<int>> &grid, vector<int> &vec)
    {
        if (row == n - 1 and col == m - 1)
        {
            vec.push_back(grid[row][col]);
            v.push_back(vec);
            vec.pop_back();
            return;
        }
        vec.push_back(grid[row][col]);
        if (row < n - 1)
        {
            generateSolution(v, row + 1, col, n, m, grid, vec);
        }
        if (col < m - 1)
        {
            generateSolution(v, row, col + 1, n, m, grid, vec);
        }
        vec.pop_back();
    }

    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> v;
        vector<int> vec;
        generateSolution(v, 0, 0, n, m, grid, vec);
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution ob;
    auto ans = ob.findAllPossiblePaths(n, m, grid);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    // }
    return 0;
}

// } Driver Code Ends