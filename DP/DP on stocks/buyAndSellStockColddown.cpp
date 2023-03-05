#include<bits/stdc++.h>
using namespace std;

int maxProfitSpaceOptimization(vector<int>& p) {
    int n = p.size();
    vector<int> ahead(2, 0), aheadAhead(2, 0), curr(2, 0);

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= 1; j++){
            int take, notTake;
            if(j){
                take = ahead[0] - p[i];
                notTake = ahead[1];
            }else{
                take = aheadAhead[1] + p[i];
                notTake = ahead[0];
            }

            curr[j] = max(take, notTake);
        }
        aheadAhead = ahead;
        ahead = curr;
    }

    return ahead[1];
}

int maxProfitTabulation(vector<int>& p) {
    int n = p.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= 1; j++){
            int take, notTake;
            if(j){
                take = dp[i + 1][0] - p[i];
                notTake = dp[i + 1][1];
            }else{
                take = dp[i + 2][1] + p[i];
                notTake = dp[i + 1][0];
            }

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[0][1];
}

int maxPorfitHelperMemoization(vector<int>& p, vector<vector<int>> &dp, int n, int buy){
    if(n >= p.size()) return 0;
    
    if(dp[n][buy] != -1) return dp[n][buy];

    int profit = 0, take, notTake;

    if(buy){
        take = maxPorfitHelperMemoization(p, dp, n + 1, 0) - p[n];
        notTake = maxPorfitHelperMemoization(p, dp, n + 1, 1);
    }else{
        take = maxPorfitHelperMemoization(p, dp, n + 2, 1) + p[n];
        notTake = maxPorfitHelperMemoization(p, dp, n + 1, 0);
    }

    return dp[n][buy] = max(take, notTake);
}

int maxProfitMemoization(vector<int>& p) {
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return maxPorfitHelperMemoization(p, dp, 0, 1);
}

int main(){
 int n;
 cin >> n;
 vector<int>p(n, 0);
 
 for(auto &e : p)cin>>e;
 

 cout<<maxProfitMemoization(p)<<"\n";

 cout<<maxProfitTabulation(p)<<"\n";

 cout<<maxProfitSpaceOptimization(p)<<"\n";

 return 0;
} 