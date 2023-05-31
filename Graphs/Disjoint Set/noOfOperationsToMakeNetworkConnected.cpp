// 1319. Number of Operations to Make Network Connected
// Medium
// 4.3K
// 59
// Companies

// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

// Example 1:

// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

// Example 2:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2

// Example 3:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.

 

// Constraints:

//     1 <= n <= 105
//     1 <= connections.length <= min(n * (n - 1) / 2, 105)
//     connections[i].length == 2
//     0 <= ai, bi < n
//     ai != bi
//     There are no repeated connections.
//     No two computers are connected by more than one cable.

// Accepted
// 174.2K
// Submissions

class Disjoint{
    vector<int>size, parent;
public:
    Disjoint(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]==node)return node;

        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    void unionMerge(int u,int v){
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

    int getDisConnCompsNo(){
        int cnt = 0;
        for(int i = 0; i < parent.size(); i++){
                    if(findParent(i) == i){
                        cnt++;
                    }
        }

        return cnt - 1;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint *ds = new Disjoint(n);
            
        int cnt = 0;
        for(auto conn : connections){
            if(ds->findParent(conn[0]) == ds->findParent(conn[1])){
                cnt++;
            }else{
                                ds->unionMerge(conn[0], conn[1]);
                        }
        }

        int disConnComps = ds->getDisConnCompsNo();

        if(disConnComps <= cnt)
            return disConnComps;
        else return -1;
    }
};












