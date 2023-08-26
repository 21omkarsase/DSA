// 5. Longest Palindromic Substring
// Medium
// 26.7K
// 1.6K
// Companies

// Given a string s, return the longest
// palindromic
// substring
// in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:

// Input: s = "cbbd"
// Output: "bb"

 

// Constraints:

//     1 <= s.length <= 1000
//     s consist of only digits and English letters.

// Accepted
// 2.5M
// Submissions
// 7.8M
// Acceptance Rate
// 32.6%

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        string res = "";
        int resLength = 0;

        for (int idx = 0; idx < n; idx++) {
            int left = idx, right = idx;

            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > resLength) {
                    res = s.substr(left, right - left + 1);
                    resLength = right - left + 1;
                }

                left--;
                right++;
            }

            left = idx, right = idx + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > resLength) {
                    res = s.substr(left, right - left + 1);
                    resLength = right - left + 1;
                }

                left--;
                right++;
            }
        }

        return res;
    }
};