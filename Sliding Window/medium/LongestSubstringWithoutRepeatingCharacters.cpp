// 3. Longest Substring Without Repeating Characters
// Medium
// 34.8K
// 1.5K
// Companies

// Given a string s, find the length of the longest
// substring
// without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 

// Constraints:

//     0 <= s.length <= 5 * 104
//     s consists of English letters, digits, symbols and spaces.

// Accepted
// 4.6M
// Submissions
// 13.6M
// Acceptance Rate
// 33.8%

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int left = 0, longestSubstring = 0;
        unordered_map<char, int> tracker;

        for (int right = 0; right < n; right++) {
            tracker[s[right]]++;

            if (tracker[s[right]] > 1) {
                while (s[left] != s[right] && left < right) {
                    tracker[s[left++]]--;
                }

                tracker[s[left++]]--;
            }

            longestSubstring = max(longestSubstring, right - left + 1);
        }

        return longestSubstring;
    }
};