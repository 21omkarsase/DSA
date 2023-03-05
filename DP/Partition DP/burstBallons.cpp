// 312. Burst Balloons
// Hard
// 7.4K
// 189
// Companies

// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

 

// Example 1:

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

// Example 2:

// Input: nums = [1,5]
// Output: 10

 

// Constraints:

//     n == nums.length
//     1 <= n <= 300
//     0 <= nums[i] <= 100

// Accepted
// 221.3K
// Submissions
// 388.6K
// Acceptance Rate
// 56.9%

#include<bits/stdc++.h>
using namespace std;

int maxCoinsTabulation(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;

    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    vector<vector<int>> dp(n + 3, vector<int>(n + 3, 0));

    for(int i = n; i >= 1; i--){
        for(int j = i; j <= n; j++){
            int ans = INT_MIN;
            for(int k = i; k <= j; k++){
                int cost = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                ans = max(ans, cost);
            }

            dp[i][j] =  ans;
        }
    }

    return dp[1][n];
}


int maxCoinsHelperMemiozation(vector<int> &nums, vector<vector<int>> &dp, int i, int j){
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MIN;
    for(int k = i; k <= j; k++){
        int cost = nums[i - 1] * nums[k] * nums[j + 1] + maxCoinsHelperMemiozation(nums, dp, i, k - 1) + maxCoinsHelperMemiozation(nums, dp, k + 1, j);
        ans = max(ans, cost);
    }

    return dp[i][j] =  ans;
}

int maxCoinsMemiozation(vector<int>& nums) {
    int n = nums.size();

    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return maxCoinsHelperMemiozation(nums, dp, 1, n);
}

int main(){
    int n;cin>>n;
    vector<int> nums(n, 0);
    for(auto &e : nums) cin >> e;

    cout<<maxCoinsMemiozation(nums)<<"\n";

    cout<<maxCoinsTabulation(nums)<<"\n";

    return 0;
}