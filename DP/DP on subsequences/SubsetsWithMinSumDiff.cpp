#include <bits/stdc++.h> 
using namespace std;

int minSubsetSumDifferenceSpaceOptimization(vector<int>& arr, int n)
{
	int sum = 0;
	for(auto e : arr) sum += e;
	if(sum <= 0) return 0;

	vector<int> prev(sum + 1, 0), curr(sum + 1, 0);

	prev[0] = curr[0] = 1;
	if(sum >= arr[0])prev[arr[0]] = 1;

	for(int i = 1; i < n; i++){
		for(int j = 1; j <= sum; j++){
			int take = false;
			if(j >= arr[i]) take = prev[j - arr[i]];
			int notTake = prev[j];

			curr[j] = take || notTake;
		}
		prev = curr;
	}
    
	int ans = 1e9;
	for(int i = 0; i <= sum / 2; i++){
		if(prev[i]){
			int diff = abs(i - (sum - i));
			ans = min(ans, diff);
		}
	}

	return ans;
}


int minSubsetSumDifferenceTabulation(vector<int>& arr, int n)
{
	int sum = 0;
	for(auto e : arr) sum += e;
	vector<vector<int>>dp (n, vector<int>(sum + 1, 0));

	for(int i = 0; i < n; i++) dp[i][0] = 1;
	dp[0][arr[0]] = 1;

	for(int i = 1; i < n; i++){
		for(int j = 1; j <= sum; j++){
			int take = false;
			if(j >= arr[i]) take = dp[i - 1][j - arr[i]];
			int notTake = dp[i - 1][j];

			dp[i][j] = take || notTake;
		}
	}
    
	int ans = 1e9;
	for(int i = 0; i <= sum / 2; i++){
		if(dp[n - 1][i]){
			int diff = abs(i - (sum - i));
			ans = min(ans, diff);
		}
	}

	return ans;
}



int main(){
	int n;
	cin>>n;

	vector<int>arr(n, 0);
	for(auto &e : arr)
		cin>>e;

	cout<<"Tabulation --> "<<minSubsetSumDifferenceTabulation(arr, n)<<"\n";

	cout<<"Space Optimization --> "<<minSubsetSumDifferenceSpaceOptimization(arr, n)<<"\n";
	return 0;
}