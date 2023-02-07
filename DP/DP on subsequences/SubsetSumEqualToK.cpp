// Subarray = n*(n+1)/2
// Subseqeunce = (2^n) -1 (non-empty subsequences)
// Subset = 2^n

#include <bits/stdc++.h>
using namespace std;


bool subsetSumToKSpaceOptimization(int n, int k, vector<int> &arr) {
    //Time Complexity --> o(n * k)
	//Space Complexity --> o(k)
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);    
    
    prev[0] = curr[0] = 1;
    if(arr[0] <= k) prev[arr[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            int take = false;
            if(j >= arr[i])take = prev[j - arr[i]];
            int notTake = prev[j];
            curr[j] = take || notTake;
        }
        prev = curr;
    }
    return prev[k];
}

bool subsetSumToKTabulation(int n, int k, vector<int> &arr) {
    //Time Complexity --> o(n * k)
	//Space Complexity --> o(n * K)
    vector<vector<bool>>dp(n, vector<bool>(k + 1, 0));
    
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    if(arr[0] <= k) dp[0][arr[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            int take = false;
            if(j >= arr[i])take = dp[i - 1][j - arr[i]];
            int notTake = dp[i - 1][j];

            dp[i][j] = take || notTake;
        }
    }
    return dp[n - 1][k];
}

bool isSubsetPresentHelperMemoization(vector<int> &arr, vector<vector<int>> &dp, int n, int k){
    if(k < 0) return false;
    if(k == 0) return true;

    if(n == 0) return arr[0] == k;

    if(dp[n][k] != -1) return dp[n][k];

    bool take = isSubsetPresentHelperMemoization(arr, dp, n - 1, k - arr[n]);

    bool notTake = isSubsetPresentHelperMemoization(arr, dp, n - 1, k);

    return dp[n][k] = take || notTake;
}

bool subsetSumToKMemoization(int n, int k, vector<int> &arr) {
	//Time Complexity --> o(n * k)
	//Space Complexity --> o(n * K) + O(n)
    vector<vector<int>>dp(n, vector<int>(k + 1, -1));
    return isSubsetPresentHelperMemoization(arr, dp, n - 1, k);
}


bool isSubsetPresentHelperRecursion(vector<int> &arr, int n, int k){
    if(k < 0) return false;
    if(k == 0) return true;

    if(n == 0) return arr[0] == k;

    bool take = isSubsetPresentHelperRecursion(arr, n - 1, k - arr[n]);  // reducing value of k after picking the element

    bool notTake = isSubsetPresentHelperRecursion(arr, n - 1, k);

    return take || notTake;  
}

bool subsetSumToKRecursion(int n, int k, vector<int> &arr) {
	//Time Complexity --> o(2 ^ n)
	//Space Complexity --> o(n)
    return isSubsetPresentHelperRecursion(arr, n - 1, k);
}

int main(){
	int n, k;
	cin>>n>>k;

	vector<int>arr(n, 0);
	for(auto &e : arr)cin>>e;

	cout<<"Recursion --> "<<subsetSumToKRecursion(n, k, arr)<<"\n";

	cout<<"Memoization --> "<<subsetSumToKMemoization(n, k, arr)<<"\n";

	cout<<"Tabulation --> "<<subsetSumToKTabulation(n, k, arr)<<"\n";

	cout<<"Space Optimization --> "<<subsetSumToKSpaceOptimization(n, k, arr)<<"\n";

	return 0;
}