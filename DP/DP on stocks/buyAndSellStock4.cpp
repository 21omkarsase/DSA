#include<bits/stdc++.h>
using namespace std;

int maxProfitSpaceOptimization(int k, vector<int>& p) {
    int n = p.size();
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0)), curr(2, vector<int>(k + 1, 0));

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= 1; j++){
            for(int c = 1; c <= k; c++){
                int profit = 0, take, notTake;
                if(j){
                    take = ahead[0][c] - p[i];
                    notTake = ahead[1][c];
                }else{
                    take = ahead[1][c - 1] + p[i];
                    notTake = ahead[0][c];
                }

                curr[j][c] = max(take, notTake);
            }
        }
        ahead = curr;
    }

    return ahead[1][k];
}

int maxProfitTabulation(int k, vector<int>& p) {
    int n = p.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= 1; j++){
            for(int c = 1; c <= k; c++){
                int profit = 0, take, notTake;
                if(j){
                    take = dp[i + 1][0][c] - p[i];
                    notTake = dp[i + 1][1][c];
                }else{
                    take = dp[i + 1][1][c - 1] + p[i];
                    notTake = dp[i + 1][0][c];
                }

                dp[i][j][c] = max(take, notTake);
            }
        }
    }

    return dp[0][1][k];
}


int maxProfitHelperMemoization(vector<int> &p, vector<vector<vector<int>>> &dp, int n, int buy, int cap){
    if(cap == 0 || n == p.size()) return 0;
    
    if(dp[n][buy][cap] != -1) return dp[n][buy][cap];

    int profit = 0, take, notTake;
    if(buy){
        take = maxProfitHelperMemoization(p, dp, n + 1, 0, cap) - p[n];
        notTake = maxProfitHelperMemoization(p, dp, n + 1, 1, cap);
    }else{
        take = maxProfitHelperMemoization(p, dp, n + 1, 1, cap - 1) + p[n];
        notTake = maxProfitHelperMemoization(p, dp, n + 1, 0, cap);
    }

    return dp[n][buy][cap] = max(take, notTake);
}
int maxProfitMemoization(int k, vector<int>& p) {
    int n = p.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return maxProfitHelperMemoization(p, dp, 0, 1, k);
}

int main(){
 int n, k;
 cin >> n >> k;
 vector<int>p(n, 0);
 
 for(auto &e : p)cin>>e;
 

 cout<<maxProfitMemoization(k, p)<<"\n";

 cout<<maxProfitTabulation(k, p)<<"\n";

 cout<<maxProfitSpaceOptimization(k, p)<<"\n";

 return 0;
} 