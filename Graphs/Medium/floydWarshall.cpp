// Floyd Warshall
// MediumAccuracy: 32.89%Submissions: 79K+Points: 4
// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation  

// The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
// Do it in-place.

// Example 1:

// Input: matrix = {{0,25},{-1,0}}

// Output: {{0,25},{-1,0}}

// Explanation: The shortest distance between
// every pair is already given(if it exists).

// Example 2:

// Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}

// Output: {{0,1,7},{1,0,6},{-1,-1,0}}

// Explanation: We can reach 2 from 0 as 0->1->2
// and the cost will be 1+6=7 which is less than 
// 43.

// Your Task:
// You don't need to read, return or print anything. Your task is to complete the function shortest_distance() which takes the matrix as input parameter and modifies the distances for every pair in-place.

// Expected Time Complexity: O(n3)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= n <= 100
// -1 <= matrix[ i ][ j ] <= 1000


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:

  //multiple source shortest path algorithm
  //also detects -ve cycles
  //in directed graph only(convert undirected to directed)
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();

	    //Initial cost matrix
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1)matrix[i][j]=1e9;
	        }
	    }
	    

	    // check for miniumm distance every node to every other node via all distinct nodes
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }

	    for(int i = 0; i < n; i++){
	    	for(int j = 0; j < n; j++){
	    		if(matrix[i][j] < 0){
	    			cout<<"Negative cycle exists.\n";
	    		}
	    	}
	    }
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9)matrix[i][j]=-1;
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends

// Time Complexity:

//     The Floyd-Warshall algorithm has a time complexity of O(V^3), where V is the number of vertices.
//     The algorithm iterates over all pairs of vertices and considers each vertex as a potential intermediate vertex.
//     In each iteration, the algorithm updates the shortest path between all pairs of vertices by considering the intermediate vertex.
//     Therefore, the algorithm performs three nested loops, resulting in a time complexity of O(V^3).

// Space Complexity:

//     The space complexity of the Floyd-Warshall algorithm is O(V^2) because it requires a matrix to store the shortest distances between all pairs of vertices.
//     The matrix has dimensions V x V to represent all possible pairs of vertices.
//     Therefore, the overall space complexity is O(V^2).

// It's important to note that the Floyd-Warshall algorithm is suitable for small to medium-sized graphs due to its cubic time complexity. For larger graphs, more efficient algorithms such as Dijkstra's algorithm or the Bellman-Ford algorithm may be preferred.

// In summary, the time complexity of the Floyd-Warshall algorithm is O(V^3) and the space complexity is O(V^2).