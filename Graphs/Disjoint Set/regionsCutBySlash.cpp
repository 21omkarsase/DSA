// 959. Regions Cut By Slashes
// Medium
// 2.8K
// 521
// Companies

// An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

// Given the grid grid represented as a string array, return the number of regions.

// Note that backslash characters are escaped, so a '\' is represented as '\\'.

 

// Example 1:

// Input: grid = [" /","/ "]
// Output: 2

// Example 2:

// Input: grid = [" /","  "]
// Output: 1

// Example 3:

// Input: grid = ["/\\","\\/"]
// Output: 5
// Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.

 

// Constraints:

//     n == grid.length == grid[i].length
//     1 <= n <= 30
//     grid[i][j] is either '/', '\', or ' '.

// Accepted
// 46K
// Submissions
// 66.7K
// Acceptance Rate
// 69.0%

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
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int unMatSize = (n + 1) * (n + 1);

        Disjoint *ds = new Disjoint(unMatSize);
        for(int i = 0; i <= n; i++){
            ds->unionMerge(i, 0);
        }
        for(int i = unMatSize - n; i < unMatSize; i++){
            ds->unionMerge(i, 0);
        }
        for(int i = 0; i <= unMatSize - n; i = i + 1 + n){
            ds->unionMerge(i, 0);
        }
        for(int i = n; i < unMatSize; i = i + 1 + n){
            ds->unionMerge(i, 0);
        }
        
        int cnt = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '/'){
                    int x = ((n + 1) * i) + (j + 1);
                    int y = ((n + 1) * (i + 1)) + j;

                    if(ds->findParent(x) == ds->findParent(y)){
                        cnt++;
                        cout<<grid[i][j]<<" : "<<i<<" : "<<j<<" --> "<<x<<" :: "<<y<<"\n";
                    }
                    else ds->unionMerge(x, y);
                }else if(grid[i][j] == '\\'){
                    int x = ((n + 1) * i) + j;
                    int y = ((n + 1) * (i + 1)) + (j + 1);

                    if(ds->findParent(x) == ds->findParent(y)){
                        cnt++;
                        cout<<grid[i][j]<<" : "<<i<<" : "<<j<<" --> "<<x<<" :: "<<y<<"\n";
                    }
                    else ds->unionMerge(x, y);
                }
            }
        }

        return cnt;
    }
};





