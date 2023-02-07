#include<bits/stdc++.h>
using namespace std;

int getTotalSum(vector<int>arr){
	int sum = 0;
	for(auto e : arr) sum += e;
	return sum;
}

bool canPartitionSpaceOptimization(vector<int> &arr, int n)
{
    if(n == 1) return false;

    int totalSum = getTotalSum(arr);

    if(totalSum & 1) return false;

    int sum = totalSum / 2;

    vector<bool> prev(sum + 1, 0), curr(sum + 1, 0);

    prev[0] = curr[0] = 1;
    if(arr[0] <= sum) prev[arr[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= sum; j++){
            int pick = 0;
            if(arr[i] <= j) pick = prev[j - arr[i]];
            int notPick = prev[j];

            curr[j] =  pick || notPick;
        }
        prev = curr;
    }

    return prev[sum];
}

bool canPartitionTabulation(vector<int> &arr, int n)
{
    if(n == 1) return false;

    int totalSum = getTotalSum(arr);

    if(totalSum & 1) return false;

    int sum = totalSum / 2;
    vector<vector<bool>>dp (n, vector<bool>(sum + 1, 0));
    
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    if(arr[0] <= sum) dp[0][arr[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= sum; j++){
            int pick = 0;
            if(arr[i] <= j) pick = dp[i - 1][j - arr[i]];
            int notPick = dp[i - 1][j];

            dp[i][j] =  pick || notPick;
        }
    }

    return dp[n - 1][sum];
}

bool canPartitionMemoizationHelper(vector<int> &arr, vector<vector<int>> &dp, int sum, int n){
	if(sum < 0) return false;

	if(sum == 0) return true;

	if(n == 0) return sum == arr[0];
    
	if(dp[n][sum] != -1) return dp[n][sum];

	int pick = canPartitionMemoizationHelper(arr, dp, sum - arr[n], n - 1);
	int notPick = canPartitionMemoizationHelper(arr, dp, sum, n - 1);

	return dp[n][sum] = pick || notPick;
}

bool subsetSumToKMemoization(vector<int> &arr, int n)
{
	if(n == 1) return false;

	int totalSum = getTotalSum(arr);

	if(totalSum & 1) return false;
    vector<vector<int>>dp (n, vector<int>((totalSum/2) + 1, -1));
	return canPartitionMemoizationHelper(arr, dp, totalSum/2, n - 1);
}

int main(){
	int n;
	cin>>n;

	vector<int>arr(n, 0);
	for(auto &e : arr)cin>>e;


	cout<<"Memoization --> "<<subsetSumToKMemoization(arr, n)<<"\n";

	cout<<"Tabulation --> "<<canPartitionTabulation(arr, n)<<"\n";

	cout<<"Space Optimization --> "<<canPartitionSpaceOptimization(arr, n)<<"\n";

	return 0;
}