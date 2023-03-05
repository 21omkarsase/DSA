//matrix a : 10 * 30
//matrix b : 30 * 5
//number of operations : 10 * 30 * 5

//Steps : 
// 1.Start with entire block/array
// 2.Try all partitions
// 3.Return the best possible partition

// A * (B*C*D)
//(10, 20) [(20, 30),(30, 40), (40, 50)]
// (10, 20) (20, 50)
// (10, 50)


#include <bits/stdc++.h> 
using namespace std;

int matrixMultiplicationTabulation(vector<int>& nums, int n){
    int ans = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n - 1; i > 0; i--){
        for(int j = i; j < n; j++){
            if(i == j) dp[i][j] = 0;
            else{
                int ans = INT_MAX;
                for(int k = i; k < j; k++){
                    int steps = nums[i - 1] * nums[k] * nums[j] + dp[i][k] + dp[k + 1][j];
                    ans = min(ans, steps);
                }
                dp[i][j] = ans;
            }
        }
    }

    return dp[1][n - 1];
}


// Time Complexity: O(N*N*N)
// Space Complexity: O(N*N) + O(N)

int mcmHelperMemoization(vector<int> &nums, vector<vector<int>> &dp, int i, int j){
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int steps = (nums[i - 1] * nums[k] * nums[j] + mcmHelperMemoization(nums, dp, i, k) + mcmHelperMemoization(nums, dp, k + 1, j));
        ans = min(steps, ans);
    }

    return dp[i][j] = ans;
}


int matrixMultiplicationMemoization(vector<int>& arr, int n){
    int ans = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return mcmHelperMemoization(arr, dp, 1, n - 1);
}

int main(){
	int n;
	cin >> n;

	vector<int> nums(n, 0);
	for(auto &e : nums) 
		cin >> e;

	cout<<matrixMultiplicationMemoization(nums, n)<<"\n";

    cout<<matrixMultiplicationTabulation(nums, n)<<"\n";
    
	return 0;
}