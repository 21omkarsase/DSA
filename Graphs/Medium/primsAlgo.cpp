 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
pq.push({0, 0});

vector<bool> vis(n, 0);

int ans = 0;
while(!pq.empty()){
    int w = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(vis[node]) continue;
    
    vis[node] = 1;
    ans += w;

    for(auto p : adj[node]){
        int adjNode = p.first;
        int weight = p.second;
        if(!vis[adjNode]){
            pq.push({weight, adjNode});
        }
    }
}

return ans;


// The time and space complexity of Prim's algorithm using a min heap can be analyzed as follows:

// Time Complexity:

//     The time complexity of Prim's algorithm with a min heap implementation is O((V + E) log V), where V is the number of vertices and E is the number of edges.
//     In each iteration of the algorithm, a vertex is added to the minimum spanning tree (MST) and its adjacent edges are processed.
//     The min heap operations, such as insertion and deletion, take O(log V) time.
//     Since each vertex is inserted into the heap once and each edge is processed once, the total number of operations is O(V + E).
//     Therefore, the overall time complexity is O((V + E) log V).

// Space Complexity:

//     The space complexity of Prim's algorithm is O(V + E) because it requires space to store the vertices, edges, and the min heap.
//     The min heap requires O(V) space to store the vertices, and the edges are typically stored in an adjacency list or matrix, which requires O(E) space.
//     Additionally, Prim's algorithm may require space for other data structures, such as a boolean array to track visited vertices or a key array to store the weights of vertices.
//     Therefore, the overall space complexity is O(V + E).

// In summary, the time complexity of Prim's algorithm with a min heap implementation is O((V + E) log V), and the space complexity is O(V + E).