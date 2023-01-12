// Back to Explore Page

// Detect cycle in a directed graph

// Detect cycle in an undirected graph

// Find the number of islands

// Topological sort

// Minimum Swaps to Sort

// Bipartite Graph

// Implementing Dijkstra Algorithm

// Rotten Oranges

// Steps by Knight

// Floyd Warshall

// Word Boggle

// Minimum Spanning Tree

// Find whether path exist

// Flood fill Algorithm

// Shortest Source to Destination Path

// Unit Area of largest region of 1's

// Strongly Connected Components (Kosaraju's Algo)

// Negative weight cycle

// Snake and Ladder Problem

// Distance of nearest cell having 1
// Find the number of islands
// MediumAccuracy: 42.12%Submissions: 132K+Points: 4
// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation  

// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

// Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Example 1:

// Input:
// grid = {{0,1},{1,0},{1,1},{1,0}}
// Output:
// 1
// Explanation:
// The grid is-
// 0 1
// 1 0
// 1 1
// 1 0
// All lands are connected.

// Example 2:

// Input:
// grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
// Output:
// 2
// Expanation:
// The grid is-
// 0 1 1 1 0 0 0
// 0 0 1 1 0 1 0 
// There are two islands :- one is colored in blue 
// and other in orange.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as an input parameter and returns the total number of islands.

// Expected Time Complexity: O(n*m)
// Expected Space Complexity: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bfs(vector<vector<char>>grid,vector<vector<int>>&vis,int row,int col){
        vis[row][col]=1;
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            row=q.front().first;
            col=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=row+i, ncol=col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends