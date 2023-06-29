// 813. Largest Sum of Averages
// Medium
// 1.9K
// 92
// Companies

// You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.

// Note that the partition must use every integer in nums, and that the score is not necessarily an integer.

// Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.

 

// Example 1:

// Input: nums = [9,1,2,3,9], k = 3
// Output: 20.00000
// Explanation: 
// The best choice is to partition nums into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
// We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
// That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.

// Example 2:

// Input: nums = [1,2,3,4,5,6,7], k = 4
// Output: 20.50000

 

// Constraints:

//     1 <= nums.length <= 100
//     1 <= nums[i] <= 104
//     1 <= k <= nums.length

// Accepted
// 47.3K
// Submissions
// 89.3K
// Acceptance Rate
// 52.9%

// recursion

// Time Complexity : O(2^ N)
// Space Complexity : O(N)

class Solution {
    double calculateSumAverage(int idx, int prev, int k, vector<int> &nums, vector<int> &sum, vector<vector<vector<double>>> &dp) {
        if (idx == nums.size()) {
            if (k == 0) {
                return 0;
            }
            return -1e9; 
        }

        if (k == 0) {
            return -1e9; 
        }

        if (dp[idx][prev][k] != -1)
            return dp[idx][prev][k];

        double divide = calculateSumAverage(idx + 1, idx, k - 1, nums, sum, dp) + ((double) (sum[idx] - sum[prev])) / (double) (idx - prev);

        double notDivide = calculateSumAverage(idx + 1, prev, k, nums, sum, dp);

        return dp[idx][prev][k] = max(divide, notDivide);
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {

        nums.insert(nums.begin(), 0);

        int n = nums.size();
        vector<int> sum(n, 0);

        for (int idx = 1; idx < n; idx++) 
            sum[idx] = nums[idx] + sum[idx - 1];
        
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        
        return calculateSumAverage(1, 0, k, nums, sum, dp);
    }
};



// Time Complexity : O(N*M*K)
// Space Complexity : O(N*M*K) + O(K) RECURSIVE STCK CALL


// memoization  using 3d dp
class Solution {
    double calculateSumAverage(int idx, int prev, int k, vector<int> &nums, vector<int> &sum, vector<vector<vector<double>>> &dp) {
        if (idx == nums.size()) {
            if (k == 0) {
                return 0;
            }
            return -1e9; 
        }

        if (k == 0) {
            return -1e9; 
        }

        if (dp[idx][prev][k] != -1)
            return dp[idx][prev][k];

        double divide = calculateSumAverage(idx + 1, idx, k - 1, nums, sum, dp) + ((double) (sum[idx] - sum[prev])) / (double) (idx - prev);

        double notDivide = calculateSumAverage(idx + 1, prev, k, nums, sum, dp);

        return dp[idx][prev][k] = max(divide, notDivide);
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {

        nums.insert(nums.begin(), 0);

        int n = nums.size();
        vector<int> sum(n, 0);

        for (int idx = 1; idx < n; idx++) 
            sum[idx] = nums[idx] + sum[idx - 1];
        
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        
        return calculateSumAverage(1, 0, k, nums, sum, dp);
    }
};


// Time Complexity : O(N*K)
// Space Complexity : O(N*k) + O(K) RECURSIVE STCK CALL

/// memoization using 2d dp
class Solution {
    double calculateLargestAverageSum(int idx, int k, vector<int>& nums, vector<vector<double>> &dp) {
        if (idx == nums.size()) {
                return 0;
        }

        if (k == 0)
            return -1e9;
        
        if (dp[idx][k] != -1)
            return dp[idx][k];
        
        double largestAverageSum = INT_MIN;
        double sum = 0;

        for (int partition = idx; partition < nums.size(); partition++) {
            sum += nums[partition];
            largestAverageSum = max(largestAverageSum, calculateLargestAverageSum(partition + 1, k - 1, nums, dp) + sum / (double) (partition - idx + 1));
        }

        return dp[idx][k] = largestAverageSum;
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<vector<double>> dp(n, vector<double>(k + 1, -1));
        return calculateLargestAverageSum(0, k, nums, dp);
    }
};



// Time Complexity : O(N*M*K)
// Space Complexity : O(N*M*K)

//tabulation using 3d dp
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int kMax) {
        nums.insert(nums.begin(), 0);

        int n = nums.size();
        vector<int> sum(n, 0);

        for (int idx = 1; idx < n; idx++) 
            sum[idx] = nums[idx] + sum[idx - 1];
        
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(kMax + 1, -1e9)));

        for (int prev = 0; prev < n; prev++) {
            for (int k = 0; k <= kMax; k++) {
                if (k != 0){
                    dp[n - 1][prev][k] = ((double) (sum[n - 1] - sum[prev])) / (double) (n - 1 - prev);
                }
            }
        }

        for (int idx = n - 2; idx >= 1; idx--) {
            for (int prev = n - 1; prev >= 0; prev--) {
                for(int k = 1; k <= kMax; k++) {
                    double divide = dp[idx + 1][idx][k - 1] + ((double) (sum[idx] - sum[prev])) / (double) (idx - prev);

                    double notDivide = dp[idx + 1][prev][k];

                    dp[idx][prev][k] = max(divide, notDivide);
                    
                }
            }
        }
        
        return dp[1][0][kMax];
    }
};




// tabulation using 2d dp


// Time Complexity : O(N*K)
// Space Complexity : O(N*K) 

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int kMax) {
        int n = nums.size();
        
        vector<vector<double>> dp(n + 1, vector<double>(kMax + 1, -1e9));

        for (int k = 0; k <= kMax; k++)
            dp[n][k] = 0;

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int k = 1; k <= kMax; k++) {
                double largestAverageSum = INT_MIN;
                double sum = 0;

                for (int partition = idx; partition < nums.size(); partition++) {
                    sum += nums[partition];
                    largestAverageSum = max(largestAverageSum, dp[partition + 1][k - 1] + sum / (double) (partition - idx + 1));
                }

                dp[idx][k] = largestAverageSum;
            }
        }

        return dp[0][kMax];
    }
};
