#include <bits/stdc++.h>
using namespace std;

// int findCost(vector<int> &heights, vector<int>& dp, int n){
//     if(n == 0) return 0;
//     if(n == 1) return dp[1] = abs(heights[1] - heights[0]);

//     int left = (dp[n-1] == 0 ? findCost(heights, dp, n-1) : dp[n-1]) + abs(heights[n] - heights[n-1]) ;
//     int right = (dp[n-2] == 0 ? findCost(heights, dp, n-2) : dp[n-2]) + abs(heights[n] - heights[n-2]) ;
    
//     return dp[n] = min(left, right);
// }
// int frogJump(int n, vector<int> &heights)
// {
//     vector<int>dp(n,0);
//     return findCost(heights, dp, n-1);
// }


// int frogJump(int n, vector<int> &heights)
// {
//     vector<int>dp(n,0);
//     dp[0] = 0;
//     if(n==1)return 0;

//     dp[1] = abs(heights[1] - heights[0]);
//     if(n==2)return dp[1];

//     for(int i=2;i<n;i++){
//         int step1 = abs(heights[i] - heights[i-1]);
//         int step2 = abs(heights[i] - heights[i-2]);

//         dp[i] = min((dp[i-1] + step1), (dp[i-2] + step2));
//     }

//     return dp[n-1];
// }

int frogJump(int n, vector<int> &heights)
{
    if(n==1)return 0;

    if(n==2)return abs(heights[1] - heights[0]);
    
    int prevPrev=0, prev = abs(heights[1] - heights[0]);
    for(int i=2;i<n;i++){
        int step1 = abs(heights[i] - heights[i-1]);
        int step2 = abs(heights[i] - heights[i-2]);

        int temp = prev;
        prev = min((prev + step1), (prevPrev + step2));
        prevPrev = temp;
    }

    return prev;
}

int main(){
    int n;cin>>n;
    vector<int>heights(n);
    for(auto &e : heights) cin>>e;

    cout<<frogJump(n,heights)<<"\n";
}