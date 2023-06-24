// 76. Minimum Window Substring
// Hard
// 15.3K
// 640
// Companies

// Given two strings s and t of lengths m and n respectively, return the minimum window
// substring
// of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.

// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

 

// Constraints:

//     m == s.length
//     n == t.length
//     1 <= m, n <= 105
//     s and t consist of uppercase and lowercase English letters.

 

// Follow up: Could you find an algorithm that runs in O(m + n) time?
// Accepted
// 1M
// Submissions
// 2.5M
// Acceptance Rate
// 41.0%

// Time Complexity : O(N*26 + N*26)
// Space Complexity : O(N + M)

class Solution {
    bool checkTrackerStatus(unordered_map<char, int> &tracker1, unordered_map<char, int> &tracker2) {
        for (auto pair1 : tracker2) {
            char ch = pair1.first;
            int count = pair1.second;
            
            if (tracker1.find(ch) == tracker1.end() || tracker1[ch] < tracker2[ch])
                return false;
        }

        return true;
    }
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();

        int left = 0, minWindowSize = INT_MAX, start = 0, end = n - 1;
        unordered_map<char, int> tracker1, tracker2;

        for (char ch : t) 
            tracker2[ch]++;
        
        for (int right = 0; right < n; right++) {
            tracker1[s[right]]++;

            bool flag = false;

            while (checkTrackerStatus(tracker1, tracker2) && left <= right) {
                if (right - left + 1 < minWindowSize) {
                    minWindowSize = right - left + 1;
                    start = left, end = right;
                }

                tracker1[s[left++]]--;
                flag = true;
            }
        }

        return minWindowSize == INT_MAX ? "" : s.substr(start, end - start + 1);
    }
};

// Time Complexity : O(2N)
// Space Complexity : O(M)

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();

        int left = 0, minWindowSize = INT_MAX, start = 0, end = n - 1;
        unordered_map<char, int> tracker1, tracker2;
        
        for (char ch : t) 
            tracker2[ch]++;
        
        int totalCharsReq = tracker2.size(), currCharCount = 0;

        for (int right = 0; right < n; right++) {
            if(tracker2.find(s[right]) != tracker2.end()) {
                tracker1[s[right]]++;

                if (tracker1[s[right]] == tracker2[s[right]]) 
                    currCharCount++;
            }
            
            if (currCharCount == totalCharsReq) {
                while (currCharCount == totalCharsReq && left <= right) {
                    if (right - left + 1 < minWindowSize) {
                        minWindowSize = right - left + 1;
                        start = left, end = right;
                    }
                    if (tracker2.find(s[left]) != tracker2.end()) {
                        tracker1[s[left]]--;

                        if(tracker1[s[left]] < tracker2[s[left]])
                            currCharCount--;
                    }
                    
                    if (tracker1[s[left]] == 0) 
                        tracker1.erase(s[left]);

                    left++;
                }
            }
        }

        return minWindowSize == INT_MAX ? "" : s.substr(start, end - start + 1);
    }
};












