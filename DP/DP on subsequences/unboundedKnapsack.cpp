#include <bits/stdc++.h> 
using namespace std;

int unboundedKnapsackSpaceOptimization(int n, int wt, vector<int> &p, vector<int> &w)
{
    vector<int> dp(wt + 1, 0);

    for(int i  = 0; i <= wt; i++){
        dp[i] = p[0] * (i / w[0]);
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= wt; j++){
            int notTake = dp[j];
            int take = INT_MIN;
            if(j >= w[i]) take = dp[j - w[i]] + p[i];

            dp[j] = max(take, notTake);
        }
    }

    return dp[wt];
}

int unboundedKnapsackTabulation(int n, int wt, vector<int> &p, vector<int> &w)
{
    vector<vector<int>>dp (n, vector<int>(wt + 1, 0));

    for(int i  = 0; i <= wt; i++){
        dp[0][i] = p[0] * (i / w[0]);
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= wt; j++){
            int notTake = dp[i - 1][j];
            int take = INT_MIN;
            if(j >= w[i]) take = dp[i][j - w[i]] + p[i];

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n - 1][wt];
}
int knapsackHelperMemoization(vector<int> &p, vector<vector<int>> &dp, vector<int> &w, int n, int wt){
    
    if(n == 0){
        if(wt >=  w[0]) return p[0] * (wt / w[0]);
        else return 0;
    }
    
    if(dp[n][wt] != -1) return dp[n][wt];
    
    int notTake = knapsackHelperMemoization(p, dp, w, n - 1, wt);
    int take = INT_MIN;
    if(wt >= w[n]) take = knapsackHelperMemoization(p, dp, w, n, wt - w[n]) + p[n];

    return dp[n][wt] = max(take, notTake);
}

int unboundedKnapsackMemoization(int n, int wt, vector<int> &p, vector<int> &w)
{
    vector<vector<int>>dp (n, vector<int>(wt + 1, -1));
    return knapsackHelperMemoization(p, dp, w, n - 1, wt);
}


int main(){
    int n;
    cin >> n;

    vector<int> wt(n, 0), v(n, 0);
    for(auto &e : wt) cin >> e;
    for(auto &e : v) cin >> e;

    int w;
    cin >> w;
    

    cout<<"Memoization --> "<<unboundedKnapsackMemoization(n, w, v, wt)<<"\n";

    cout<<"Tabulation --> "<<unboundedKnapsackTabulation(n, w, v, wt)<<"\n";

    cout<<"Space Optimization --> "<<unboundedKnapsackSpaceOptimization(n, w, v, wt)<<"\n";


    return 0;
}