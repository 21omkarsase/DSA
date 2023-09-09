// 2707. Extra Characters in a String
// Medium
// 1.6K
// 69
// Companies

// You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

// Return the minimum number of extra characters left over if you break up s optimally.

 

// Example 1:

// Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
// Output: 1
// Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

// Example 2:

// Input: s = "sayhelloworld", dictionary = ["hello","world"]
// Output: 3
// Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.

 

// Constraints:

//     1 <= s.length <= 50
//     1 <= dictionary.length <= 50
//     1 <= dictionary[i].length <= 50
//     dictionary[i] and s consists of only lowercase English letters
//     dictionary contains distinct words

// Accepted
// 57.9K
// Submissions
// 110.8K
// Acceptance Rate
// 52.3%

// Time Complexity : O(N^3)
// Space Complexity : O(N^2) + O(N) + O(N + N)

class Solution {
    int calculateTotalCharcters(int start, int end, const string &s, const unordered_set<string> &dict, vector<vector<int>> &dp) {
        if (end >= s.size()) {
            if (dict.find(s.substr(start, end - start + 1)) != dict.end()) {
                return end - start;
            }

            return 0;
        }

        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        bool flag = dict.find(s.substr(start, end - start + 1)) != dict.end();

        int cont = calculateTotalCharcters(start, end + 1, s, dict, dp);
        int notCont = calculateTotalCharcters(end + 1, end + 1, s, dict, dp);

        if (flag) {
            return dp[start][end] = max(notCont + end - start + 1, cont);
        }
        else {
            return dp[start][end] = max(notCont, cont);
        }
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        
        return n - calculateTotalCharcters(0, 0, s, dict, dp);
    }
};


// Time Complexity : O(N^3)
// Space Complexity : O(N^2) + O(N) 

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        for (int start = n; start >= 0; start--) {
            for (int end = n; end >= 0; end--) {
                if (end == n) {
                    if (dict.find(s.substr(start, end - start + 1)) != dict.end()) {
                        dp[start][end] = end - start;
                    }
                    else {
                        dp[start][end] =  0;
                    }
                }
                else {
                    bool flag = dict.find(s.substr(start, end - start + 1)) != dict.end();

                    int cont = dp[start][end + 1];
                    int notCont = dp[end + 1][end + 1];

                    if (flag) {
                        dp[start][end] = max(notCont + end - start + 1, cont);
                    }
                    else {
                        dp[start][end] = max(notCont, cont);
                    }
                }
            }
        }
        
        return n - dp[0][0];
    }
};