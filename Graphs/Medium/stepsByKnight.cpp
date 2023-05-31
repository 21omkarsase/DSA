// Back to Explore Page

// Detect cycle in a directed graph

// Detect cycle in an undirected graph

// BFS of graph

// DFS of Graph

// Find the number of islands

// Topological sort

// Minimum Swaps to Sort

// Bipartite Graph

// Implementing Dijkstra Algorithm

// Rotten Oranges

// Steps by Knight

// Floyd Warshall

// Print adjacency list

// Word Boggle

// Minimum Spanning Tree

// Flood fill Algorithm

// Find whether path exist

// Minimum Cost Path

// Shortest Source to Destination Path

// Unit Area of largest region of 1's
// Steps by Knight
// MediumAccuracy: 37.32%Submissions: 83K+Points: 4
// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation  

// Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

// Note:
// The initial and the target position coordinates of Knight have been given according to 1-base indexing.

 

// Example 1:

// Input:
// N=6
// knightPos[ ] = {4, 5}
// targetPos[ ] = {1, 1}
// Output:
// 3
// Explanation:

// Knight takes 3 step to reach from 
// (4, 5) to (1, 1):
// (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

 

 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the initial position of Knight (KnightPos), the target position of Knight (TargetPos), and the size of the chessboard (N) as input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position or return -1 if its not possible.

 

// Expected Time Complexity: O(N2).
// Expected Auxiliary Space: O(N2).

 

// Constraints:
// 1 <= N <= 1000
// 1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&start,vector<int>&end,int N)
	{
	    vector<pair<int,int>>loop;
	    loop.push_back({1,2});
	    loop.push_back({1,-2});
	    loop.push_back({-1,2});
	    loop.push_back({-1,-2});
	    loop.push_back({2,1});
	    loop.push_back({2,-1});
	    loop.push_back({-2,1});
	    loop.push_back({-2,-1});
	    
	    int sx = start[0], sy = start[1], ex = end[0], ey = end[1];
	    
	    queue<pair<int,int>>q;
	    q.push({sx,sy});
	    
	    vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	    int cnt=0;
	    while(!q.empty()){
	        int size=q.size();
	        for(int i=0;i<size;i++){
	            int row=q.front().first;
	            int col=q.front().second;
	            q.pop();
	            if(row==ex && col==ey)return cnt;
	           // cout<<row<<" : "<<col<<"\n";
	            for(int j=0;j<loop.size();j++){
	                int nrow=row+loop[j].first;
	                int ncol=col+loop[j].second;
	               // cout<<<<nrow<<" : "<<ncol<<"\n";
	                if(nrow>=1 && ncol>=1 && nrow<=N && ncol<=N && !vis[nrow][ncol]){
	                    q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
        	           // cout<<nrow<<" : "<<ncol<<"\n";
	                }
	            }
	        }
	            cnt++;
	    }
	    return -1;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends