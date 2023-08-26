// 28. Find the Index of the First Occurrence in a String
// Easy
// 4.5K
// 233
// Companies

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.

 

// Constraints:

//     1 <= haystack.length, needle.length <= 104
//     haystack and needle consist of only lowercase English characters.

// Accepted
// 1.9M
// Submissions
// 4.7M
// Acceptance Rate
// 40.2%

// Time Complexity : O(N + M)
// Space Complexity : O(N)

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }

        int n = haystack.size(), m = needle.size();

        vector<int> lps(m, 0);

        int prevLps = 0, idx = 1;

        while (idx < m) {
            if (needle[idx] == needle[prevLps]) {
                lps[idx] = prevLps + 1;
                idx++;
                prevLps++;
            }
            else if (prevLps == 0) {
                lps[idx] = 0;
                idx++;
            }
            else {
                prevLps = lps[prevLps - 1];
            }
        }

        int idx1 = 0, idx2 = 0;

        while (idx1 < n) {
            if (haystack[idx1] == needle[idx2]) {
                idx1++, idx2++;
            }
            else if (idx2 == 0) {
                idx1++;
            }
            else {
                idx2 = lps[idx2 - 1];
            }

            if (idx2 == m) {
                return idx1 - m;
            }
        }

        return -1;
    }
};