#include<bits/stdc++.h>
using namespace std;

int findCost(vector<int> &dp, vector<int> &heights, int n, int k){
    if(n == 0) return 0;
    if(n == 1) return abs(heights[0] - heights[1]);

    int minCost = INT_MAX;

    for(int j=1;j<=k;j++){
        if(n-j>=0){
       int cost = dp[n - j] == 0 ? findCost(dp, heights, n-j, k) + abs(heights[n] - heights[n-j]) : dp[n - j] + abs(heights[n] - heights[n-j]);
       minCost = min(minCost, cost);}
    }
    return dp[n] = minCost;
}

int frogJumpUsingMemoization(int n, int k, vector<int> &heights){
    vector<int>dp(n,0);
    return findCost(dp,heights,n-1,k);
}

int frogJumpUsingTabulation(int n, int k, vector<int> &heights){
    vector<int>dp(n,0);

    dp[0] = 0;
    if(n == 1) return 0;

    dp[1] = abs(heights[1] - heights[0]);
    if(n  == 2) return dp[1];

    for(int i=2;i<n;i++){
        int minCost = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-j >= 0){
                int cost = abs(heights[i] - heights[i-j]) + dp[i-j];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost; 
    }
    return dp[n-1];
}


int main(){
    int n,k;cin>>n>>k;
    vector<int>heights(n);
    for(auto &e : heights) cin>>e;

    cout<<"Using Memoization --> "<<frogJumpUsingMemoization(n,k,heights)<<"\n";
    cout<<"Using Memoization --> "<<frogJumpUsingTabulation(n,k,heights)<<"\n";

}