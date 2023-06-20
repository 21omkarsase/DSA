#include<bits/stdc++.h>
using namespace std;


// User function Template for C++

class Solution{
    int calculateTotalPrice(int n, int price[], vector<int> &dp){
        if(n == 0)
            return 0;
            
        if(dp[n] != -1)
            return dp[n];
        
        int maxPrice = 0;
        for(int i = 1; i <= n; i++){
            maxPrice = max(maxPrice, calculateTotalPrice(n - i, price, dp) + price[i - 1]);
        }
        
        return dp[n] = maxPrice;
    }
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n + 1, -1);
        return calculateTotalPrice(n, price, dp);
    }
};

int cutRodHelperMemoization(vector<int> &price, vector<vector<int>> &dp, int n, int target){
	if(n == 1){
		if(target >= 1) return price[0] * target;
		else return 0;
	}
    
	if(dp[n][target] != -1) return dp[n][target];

	int notTake = cutRodHelperMemoization(price, dp, n - 1, target);
	int take = -1e9;
	if(target >= n) take = cutRodHelperMemoization(price, dp, n, target - n) + price[n - 1];

	return dp[n][target] = max(take, notTake);
}
int cutRodMemoization(vector<int> &price, int n)
{
	vector<vector<int>>dp (n + 1, vector<int>(n + 1, -1));
	return cutRodHelperMemoization(price, dp, n, n);
}



int main(){
    int n;
    cin >> n;

    vector<int> price(n, 0);
    for(auto &e : price) cin>>e;
    

    cout<<"Memoization --> "<<cutRodMemoization(price, n)<<"\n";

    // cout<<"Tabulation --> "<<unboundedKnapsackTabulation(price, n)<<"\n";

    // cout<<"Space Optimization --> "<<unboundedKnapsackSpaceOptimization(price, n)<<"\n";


    return 0;
}