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

class Solution{
public:
    int matrixMultiplication(int n, int nums[])
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int start = n - 3; start >= 0 ; start--){
            for(int end = start + 1; end < n - 1; end++){
                int maxCalculations = INT_MAX;
                for(int it = start; it < end; it++){
                    maxCalculations = min(maxCalculations, 
                                          nums[start] * nums[it + 1] * nums[end + 1] + 
                                          dp[start][it] + dp[it + 1][end]);
                }
                
                dp[start][end] = maxCalculations;
            }
        }
        
        return dp[0][n - 2];
    }
};

class Solution{
    int mcm(int start, int end, int nums[], vector<vector<int>> &dp){
        if(start == end)
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int maxCalculations = INT_MAX;
        for(int it = start; it < end; it++){
            maxCalculations = min(maxCalculations, 
                                  nums[start] * nums[it + 1] * nums[end + 1] + 
                                  mcm(start, it, nums, dp)+ mcm(it + 1, end, nums, dp)
                            );
        }
        
        return dp[start][end] = maxCalculations;
    }
public:
    int matrixMultiplication(int n, int nums[])
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return mcm(0, n - 2, nums, dp);
    }
};



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