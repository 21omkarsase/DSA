// 664. Strange Printer
// Hard
// 1.4K
// 129
// Companies

// There is a strange printer with the following two special properties:

//     The printer can only print a sequence of the same character each time.
//     At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.

// Given a string s, return the minimum number of turns the printer needed to print it.

 

// Example 1:

// Input: s = "aaabbb"
// Output: 2
// Explanation: Print "aaa" first and then print "bbb".

// Example 2:

// Input: s = "aba"
// Output: 2
// Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.

 

// Constraints:

//     1 <= s.length <= 100
//     s consists of lowercase English letters.

// Accepted
// 41.3K
// Submissions
// 82.6K
// Acceptance Rate
// 50.0%

// Time Complexity : O(N^3)
// Space Complexity : O(N^3) + O(N)
class Solution {
    int calculateTotalTurns(int left, int right, string &s, vector<vector<int>> &memo) {
        if (left > right) {
            return 0;
        }

        if (left == right) {
            return 1;
        }

        if (memo[left][right] != -1) {
            return memo[left][right];
        }


        int turns = 1e9;
        
        // when all characters are diff -> ans will be number of characters
        // if repeating characters are present that number will start decreasing (specially consecutive)
        // for two same characters -> 
                    // if they have diff character in between -> ans = 1 (whole s will be printed) + 
                                                                       // printing count of in bet charaters

                    // ans will be 1
        for (int idx = left + 1; idx <= right; idx++) {
            if (s[idx] == s[left]) { 
                // instead of directly adding 1 (tdsgt)
                // we make s as tdsg (eventually 1 will get added when s == 't')
                turns = min(turns, calculateTotalTurns(left, idx - 1, s, memo) + calculateTotalTurns(idx + 1, right, s, memo));
            }
        }

        return memo[left][right] = min(turns, 1 + calculateTotalTurns(left + 1, right, s, memo));
    }
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));

        return calculateTotalTurns(0, s.size() - 1, s, memo);
    }
};


// Time Complexity : O(N^3)
// Space Complexity : O(N^3)

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int left = n - 1; left >= 0; left--) {
            for (int right = left; right < n; right++) {
                if (left == right) {
                    dp[left][right] = 1;
                }
                else {
                    int turns = 1e9;

                    for (int idx = left + 1; idx <= right; idx++) {
                        if (s[idx] == s[left]) {
                            turns = min(turns, dp[left][idx - 1] + dp[idx + 1][right]);
                        }
                    }

                    dp[left][right] = min(turns, 1 + dp[left + 1][right]);
                }
            }
        }

        return dp[0][n - 1];
    }
};