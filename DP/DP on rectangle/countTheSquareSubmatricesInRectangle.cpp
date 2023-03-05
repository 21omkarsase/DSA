#include<bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp = matrix;

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(matrix[i][j] && matrix[i - 1][j] && matrix[i][j - 1] && matrix[i - 1][j - 1]){
                dp[i][j] += min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }

   int squares = 0;
   for(auto v : dp)
       for(auto e : v)
            squares += e;
    
    return squares;
}


int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }

    cout<<countSquares(matrix)<<"\n";
    
    return 0;
}