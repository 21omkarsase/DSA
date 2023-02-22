#include<bits/stdc++.h>
using namespace std;

int maxProfitSpaceOptimization(vector<int>& p) {
    int n = p.size();
    vector<long> prev(2, 0), curr(2, 0);
    
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= 1; j++){
            int profit = 0;
            if(j == 1) profit = max(prev[0] - p[i], prev[1]);
            else profit = max(prev[1] + p[i], prev[0]);

            curr[j] = profit;
        }
        prev = curr;
    }

    return prev[1];
}

int maxProfitTabulation(vector<int>& p) {
    int n = p.size();
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));
    
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= 1; j++){
            int profit = 0;
            if(j == 1) profit = max(dp[i + 1][0] - p[i], dp[i + 1][1]);
            else profit = max(dp[i + 1][1] + p[i], dp[i + 1][0]);

            dp[i][j] = profit;
        }
    }

    return dp[0][1];
}

int fMemoization(vector<int> &p, vector<vector<long>> &dp, int n, int buy){
    if(n == p.size()) return 0;
    
    if(dp[n][buy] != -1) return dp[n][buy];
    if(buy){
        return dp[n][buy] = max(fMemoization(p, dp, n + 1, 0) - p[n], fMemoization(p, dp, n + 1, 1));
    }else{
        return dp[n][buy] = max(fMemoization(p, dp, n + 1, 1) + p[n], fMemoization(p, dp, n + 1, 0));
    }
}
int maxProfitMemoization(vector<int>& p) {
    int n = p.size();
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return fMemoization(p, dp, 0, 1);
} 

int main(){
 int n;cin>>n;
 vector<int>p(n, 0);
 
 for(auto &e : p)cin>>e;
 
 cout<<maxProfitMemoization(p)<<"\n";

 cout<<maxProfitSpaceOptimization(p)<<"\n";

 cout<<maxProfitTabulation(p)<<"\n";

 return 0;
} 