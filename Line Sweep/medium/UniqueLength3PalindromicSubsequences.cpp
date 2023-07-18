// 1930. Unique Length-3 Palindromic Subsequences
// Medium
// 707
// 20
// Companies

// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

//     For example, "ace" is a subsequence of "abcde".

 

// Example 1:

// Input: s = "aabca"
// Output: 3
// Explanation: The 3 palindromic subsequences of length 3 are:
// - "aba" (subsequence of "aabca")
// - "aaa" (subsequence of "aabca")
// - "aca" (subsequence of "aabca")

// Example 2:

// Input: s = "adc"
// Output: 0
// Explanation: There are no palindromic subsequences of length 3 in "adc".

// Example 3:

// Input: s = "bbcbaba"
// Output: 4
// Explanation: The 4 palindromic subsequences of length 3 are:
// - "bbb" (subsequence of "bbcbaba")
// - "bcb" (subsequence of "bbcbaba")
// - "bab" (subsequence of "bbcbaba")
// - "aba" (subsequence of "bbcbaba")

 

// Constraints:

//     3 <= s.length <= 105
//     s consists of only lowercase English letters.

// Accepted
// 25.6K
// Submissions
// 48.7K
// Acceptance Rate
// 52.7%

// Time Complexity : O(3^N)
// Space Complexity : O(N)

class Solution {
    int calculateTotalPalindromes(int start, int end, string left, string right, unordered_set<string> &tracker, string s){
        if (left.size() + right.size() > 3)
            return 0;a

                return 0;
            }

            return 0;
        }

        int totalPalindromes = 0;
        if (s[start] == s[end]) {
            totalPalindromes = calculateTotalPalindromes(start + 1, end - 1, left + s[start], s[end] + right, tracker, s);
        }

        totalPalindromes += calculateTotalPalindromes(start + 1, end, left, right, tracker, s);

        totalPalindromes += calculateTotalPalindromes(start, end - 1, left, right, tracker, s);
        
        return totalPalindromes;
    }
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        unordered_set<string> tracker;
        
        return calculateTotalPalindromes(0, n - 1, "", "", tracker, s);
    }
};


// Time Complexity : O(26 *N)
// Space Complexity : O(N)


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        unordered_map<char, pair<int, int>> tracker;

        for (int idx = 0; idx < n; idx++) {
            if (tracker.find(s[idx]) == tracker.end()) {
                tracker[s[idx]] = {idx, -1};
            } else {
                tracker[s[idx]] = {tracker[s[idx]].first, idx};
            }
        }

        int palindromeCnt = 0;

        for (auto it : tracker) {
            int firstIdx = it.second.first;
            int lastIdx = it.second.second;

            unordered_set<char> uniqueTracker;

            for (int idx = firstIdx + 1; idx < lastIdx; idx++) {
                uniqueTracker.insert(s[idx]);
            }

            palindromeCnt += uniqueTracker.size();
        }

        return palindromeCnt;
    }
};