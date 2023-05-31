// 886. Possible Bipartition
// Medium
// 4.3K
// 101
// Companies

// We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

// Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

// Example 1:

// Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: The first group has [1,4], and the second group has [2,3].

// Example 2:

// Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
// Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.

 

// Constraints:

//     1 <= n <= 2000
//     0 <= dislikes.length <= 104
//     dislikes[i].length == 2
//     1 <= ai < bi <= n
//     All the pairs of dislikes are unique.

// Accepted
// 184.5K
// Submissions
// 368.3K
// Acceptance Rate
// 50.1%

class DisJoint{
    vector<int> SIZE;
    vector<int> parent;

public:

    DisJoint(int n){
        SIZE.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node])
            return node;

        return parent[node] = this->findParent(parent[node]);
    }

    void unionMerge(int u, int v){
        int ulp_u = this->findParent(u);
        int ulp_v = this->findParent(v);

        if(ulp_u == ulp_v)
            return;
        
        if(SIZE[ulp_u] > SIZE[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else if(SIZE[ulp_v] > SIZE[ulp_u]){
            parent[ulp_u] = ulp_v;
        }else{
            parent[ulp_u] = ulp_v;
            SIZE[ulp_v] += SIZE[ulp_u];
        }
    }
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n + 1];

        for(auto vec : dislikes){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }

        DisJoint *ds = new DisJoint(n + 1);

        for(int node = 1; node <= n; node++){
            for(auto adjNode : adj[node]){
                if(ds->findParent(node) == ds->findParent(adjNode))
                    return false;
                
                ds->unionMerge(adj[node][0], adjNode);
            }
        }

        return true;
    }
};