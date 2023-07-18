// 2781. Length of the Longest Valid Substring
// Hard
// 262
// 3
// Companies

// You are given a string word and an array of strings forbidden.

// A string is called valid if none of its substrings are present in forbidden.

// Return the length of the longest valid substring of the string word.

// A substring is a contiguous sequence of characters in a string, possibly empty.

 

// Example 1:

// Input: word = "cbaaaabc", forbidden = ["aaa","cb"]
// Output: 4
// Explanation: There are 9 valid substrings in word: "c", "b", "a", "ba", "aa", "bc", "baa", "aab", and "aabc". The length of the longest valid substring is 4. 
// It can be shown that all other substrings contain either "aaa" or "cb" as a substring. 

// Example 2:

// Input: word = "leetcode", forbidden = ["de","le","e"]
// Output: 4
// Explanation: There are 11 valid substrings in word: "l", "t", "c", "o", "d", "tc", "co", "od", "tco", "cod", and "tcod". The length of the longest valid substring is 4.
// It can be shown that all other substrings contain either "de", "le", or "e" as a substring. 

 

// Constraints:

//     1 <= word.length <= 105
//     word consists only of lowercase English letters.
//     1 <= forbidden.length <= 105
//     1 <= forbidden[i].length <= 10
//     forbidden[i] consists only of lowercase English letters.

// Accepted
// 5.5K
// Submissions
// 17.9K
// Acceptance Rate
// 30.7%

// Time Complexity : O(N*L^3)
// Space Complexity : O(N*L)
// L -> max len of forbidden string element

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n = word.size(), m = forbidden.size();
        int mxLen = 0;

        unordered_set<string> tracker;
        
        for (int idx = 0; idx < m; idx++) {
            tracker.insert(forbidden[idx]);

            mxLen = max((int) forbidden[idx].size(), mxLen);
        }

        int left = 0, longestValidLength = 0;

        for (int right = 0; right < n; right++) {
            string str = "";
            bool flag = true;

            for (int idx = right; idx >= max(left, right - 10 + 1); idx--) {
                str = word[idx] + str;

                if (tracker.find(str) != tracker.end()) {
                    left = idx + 1;
                    flag = false;
                    break;
                }
            }

            longestValidLength = max(longestValidLength, right - left + 1);
        }

        return longestValidLength;
    }
};