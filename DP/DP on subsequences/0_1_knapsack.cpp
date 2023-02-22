#include <bits/stdc++.h> 
using namespace std;

int knapsackSpaceOptimization(vector<int> wt, vector<int> v, int n, int w) 
{
    vector<int> dp(w + 1, 0);

    for(int i = wt[0]; i <= w; i++) dp[i] = v[0];

    for(int i = 1; i < n; i++){
      for (int j = w; j >= 0; j--) {
        int pick = INT_MIN;
        if (wt[i] <= j)
          pick = dp[j - wt[i]] + v[i];

        int notPick = dp[j];

        dp[j] = max(pick, notPick);
      }
    }
    return dp[w];
}

int knapsackTabulation(vector<int> wt, vector<int> v, int n, int w) 
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for(int i = wt[0]; i <= w; i++) dp[0][i] = v[0];

    for(int i = 1; i < n; i++){
      for (int j = 0; j <= w; j++) {
        int pick = INT_MIN;
        if (wt[i] <= j)
          pick = dp[i - 1][j - wt[i]] + v[i];

        int notPick = dp[i - 1][j];

        dp[i][j] = max(pick, notPick);
      }
    }
    return dp[n - 1][w];
}

int knapsackHelperMemoization(vector<int> &wt, vector<int> &v, vector<vector<int>> &dp, int n, int w){
    if(w < 0) return -1e9;

    if(n == 0){
        if(wt[0] <= w) return v[0];
        else return 0;
    }
    
    if(dp[n][w] != -1) return dp[n][w];

    int pick = knapsackHelperMemoization(wt, v, dp, n - 1, w - wt[n]) + v[n];

    int notPick = knapsackHelperMemoization(wt, v, dp, n - 1, w);

    return dp[n][w] = max(pick, notPick);
}

int knapsackMemoization(vector<int> wt, vector<int> v, int n, int w) 
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
	return knapsackHelperMemoization(wt, v, dp, n - 1, w);
}


int knapsackHelperRecursion(vector<int> &wt, vector<int> &v, vector<vector<int>> &dp, int n, int w){
    if(w < 0) return -1e9;

    if(n == 0){
        if(wt[0] <= w) return v[0];
        else return 0;
    }
    
    if(dp[n][w] != -1) return dp[n][w];

    int pick = knapsackHelperRecursion(wt, v, dp, n - 1, w - wt[n]) + v[n];

    int notPick = knapsackHelperRecursion(wt, v, dp, n - 1, w);

    return dp[n][w] = max(pick, notPick);
}

int knapsackRecursion(vector<int> wt, vector<int> v, int n, int w) 
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return knapsackHelperRecursion(wt, v, dp, n - 1, w);
}

int main(){
    int n;
    cin >> n;

    vector<int> wt(n, 0), v(n, 0);
    for(auto &e : wt) cin >> e;
    for(auto &e : v) cin >> e;

    int w;
    cin >> w;
    
    cout<<"Recursion --> "<<knapsackRecursion(wt, v, n, w)<<"\n";

    cout<<"Memoization --> "<<knapsackMemoization(wt, v, n, w)<<"\n";

    cout<<"Tabulation --> "<<knapsackTabulation(wt, v, n, w)<<"\n";

    cout<<"Space Optimization --> "<<knapsackSpaceOptimization(wt, v, n, w)<<"\n";


    return 0;
}