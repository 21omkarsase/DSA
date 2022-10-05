// Queries on a Matrix
// HardAccuracy: 67.28%Submissions: 9388Points: 8
// You are given a matrix of dimension n*n. All the cells are initially, zero. You are given Q queries, which contains 4 integers a b c d where (a,b) is the TOP LEFT cell and (c,d) is the Bottom Right cell of a submatrix. Now, all the cells of this submatrix have to be incremented by one. After all the Q queries have been performed. Your task is to find the final resulting Matrix.
// Note : Zero-Based Indexing is used for cells of the matrix. 
 

// Example 1:

// Input: n = 6, q = 6,
// Queries = {
// {4,0,5,3},
// {0,0,3,4},
// {1,2,1,2},
// {1,1,2,3},
// {0,0,3,1},
// {1,0,2,4}}.
// Output: 
// 2 2 1 1 1 0
// 3 4 4 3 2 0 
// 3 4 3 3 2 0
// 2 2 1 1 1 0
// 1 1 1 1 0 0
// 1 1 1 1 0 0
// Explanation:After incrementing all the
// sub-matrices of given queries we will 
// get the final output.

 

 

// Example 2:

// Input: n = 4, q = 2,
// Queries = {
// {0,0,3,3},
// {0,0,2,2}}.
// Output: 
// 2 2 2 1 
// 2 2 2 1  
// 2 2 2 1 
// 1 1 1 1 
// Explanation:After incrementing all the
// sub-matrices of given queries we will
// get the final output.
// Your Task:
// You don't need to read or print anything. Your task is to complete the function solveQueries() which takes n and Queries and input parameter and returns a matrix after performing all the queries.
 

// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(n2)
 

// Constraints:
// 1 <= n <= 1000
// 0 <= a <= c < n
// 0 <= b <= d < n
// 1 <= No. of Queries <= 1000

// View Bookmarked Problems 
// Topic Tags
// Dynamic ProgrammingMathematicalMatrix

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
       vector<vector<int>>ans(n,vector<int>(n,0));

       // for(int k=0;k<Queries.size();k++){
       //  for(int i=Queries[k][0];i<=Queries[k][2];i++){
       //      for(int j=Queries[k][1];j<=Queries[k][3];j++){
       //          ans[i][j]++;
       //      }
       //  }
       // }  //TLE


       for(int k=0;k<Queries.size();k++){
        for(int i=Queries[k][0];i<=Queries[k][2];i++){
           ans[i][Queries[k][1]]++;    //adding 1 to first col of every submatrix
           if(Queries[k][3]+1<n) 
            ans[i][Queries[k][3]+1]--;   //substracting one from every field of col next to last col if it exists
        }
       }
       

       for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            ans[i][j]+=ans[i][j-1];  //every cell val = val of that cell + val of prev cell
        }
       }



       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends