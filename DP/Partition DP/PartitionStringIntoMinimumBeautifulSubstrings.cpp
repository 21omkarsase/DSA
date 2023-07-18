// 2767. Partition String Into Minimum Beautiful Substrings
// Medium
// 140
// 6
// Companies

// Given a binary string s, partition the string into one or more substrings such that each substring is beautiful.

// A string is beautiful if:

//     It doesn't contain leading zeros.
//     It's the binary representation of a number that is a power of 5.

// Return the minimum number of substrings in such partition. If it is impossible to partition the string s into beautiful substrings, return -1.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: s = "1011"
// Output: 2
// Explanation: We can paritition the given string into ["101", "1"].
// - The string "101" does not contain leading zeros and is the binary representation of integer 51 = 5.
// - The string "1" does not contain leading zeros and is the binary representation of integer 50 = 1.
// It can be shown that 2 is the minimum number of beautiful substrings that s can be partitioned into.

// Example 2:

// Input: s = "111"
// Output: 3
// Explanation: We can paritition the given string into ["1", "1", "1"].
// - The string "1" does not contain leading zeros and is the binary representation of integer 50 = 1.
// It can be shown that 3 is the minimum number of beautiful substrings that s can be partitioned into.

// Example 3:

// Input: s = "0"
// Output: -1
// Explanation: We can not partition the given string into beautiful substrings.

 

// Constraints:

//     1 <= s.length <= 15
//     s[i] is either '0' or '1'.

// Accepted
// 7.7K
// Submissions
// 15K
// Acceptance Rate
// 51.4%


//memoization


// Time Complexity : O(N^3*6)
// Space Complexity : O(N*N) + O(N)

class Solution {
    bool isValid(string s) {
        int num = 0;

        for (int idx = s.size() - 1; idx >= 0; idx--) 
            if (s[idx] == '1')
                num += (1 << (s.size() - idx - 1));

        if (num == 1)
            return true;

        int x = 1;

        while (x < num)
            x = x * 5;

        return x == num;
    }

    int calculateMinPartitions(int start, int end, string s, vector<vector<int>> &dp) {
        if (s[start] == '0') 
            return 1e9;
        
        if (isValid(s.substr(start, end - start + 1))) 
            return 0;
        
        if (dp[start][end] != -1) 
            return dp[start][end];

        int minPartitions = 1e9;

        for (int partition = start + 1; partition <= end; partition++) {
            int left = calculateMinPartitions(start, partition - 1, s, dp);
            int right = calculateMinPartitions(partition, end, s, dp);

            minPartitions = min(minPartitions, left + right + 1);
        }

        return dp[start][end] = minPartitions;
    }
public:
    int minimumBeautifulSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

        int partitions = calculateMinPartitions(0, s.size() - 1, s, dp);
        return partitions >= 1e9 ? -1 : partitions + 1;
    }
};


//tabulation


// Time Complexity : O(N^3*6)
// Space Complexity : O(N*N)

class Solution {
    bool isValid(string s) {
        int num = 0;

        for (int idx = s.size() - 1; idx >= 0; idx--) 
            if (s[idx] == '1')
                num += (1 << (s.size() - idx - 1));

        if (num == 1)
            return true;

        int x = 1;

        while (x < num)
            x = x * 5;

        return x == num;
    }

public:
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 1e9));
        
        for (int start = n - 1; start >= 0; start--) {
            for (int end = start; end < n; end++) {
                if (s[start] == '0')
                    dp[start][end] = 1e9;
                else if (isValid(s.substr(start, end - start + 1))) 
                    dp[start][end] = 0;
                else {
                    int minPartitions = 1e9;

                    for (int partition = start + 1; partition <= end; partition++) {
                        int left = dp[start][partition - 1];
                        int right = dp[partition][end];

                        minPartitions = min(minPartitions, left + right + 1);
                    }

                    dp[start][end] = minPartitions;
                }
            }
        }

        return dp[0][n - 1] >= 1e9 ? -1 : dp[0][n - 1] + 1;
    }
};


//Time Complexity : O(N^2)
// Space Complexity : O(N) + O(N)

class Solution {
    bool isValid(string s) {
        int num = 0;

        for (int idx = s.size() - 1; idx >= 0; idx--) 
            if (s[idx] == '1')
                num += (1 << (s.size() - idx - 1));

        if (num == 1)
            return true;

        int x = 1;

        while (x < num)
            x = x * 5;

        return x == num;
    }

    int calculateMinPartitions(int idx, string s, vector<int> &dp) {
        if (idx >= s.size())
            return 0;

        if (s[idx] == '0') 
            return 1e9;

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int minPartitions = 1e9;

        for (int partition = idx; partition < s.size(); partition++) {
            if (isValid(s.substr(idx, partition - idx + 1))) {
                int right = calculateMinPartitions(partition + 1, s, dp);

                minPartitions = min(minPartitions,  right + 1);
            }
        }

        return dp[idx] = minPartitions;
    }
public:
    int minimumBeautifulSubstrings(string s) {
        vector<int> dp(s.size(), -1);
        int partitions = calculateMinPartitions(0, s, dp);
        
        return partitions >= 1e9 ? -1 : partitions;
    }
};