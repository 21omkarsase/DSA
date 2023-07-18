// 859. Buddy Strings
// Easy
// 1.9K
// 1.2K
// Companies

// Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

// Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

//     For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

 

// Example 1:

// Input: s = "ab", goal = "ba"
// Output: true
// Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

// Example 2:

// Input: s = "ab", goal = "ab"
// Output: false
// Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

// Example 3:

// Input: s = "aa", goal = "aa"
// Output: true
// Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.

 

// Constraints:

//     1 <= s.length, goal.length <= 2 * 104
//     s and goal consist of lowercase letters.

// Accepted
// 154K
// Submissions
// 519.3K
// Acceptance Rate
// 29.7%

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size(), m = goal.size();

        if (n != m)
            return false;

        if (s == goal) {
            unordered_set<char> tracker(s.begin(), s.end());

            // when both are equal -> if any duplicate is present then only we can swap

            return tracker.size() < goal.size();
        }
        
        vector<int> diff;

        for (int idx = 0; idx < n; idx++) {
            if (s[idx] != goal[idx]) 
                diff.push_back(idx);
        }

        // it is possible to get 'goal' string when we have diff chars exactly at 2 positions

        return diff.size() == 2 && s[diff[0]] == goal[diff[1]] && goal[diff[0]] == s[diff[1]];
    }
};