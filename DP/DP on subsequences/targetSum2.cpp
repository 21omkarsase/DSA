class Solution {
    int findTotalWays(int n, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(n == 0){
            return (target - nums[n] == 0) + (target + nums[n] == 0);
        }

        if(dp[n][target + 2000] != -1)
            return dp[n][target + 2000];

        int plus = findTotalWays(n - 1, target - nums[n], nums, dp);
        int minus = findTotalWays(n - 1, target + nums[n], nums, dp);

        return dp[n][target + 2000] = plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(4001, -1));
        return findTotalWays(n - 1, target, nums, dp);
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(4001, 0));

        for(int i = -1000; i <= 1000; i++){
            dp[0][i + 2000] = (i - nums[0] == 0) + (i + nums[0] == 0);
        }

        for(int i = 1; i < n; i++){
            for(int j = -1000; j <= 1000; j++){
                int plus = dp[i - 1] [j + 2000 - nums[i]];
                int minus = dp[i - 1] [j + 2000 + nums[i]];

                dp[i][j + 2000] = plus + minus;
            }
        }

        return dp[n - 1][target + 2000];
    }
};

class Solution {
    int findTotalWays(int n, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(n == 0){
            return (target - nums[n] == 0) + (target + nums[n] == 0);
        }

        if(dp[n][target + 2000] != -1)
            return dp[n][target + 2000];

        int plus = findTotalWays(n - 1, target - nums[n], nums, dp);
        int minus = findTotalWays(n - 1, target + nums[n], nums, dp);

        return dp[n][target + 2000] = plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(4001, -1));
        return findTotalWays(n - 1, target, nums, dp);
    }
};

class Solution {
    int findTotalWays(int n, int target, vector<int> &nums){
        if(n == 0){
            return (target - nums[n] == 0) + (target + nums[n] == 0);
        }

        int plus = findTotalWays(n - 1, target - nums[n], nums);
        int minus = findTotalWays(n - 1, target + nums[n], nums);

        return plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return findTotalWays(n - 1, target, nums);
    }
};