// 97. Interleaving String
// Medium
// 7K
// 415
// Companies

// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

// An interleaving of two strings s and t is a configuration where s and t are divided into n and m
// substrings
// respectively, such that:

//     s = s1 + s2 + ... + sn
//     t = t1 + t2 + ... + tm
//     |n - m| <= 1
//     The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...

// Note: a + b is the concatenation of strings a and b.

 

// Example 1:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Explanation: One way to obtain s3 is:
// Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
// Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
// Since s3 can be obtained by interleaving s1 and s2, we return true.

// Example 2:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false
// Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.

// Example 3:

// Input: s1 = "", s2 = "", s3 = ""
// Output: true

 

// Constraints:

//     0 <= s1.length, s2.length <= 100
//     0 <= s3.length <= 200
//     s1, s2, and s3 consist of lowercase English letters.

 

// Follow up: Could you solve it using only O(s2.length) additional memory space?
// Accepted
// 411.1K
// Submissions
// 1.1M
// Acceptance Rate
// 38.1%




// Time Complexity : O(N*M*K)
// Space Complexity : O(N*M*K) + O(N + M + K)


class Solution {
    bool isPossibleToFormS3(int idx, int n, int m, const string &s1, const string &s2, const string &s3, vector<vector<vector<int>>> &dp) {
        if (idx >= s3.size() && (n < s1.size() || m < s2.size())) {
            return false;
        }

        if (idx >= s3.size()) {
            return true;
        }        

        if (dp[n][m][idx] != -1) {
            return dp[n][m][idx];
        }

        if (n < s1.size() && s1[n] == s3[idx]) {
            if (isPossibleToFormS3(idx + 1, n + 1, m, s1, s2, s3, dp)) {
                return dp[n][m][idx] = true;
            }
        }

        if (m < s2.size() && s2[m] == s3[idx]) {
            if (isPossibleToFormS3(idx + 1, n, m + 1, s1, s2, s3, dp)) {
                return dp[n][m][idx] = true;
            }
        }

        return dp[n][m][idx] = false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k, -1)));

        return isPossibleToFormS3(0, 0, 0, s1, s2, s3, dp);
    }
};



// Time Complexity : O(N*M*K)
// Space Complexity : O(N*M*K)

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));

        for (int idx = k; idx >= 0; idx--) {
            for (int idx1 = n; idx1 >= 0; idx1--) {
                for (int idx2 = m; idx2 >= 0; idx2--) {
                    if (idx >= k && (idx1 < n || idx2 < m)) {
                        dp[idx1][idx2][idx] = false;
                    }
                    else if (idx >= k) {
                        dp[idx1][idx2][idx] = true;
                    }
                    else if (idx1 < n && s1[idx1] == s3[idx] && dp[idx1 + 1][idx2][idx + 1]) {
                        dp[idx1][idx2][idx] = true;
                    }
                    else if (idx2 < m && s2[idx2] == s3[idx] && dp[idx1][idx2 + 1][idx + 1]) {
                        dp[idx1][idx2][idx] = true;
                    }
                    else {
                        dp[idx1][idx2][idx] = false;
                    }
                }
            }
        }


        return dp[0][0][0];
    }
};


// Time Complexity : O(N*M)
// Space Complexity : O(N*M) + O(N + M)

// we don't need pointer to track s3 idx (as it will be idx1 + idx2)

class Solution {
    bool isPossibleToFormS3(int n, int m, const string &s1, const string &s2, const string &s3, vector<vector<int>> &dp) {
        if (n + m >= s3.size() && (n < s1.size() || m < s2.size())) {
            return false;
        }

        if (n + m >= s3.size()) {
            return true;
        }        

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (n < s1.size() && s1[n] == s3[n + m]) {
            if (isPossibleToFormS3(n + 1, m, s1, s2, s3, dp)) {
                return dp[n][m] = true;
            }
        }

        if (m < s2.size() && s2[m] == s3[n + m]) {
            if (isPossibleToFormS3(n, m + 1, s1, s2, s3, dp)) {
                return dp[n][m] = true;
            }
        }

        return dp[n][m] = false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return isPossibleToFormS3(0, 0, s1, s2, s3, dp);
    }
};




// Time Complexity : O(N*M)
// Space Complexity : O(N*M) 

class Solution { 
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));

        for (int idx1 = n; idx1 >= 0; idx1--) {
            for (int idx2 = m; idx2 >= 0; idx2--) {
                if (idx1 + idx2 >= k && (idx1 < n || idx2 < m)) {
                    dp[idx1][idx2] = false;
                }
                else if (idx1 + idx2 >= k) {
                    dp[idx1][idx2] = true;
                }        
                else if (idx1 < n && s1[idx1] == s3[idx1 + idx2] && dp[idx1 + 1][idx2]) {
                    dp[idx1][idx2] = true;
                }
                else if (idx2 < m && s2[idx2] == s3[idx1 + idx2] && dp[idx1][idx2 + 1]) {
                    dp[idx1][idx2] = true;
                }
                else {
                    dp[idx1][idx2] = false;
                }
            }
        }

        return dp[0][0];
    }
};


// Time Complexity : O(N*M)
// Space Complexity : O(M) 

class Solution { 
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));

        vector<bool> prev(m + 1, 0), curr(m + 1, 0);

        for (int idx1 = n; idx1 >= 0; idx1--) {
            for (int idx2 = m; idx2 >= 0; idx2--) {
                if (idx1 + idx2 >= k && (idx1 < n || idx2 < m)) {
                    curr[idx2] = false;
                }
                else if (idx1 + idx2 >= k) {
                    curr[idx2] = true;
                }        
                else if (idx1 < n && s1[idx1] == s3[idx1 + idx2] && prev[idx2]) {
                    curr[idx2] = true;
                }
                else if (idx2 < m && s2[idx2] == s3[idx1 + idx2] && curr[idx2 + 1]) {
                    curr[idx2] = true;
                }
                else {
                    curr[idx2] = false;
                }
            }

            prev = curr;
        }

        return prev[0];
    }
};
