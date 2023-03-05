#include <bits/stdc++.h> 
using namespace std;

int minCostTabulation(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for(int i = c; i > 0; i--){
        for(int j = i; j <= c; j++){
            int ans = INT_MAX;
            for(int k = i; k <= j; k++){
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                ans = min(ans, cost);
            }

            dp[i][j] = ans;
        }
    }
    
    return dp[1][c];
}

int minCostHelperMemoization(vector<int> &cuts, vector<vector<int>> &dp, int i, int j){
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k = i; k <= j; k++){
        int cost = cuts[j + 1] - cuts[i - 1] + minCostHelperMemoization(cuts, dp, i, k - 1) + minCostHelperMemoization(cuts, dp, k + 1, j);
        ans = min(ans, cost);
    }

    return dp[i][j] = ans;
}
int minCostHelperMemoization(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return minCostHelperMemoization(cuts, dp, 1, c);
}


int main(){
	int n;
	cin >> n;

	vector<int> nums(n, 0);
	for(auto &e : nums) 
		cin >> e;

	cout<<minCostHelperMemoization(n, nums)<<"\n";

    cout<<minCostTabulation(n, nums)<<"\n";
    
	return 0;
}