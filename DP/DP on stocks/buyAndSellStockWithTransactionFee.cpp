#include<bits/stdc++.h>
using namespace std;

 int maxProfitSpaceOptimization(vector<int>& p, int f) {
    int n = p.size();
    vector<int> ahead(2, 0), curr(2, 0);

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= 1; j++){
            int take, notTake;
            if(j){
                take = ahead[0] - p[i] - f;
                notTake = ahead[1];
            }else{
                take = ahead[1] + p[i];
                notTake = ahead[0];
            }

            curr[j] = max(take, notTake); 
        }
        ahead = curr;
    }
    return ahead[1];
}

int maxProfitTabulation(vector<int>& p, int f) {
    int n = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= 1; j++){
            int take, notTake;
            if(j){
                take = dp[i + 1][0] - p[i] - f;
                notTake = dp[i + 1][1];
            }else{
                take = dp[i + 1][1] + p[i];
                notTake = dp[i + 1][0];
            }

            dp[i][j] = max(take, notTake); 
        }
    }
    return dp[0][1];
}

int maxProfitHelperMemoization(vector<int>& p, vector<vector<int>> &dp, int f, int n , int buy){
    if(n == p.size()) return 0;

    if(dp[n][buy] != -1) return dp[n][buy];

    int take, notTake;
    if(buy){
        take = maxProfitHelperMemoization(p, dp, f, n + 1, 0) - p[n] - f;
        notTake = maxProfitHelperMemoization(p, dp, f, n + 1, 1);
    }else{
        take = maxProfitHelperMemoization(p, dp, f, n + 1, 1) + p[n];
        notTake = maxProfitHelperMemoization(p, dp, f, n + 1, 0);
    }

    return dp[n][buy] = max(take, notTake); 
}

int maxProfitMemoization(vector<int>& p, int f) {
    int n = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return maxProfitHelperMemoization(p, dp, f, 0, 1);
}

int main(){
 int n, f;
 cin >> n >> f;
 vector<int>p(n, 0);
 
 for(auto &e : p)cin>>e;
 

 cout<<maxProfitMemoization(p, f)<<"\n";

 cout<<maxProfitTabulation(p, f)<<"\n";

 cout<<maxProfitSpaceOptimization(p, f)<<"\n";

 return 0;
} 