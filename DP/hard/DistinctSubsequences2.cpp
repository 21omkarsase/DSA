// 940. Distinct Subsequences II
// Solved
// Hard
// Topics
// Companies

// Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.
// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.

 

// Example 1:

// Input: s = "abc"
// Output: 7
// Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".

// Example 2:

// Input: s = "aba"
// Output: 6
// Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".

// Example 3:

// Input: s = "aaa"
// Output: 3
// Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".

 

// Constraints:

//     1 <= s.length <= 2000
//     s consists of lowercase English letters.

// Accepted
// 35.9K
// Submissions
// 82.9K
// Acceptance Rate
// 43.3%

// Time Complexity : O(N)
// Space Complexity : O(2N)

class Solution {
    const int MOD = 1e9 + 7;
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        unordered_map<char, int> tracker;
        
        for (int idx = 1; idx <= n; idx++) {
            dp[idx] = ((long long) dp[idx - 1] * 2) % MOD;

            if (tracker.find(s[idx - 1]) != tracker.end()) {
                dp[idx] = ((long long) dp[idx] % MOD - dp[tracker[s[idx - 1]] - 1] % MOD) % MOD;
            }

            tracker[s[idx - 1]] = idx;
        }

        dp[n]--;

        if(dp[n] < 0)
            dp[n] += MOD;

        return dp[n];
    }
};