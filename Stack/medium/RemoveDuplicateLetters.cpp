// 316. Remove Duplicate Letters
// Attempted
// Medium
// Topics
// Companies
// Hint

// Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
// the smallest in lexicographical order
// among all possible results.

 

// Example 1:

// Input: s = "bcabc"
// Output: "abc"

// Example 2:

// Input: s = "cbacdcbc"
// Output: "acdb"

 

// Constraints:

//     1 <= s.length <= 104
//     s consists of lowercase English letters.

 

// Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
// Accepted
// 269.9K
// Submissions
// 571.4K
// Acceptance Rate
// 47.2%

// Time Complexity : O(2^N)
// Space Complexity  : O(N) + O(N * N)

class Solution {
    void getLexicoSmallestString(int idx, string &ans, string temp, unordered_map<char, int> &tracker, string &s) {
        if (idx == s.size()) {
            if (ans == "" || (ans != "" && ans > temp)) {
                ans = temp;
            }
            return;
        }

        if (tracker[s[idx]] == 1) {
            tracker[s[idx]]--;
            getLexicoSmallestString(idx + 1, ans, temp + s[idx], tracker, s);
            tracker[s[idx]]++;
        }
        else if (tracker[s[idx]] > 1) {
            int t = tracker[s[idx]];
            
            tracker[s[idx]] = 0;
            getLexicoSmallestString(idx + 1, ans, temp + s[idx], tracker, s);

            tracker[s[idx]] = t - 1;
            
            getLexicoSmallestString(idx + 1, ans, temp, tracker, s);
            tracker[s[idx]] = t;
        }
        else if (tracker[s[idx]] == 0){
            getLexicoSmallestString(idx + 1, ans, temp, tracker, s);
        }
    }
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        
        unordered_map<char, int> tracker;

        for (auto ch : s) {
            tracker[ch]++;
        }

        getLexicoSmallestString(0, ans, "", tracker, s);

        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(3N)

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        stack<int> st;

        unordered_set<char> tracker;
        unordered_map<char, int> freq;

        for (auto ch : s) {
            freq[ch]++;
        }

        for (int idx = 0; idx < n; idx++) {
            if (tracker.find(s[idx]) != tracker.end()) {
                freq[s[idx]]--;
                continue;
            }

            while (!st.empty() && s[st.top()] > s[idx] && freq[s[st.top()]] > 1) {
                tracker.erase(s[st.top()]);
                freq[s[st.top()]]--;

                st.pop();
            }

            if (tracker.find(s[idx]) == tracker.end()) {
                tracker.insert(s[idx]);
                st.push(idx);
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans += s[st.top()];
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};