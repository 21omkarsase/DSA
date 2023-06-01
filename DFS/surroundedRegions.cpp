// 130. Surrounded Regions
// Medium
// 7.2K
// 1.5K
// Companies

// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

// Example 1:

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// Explanation: Notice that an 'O' should not be flipped if:
// - It is on the border, or
// - It is adjacent to an 'O' that should not be flipped.
// The bottom 'O' is on the border, so it is not flipped.
// The other three 'O' form a surrounded region, so they are flipped.

// Example 2:

// Input: board = [["X"]]
// Output: [["X"]]

 

// Constraints:

//     m == board.length
//     n == board[i].length
//     1 <= m, n <= 200
//     board[i][j] is 'X' or 'O'.

// Accepted
// 538.5K
// Submissions
// 1.5M
// Acceptance Rate
// 37.0%

// *************************using visited array*******************

class Solution {
    void dfs(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<char>>& board){
        vis[i][j] = 1;
        for(int r = -1; r <= 1; r++){
            for(int c = -1; c <= 1; c++){
                if(abs(r) != abs(c)){
                    int row = r + i, col = c + j;
                    if(row >= 0 && col >= 0 && row < n && col < m && !vis[row][col] && board[row][col] == 'O'){
                        dfs(row, col, n, m, vis, board);
                    }
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                    if(board[i][j] == 'O' && !vis[i][j]){
                        dfs(i, j, n, m, vis, board);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                    vis[i][j] = 1;
                }
            }
        }
    }
};

// ***************************without using extraa space***********************

class Solution {
    void dfs(int i, int j, int n, int m, vector<vector<char>>& board){
        board[i][j] = '1';
        for(int r = -1; r <= 1; r++){
            for(int c = -1; c <= 1; c++){
                if(abs(r) != abs(c)){
                    int row = r + i, col = c + j;
                    if(row >= 0 && col >= 0 && row < n && col < m && board[row][col] == 'O'){
                        dfs(row, col, n, m, board);
                    }
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                    if(board[i][j] == 'O' && board[i][j] != '1'){
                        dfs(i, j, n, m, board);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};


// **************************using union find***************************************
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
    void solve(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        Disjoint *ds = new Disjoint((m * n) + 1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'X')
                    continue;
                if(i == 0 || j == 0 || i == n - 1 || j == m -1){
                    ds->unionMerge(m * n, (m * i) + j);
                }else{
                    for(int row = -1; row <= 1; row++){
                        for(int col = -1; col <= 1; col++){
                            if(abs(row) != abs(col)){
                                int nrow = row + i, ncol = col + j;
                                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 'O'){
                                    ds->unionMerge((m * i) + j, (m * nrow) + ncol);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        int boundaryPar = ds->findParent(m * n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int currParent = ds->findParent((m * i) + j);
                if(grid[i][j] == 'O' && currParent != boundaryPar)
                    grid[i][j] = 'X';
            }
        }
    }
};




















