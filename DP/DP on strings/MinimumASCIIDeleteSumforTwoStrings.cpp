// 712. Minimum ASCII Delete Sum for Two Strings
// Medium
// 2.7K
// 72
// Companies

// Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

// Example 1:

// Input: s1 = "sea", s2 = "eat"
// Output: 231
// Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
// Deleting "t" from "eat" adds 116 to the sum.
// At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

// Example 2:

// Input: s1 = "delete", s2 = "leet"
// Output: 403
// Explanation: Deleting "dee" from "delete" to turn the string into "let",
// adds 100[d] + 101[e] + 101[e] to the sum.
// Deleting "e" from "leet" adds 101[e] to the sum.
// At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
// If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

 

// Constraints:

//     1 <= s1.length, s2.length <= 1000
//     s1 and s2 consist of lowercase English letters.

// Accepted
// 85K
// Submissions
// 134.4K
// Acceptance Rate
// 63.2%

// Time Complexity : O(N^2)
// Space Complexity : O(N^2) + O(N + M)

class Solution {
    int calculateMinimumSum(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &memo) {
        if (idx1 < 0) {
            int sum = 0;

            for (int idx = 0; idx <= idx2; idx++) {
                sum += (s2[idx] + 0);
            }

            return sum;
        }

        if (idx2 < 0) {
            int sum = 0;

            for (int idx = 0; idx <= idx1; idx++) {
                sum += (s1[idx] + 0);
            }

            return sum;
        }

        if (memo[idx1][idx2] != -1) {
            return memo[idx1][idx2];
        }

        if (s1[idx1] == s2[idx2]) {
            return memo[idx1][idx2] = calculateMinimumSum(idx1 - 1, idx2 - 1, s1, s2, memo);
        }

        return memo[idx1][idx2] = min(calculateMinimumSum(idx1, idx2 - 1, s1, s2, memo) + (s2[idx2] + 0),
                   calculateMinimumSum(idx1 - 1, idx2, s1, s2, memo) + (s1[idx1] + 0));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));

        return calculateMinimumSum(n - 1, m - 1, s1, s2, memo);
    }
};


// Time Complexity : O(N^2)
// Space Complexity : O(N^2) 

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int idx1 = 0; idx1 <= n; idx1++) {
            for (int idx2 = 0; idx2 <= m; idx2++) {
                if (idx1 == 0) {
                    int sum = 0;

                    for (int idx = 0; idx < idx2; idx++) {
                        sum += (s2[idx] + 0);
                    }

                    dp[idx1][idx2] = sum;
                }
                else if (idx2 == 0) {
                    int sum = 0;

                    for (int idx = 0; idx < idx1; idx++) {
                        sum += (s1[idx] + 0);
                    }

                    dp[idx1][idx2] = sum;
                }
                else {
                    if (s1[idx1 - 1] == s2[idx2 - 1]) {
                        dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1];
                    }
                    else {
                        dp[idx1][idx2] = min(dp[idx1][idx2 - 1] + (s2[idx2 - 1] + 0),
                                            dp[idx1 - 1][idx2] + (s1[idx1 - 1] + 0));
                    }
                }
            }
        }

        return dp[n][m];
    }
};