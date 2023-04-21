// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     bool isValid(int i, int j, int n, int m, vector<vector<int>> &grid){
//         if(i > n || i < 0 || j > m || j < 0 || grid[i][j] == -1){
//             return false;
//         }
//         return true;
//     }
//     int kdHelper(vector<vector<int>> &grid, int steps, int n, int m, int cnt, int i , int j, vector<pair<int, int>> validMoves){
//         int mod = 1000000007;

//         if(cnt == steps){
//             return 1;
//         } 

//         if(i > n || j > m || i < 0 || j < 0) return 0;

//         int currAns = 0;
//         for(auto p : validMoves){
//             if(isValid(i + p.first, j + p.second, n, m, grid)){
//                 currAns += (kdHelper(grid, steps, n, m, cnt + 1, i + p.first, j + p.second, validMoves) % mod);
//             }
//         }

//         return (currAns % mod);
//     }

//     int knightDialer(int n) {
//         int mod = 1000000007;
//         vector<pair<int, int>> validMoves;
//         validMoves.push_back({1, 2});
//         validMoves.push_back({2, 1});
//         validMoves.push_back({-1,-2});
//         validMoves.push_back({-2, -1});
//         validMoves.push_back({1, -2});
//         validMoves.push_back({-2, 1});
//         validMoves.push_back({-1, 2});
//         validMoves.push_back({2, -1});

//         vector<vector<int>> grid(4, vector<int>(3, 0));
//         for(int i = 0, k = 1; i < 4; i++){
//             for(int j = 0; j < 3; j++){
//                 grid[i][j] = k++;
//             }
//         }

//         grid[3][0] = -1, grid[3][2] = -1, grid[3][1] = 0;

//         int ans = 0;
//         for(int i = 0; i < 4; i++){
//             for(int j = 0; j < 3; j++){
//                 if(grid[i][j] != -1){
//                    ans = (ans + (kdHelper(grid, n, 3, 2, 1, i, j, validMoves) % mod) % mod);
//                 }
//             }
//         }
//         return (ans % mod);
//     }
// };

// int main(){
//     int n;cin>>n;

//     Solution *s = new Solution();

//     cout<<s->knightDialer(n)<<"\n";
    
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knightDialer(int n) {
       if(n == 1)
        return 10;

       unordered_map<int, vector<int>> um;

       um[0] = {4, 6}; 
       um[1] = {6, 8}; 
       um[2] = {7, 9}; 
       um[3] = {4, 8}; 
       um[4] = {0, 3, 9}; 
       um[6] = {0, 1, 7}; 
       um[7] = {2, 6}; 
       um[8] = {1, 3};
       um[9] = {2, 4};

       vector<int>v(10, 1);

       for(int i = 2; i <= n; i++){
           vector<int> temp(10, 0);
           for(auto p: um){
                int key = p.first;
                vector<int>value = p.second;
               for(auto ele : value){
                   temp[key] = (temp[key] + v[ele]) % 1000000007;
               }
           }
           v = temp;
        } 

       int ans = 0;
       for(auto ele : v)
        ans = (ans + ele) % 1000000007;

       return ans;
    }
};

int main(){
    int n;cin>>n;

    Solution *s = new Solution();

    cout<<s->knightDialer(n)<<"\n";
    
    return 0;
}