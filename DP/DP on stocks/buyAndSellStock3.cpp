#include<bits/stdc++.h>
using namespace std;

int maxProfitSpaceOptimization(vector<int>& p) {
    int n = p.size();
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));
    int pick = 0, notPick = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= 1; j++){
            for(int k = 1; k <= 2; k++){
                int profit = 0;
                if(j){
                    pick = after[0][k] - p[i];
                    notPick = after[1][k];

                }else{
                    pick = after[1][k - 1] + p[i];
                    notPick = after[0][k];
                }
                curr[j][k] = max(pick , notPick);
            }
        }
        after = curr;
    }

    return after[1][2];
}

int maxProfitTabulation(vector<int>& p) {
    int n = p.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    int pick = 0, notPick = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= 1; j++){
            for(int k = 1; k <= 2; k++){
                int profit = 0;
                if(j){
                    pick = dp[i + 1][0][k] - p[i];
                    notPick = dp[i + 1][1][k];

                }else{
                    pick = dp[i + 1][1][k - 1] + p[i];
                    notPick = dp[i + 1][0][k];
                }
                dp[i][j][k] = max(pick , notPick);
            }
        }
    }

    return dp[0][1][2];
}


int maxProfitHelperMemoization(vector<int> &p, vector<vector<vector<int>>> &dp, int n, int buy, int cap){
    if(n == p.size() || cap == 0) return 0;
    
    if(dp[n][buy][cap] != -1) return dp[n][buy][cap];
    
    int profit = 0;
    if(buy){
        int buy = maxProfitHelperMemoization(p, dp, n + 1, 0, cap) - p[n];
        int notBuy = maxProfitHelperMemoization(p, dp, n + 1, 1, cap);

        profit= max(buy, notBuy);
    }else{
        int sell = maxProfitHelperMemoization(p, dp, n + 1, 1, cap - 1) + p[n];
        int notSell = maxProfitHelperMemoization(p, dp, n + 1, 0, cap);

        profit = max(sell, notSell);
    }
}
int maxProfitMemoization(vector<int>& p) {
    int n = p.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return maxProfitHelperMemoization(p, dp, 0, 1, 2);
}

int maxProfitHelperRecursion(vector<int> &p, int n, int buy, int cap){
    if(n == p.size() || cap == 0) return 0;
        
    if(buy){
        int buy = maxProfitHelperRecursion(p,  n + 1, 0, cap) - p[n];
        int notBuy = maxProfitHelperRecursion(p,  n + 1, 1, cap);

        return  max(buy, notBuy);
    }else{
        int sell = maxProfitHelperRecursion(p,  n + 1, 1, cap - 1) + p[n];
        int notSell = maxProfitHelperRecursion(p,  n + 1, 0, cap);

        return  max(sell, notSell);
    }
}
int maxProfitRecursion(vector<int>& p) {
    int n = p.size();
    return maxProfitHelperRecursion(p, 0, 1, 2);
}

int main(){
 int n;cin>>n;
 vector<int>p(n, 0);
 
 for(auto &e : p)cin>>e;
 
 cout<<maxProfitRecursion(p)<<"\n";

 cout<<maxProfitMemoization(p)<<"\n";

 cout<<maxProfitTabulation(p)<<"\n";

 cout<<maxProfitSpaceOptimization(p)<<"\n";

 return 0;
} 