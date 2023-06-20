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

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int start = n - 2; start >= 0; start--){
            for(int end = start + 2; end < n; end++){
                int maxCoins = 0;

                for(int idx = start + 1; idx < end; idx++){
                    int currCoins = nums[start] * nums[end] * nums[idx];
                    int leftPartCoins = dp[start][idx];
                    int rightPartCoins = dp[idx][end];

                    maxCoins = max(maxCoins, currCoins + leftPartCoins + rightPartCoins);
                }

                dp[start][end] = maxCoins;
            }
        }
        
        return dp[0][n - 1];
    }
};


class Solution {
    int calculateMaxCoins(int start, int end, vector<int> &nums, vector<vector<int>> &dp){
        if(dp[start][end] != -1)
            return dp[start][end];

        int maxCoins = 0;

        for(int idx = start + 1; idx < end; idx++){
            int currCoins = nums[start] * nums[end] * nums[idx];
            int leftPartCoins = calculateMaxCoins(start, idx, nums, dp);
            int rightPartCoins = calculateMaxCoins(idx, end, nums, dp);

            maxCoins = max(maxCoins, currCoins + leftPartCoins + rightPartCoins);
        }

        return dp[start][end] = maxCoins;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return calculateMaxCoins(0, n - 1, nums, dp);
    }
};





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