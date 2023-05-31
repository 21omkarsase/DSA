// Minimum Spanning Tree
// MediumAccuracy: 47.82%Submissions: 69K+Points: 4
// Lamp
// Stand out from the crowd. Prepare with Complete Interview Preparation  

// Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

 

// Example 1:

// Input:
// 3 3
// 0 1 5
// 1 2 3
// 0 2 1

// Output:
// 4
// Explanation:

// The Spanning Tree resulting in a weight
// of 4 is shown above.

// Example 2:

// Input:
// 2 1
// 0 1 5

// Output:
// 5
// Explanation:
// Only one Spanning Tree is possible
// which has a weight of 5.

 

// Your task:
// Since this is a functional problem you don't have to worry about input, you just have to complete the function  spanningTree() which takes number of vertices V and an adjacency matrix adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains a list of lists containing two integers where the first integer a[i][0] denotes that there is an edge between i and a[i][0][0] and second integer a[i][0][1] denotes that the distance between edge i and a[i][0][0] is a[i][0][1].

// In other words , adj[i][j] is of form  { u , wt } . So,this denotes that i th node is connected to u th node with  edge weight equal to wt.

 

// Expected Time Complexity: O(ElogV).
// Expected Auxiliary Space: O(V2).
 

// Constraints:
// 2 ≤ V ≤ 1000
// V-1 ≤ E ≤ (V*(V-1))/2
// 1 ≤ w ≤ 1000
// Graph is connected and doesn't contain self loops & multiple edges.

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjoint{
	vector<int>size, parent;
public:
	Disjoint(int n){
		size.resize(n+1,1);
		parent.resize(n+1);
		for(int i=0;i<=n;i++){
			parent[i]=i;
		}
	}

	int findParent(int node){
		if(parent[node]==node)return node;

		parent[node] = findParent(parent[node]);
		return parent[node];
	}

	void unionBySize(int u,int v){
		int ulp_u=findParent(u);
		int ulp_v=findParent(v);

		if(ulp_u == ulp_v)return ;
        
		if(size[ulp_u]>size[ulp_v]){
			parent[ulp_v]=ulp_u; 
			size[ulp_u]+=size[ulp_v];
		}else{
			parent[ulp_u]=ulp_v; 
			size[ulp_v]+=size[ulp_u];
		}
	}
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        // O (N + E)
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                
                edges.push_back({wt,{i,adjNode}});
            }
        }
        //N(LogM)
        sort(edges.begin(),edges.end());
        
        int ans=0;
        Disjoint ds(V);
        // (4 * alpha) * 2
        for(auto it:edges){
            int w=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.findParent(u)!=ds.findParent(v)){
                ds.unionBySize(u,v);
                ans+=w;
            }
        }
        
        return ans;   
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends

// The time and space complexity of Kruskal's algorithm using the union-find data structure can be analyzed as follows:

// Time Complexity:

//     The time complexity of Kruskal's algorithm using union-find is O(E log E), where E is the number of edges in the graph.
//     The algorithm starts by sorting the edges in ascending order of their weights, which takes O(E log E) time using efficient sorting algorithms such as quicksort or mergesort.
//     Then, for each edge, the algorithm performs a union operation using the union-find data structure and checks if the two vertices belong to different sets. This operation takes nearly constant time with the union-find data structure.
//     Overall, the algorithm performs O(E) union and find operations, and since the union-find operations have amortized constant time complexity, the dominant factor is the time required for sorting the edges.
//     Therefore, the overall time complexity is O(E log E).

// Space Complexity:

//     The space complexity of Kruskal's algorithm using union-find is O(V + E), where V is the number of vertices and E is the number of edges.
//     The union-find data structure requires space proportional to the number of vertices, which is O(V).
//     Additionally, the algorithm may require space to store the sorted edges and other auxiliary data structures.
//     Therefore, the overall space complexity is O(V + E).

// It's worth noting that in the case of a dense graph where E is close to V^2, the sorting step may dominate the overall time complexity. In contrast, for a sparse graph where E is much smaller than V^2, the time complexity of sorting becomes less significant.

// In summary, the time complexity of Kruskal's algorithm using union-find is O(E log E), and the space complexity is O(V + E).