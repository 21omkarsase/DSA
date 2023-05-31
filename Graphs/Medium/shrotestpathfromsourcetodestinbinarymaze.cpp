// Shortest Distance in a Binary Maze
// MediumAccuracy: 58.22%Submissions: 19K+Points: 4
// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation  

// Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

// If the path is not possible between source cell and destination cell, then return -1.

// Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right.

// Example 1:

// Input:
// grid[][] = {{1, 1, 1, 1},
//             {1, 1, 0, 1},
//             {1, 1, 1, 1},
//             {1, 1, 0, 0},
//             {1, 0, 0, 1}}
// source = {0, 1}
// destination = {2, 2}
// Output:
// 3
// Explanation:
// 1 1 1 1
// 1 1 0 1
// 1 1 1 1
// 1 1 0 0
// 1 0 0 1
// The highlighted part in the matrix denotes the 
// shortest path from source to destination cell.

// Example 2:

// Input:
// grid[][] = {{1, 1, 1, 1, 1},
//             {1, 1, 1, 1, 1},
//             {1, 1, 1, 1, 0},
//             {1, 0, 1, 0, 1}}
// source = {0, 0}
// destination = {3, 4}
// Output:
// -1
// Explanation:
// The path is not possible between source and 
// destination, hence return -1.

// Your Task:

// You don't need to read or print anything. Your task is to complete the function shortestPath() which takes the a 2D integer array grid, source cell and destination cell as an input parameters and returns the shortest distance between source and destination cell.

// Expected Time Complexity: O(n * m)
// Expected Space Complexity: O(n * m)

// Constraints:

//     1 ≤ n, m ≤ 500
//     grid[i][j] == 0 or grid[i][j] == 1
//     The source and destination cells are always inside the given matrix.
//     The source and destination cells always contain 1.


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[source.first][source.second]=0;
        q.push({0,{source.first,source.second}});
        
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        
        while(!q.empty()){
            auto it=q.front();
            int len=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            q.pop();
            
            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                
                if(newr>=0 && newr<n && newc>=0 && newc<m && dist[newr][newc]>len+1 && grid[newr][newc]==1){
                    dist[newr][newc]=len+1;
                    if(newr==destination.first && newc==destination.second){
                        return len+1;
                    }
                    q.push({len+1,{newr,newc}});
                }
            }
        }
        if(source.first==destination.first && source.second==destination.second) 
            return 0; 

        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
