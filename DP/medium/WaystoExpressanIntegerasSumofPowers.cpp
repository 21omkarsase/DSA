// 2787. Ways to Express an Integer as Sum of Powers
// Medium
// 192
// 9
// Companies

// Given two positive integers n and x.

// Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.

// Since the result can be very large, return it modulo 109 + 7.

// For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

 

// Example 1:

// Input: n = 10, x = 2
// Output: 1
// Explanation: We can express n as the following: n = 32 + 12 = 10.
// It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.

// Example 2:

// Input: n = 4, x = 1
// Output: 2
// Explanation: We can express n in the following ways:
// - n = 41 = 4.
// - n = 31 + 11 = 4.

 

// Constraints:

//     1 <= n <= 300
//     1 <= x <= 5

// Accepted
// 9.9K
// Submissions
// 31.5K
// Acceptance Rate
// 31.5%


int MOD = 1e9 + 7;

class Solution {
    int calculatePower(int n, int x) {
        int power = 1;

        while (x--) {
            power = ((long long) power * n) % MOD;
        }

        return power;
    }

    int calculateTotalWays(int idx, int sum, int &x, vector<vector<int>> &dp) {
        if (idx < 0 || sum < 0) {
            return 0;
        }

        if (sum == 0) {
            return 1;
        }

        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }

        int power = calculatePower(idx, x);

        int take = calculateTotalWays(idx - 1, sum - power, x, dp);
        int notTake = calculateTotalWays(idx - 1, sum, x, dp);

        return dp[idx][sum] = ((long long) take + notTake) % MOD;
    }

public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return calculateTotalWays(n, n, x, dp);
    }
};


int MOD = 1e9 + 7;

class Solution {
    int calculatePower(int n, int x) {
        int power = 1;

        while (x){
            if (x & 1) {
                power = ((long long) power * n) % MOD;
            }
            
            n = ((long long) n * n) % MOD;
            x /=> 2;
        }

        return power;
    }

public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int idx = 0; idx <= n; idx++) {
            dp[idx][0] = 1;
        }

        for (int idx = 1; idx <= n; idx++) {
            for (int sum = 1; sum <= n; sum++) {
                int power = calculatePower(idx, x);

                if (sum - power >= 0) {
                    int take = dp[idx - 1][sum - power];
                    int notTake = dp[idx - 1][sum];

                    dp[idx][sum] = ((long long) take + notTake) % MOD;
                } else {
                    dp[idx][sum] = dp[idx - 1][sum];
                }
            }
        }
        return dp[n][n];
    }
};

