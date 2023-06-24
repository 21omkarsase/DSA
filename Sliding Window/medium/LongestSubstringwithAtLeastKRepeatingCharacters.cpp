// 395. Longest Substring with At Least K Repeating Characters
// Medium
// 5.5K
// 443
// Companies

// Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

 

// Example 1:

// Input: s = "aaabb", k = 3
// Output: 3
// Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.

// Example 2:

// Input: s = "ababbc", k = 2
// Output: 5
// Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

 

// Constraints:

//     1 <= s.length <= 104
//     s consists of only lowercase English letters.
//     1 <= k <= 105

// Accepted
// 193.1K
// Submissions
// 431.3K
// Acceptance Rate
// 44.8%

// Time Complexity : O(N * 26)
// Space Complexity : O(1) maximum 26 charcters will be included in map

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        
        unordered_set<int> uniqueCharactersSet(s.begin(), s.end());
        int uniqueCharactersCount = uniqueCharactersSet.size(), longestSubstringSize = 0;

        for (int uniqueCountLimit = 1; uniqueCountLimit <= uniqueCharactersCount; uniqueCountLimit++) {
            int left = 0, currUniqueCount = 0, elementsWithCountK = 0;
            
            unordered_map<char, int> tracker;

            for (int right = 0; right < n; right++) {
                if (currUniqueCount <= uniqueCountLimit) {
                    if (tracker.find(s[right]) == tracker.end()) {
                        currUniqueCount++;
                    }
                    tracker[s[right]]++;

                    if (tracker[s[right]] == k) 
                       elementsWithCountK++; 
                } else {
                    if (tracker[s[left]] == k)
                       elementsWithCountK--; 

                    tracker[s[left]]--;

                    if (tracker[s[left]] == 0) {
                        currUniqueCount--;
                        tracker.erase(s[left]);
                    } 

                    left++, right--;
                }

                if (currUniqueCount == uniqueCountLimit && elementsWithCountK == currUniqueCount)
                   longestSubstringSize = max(longestSubstringSize, right - left + 1); 
            }
        }
        
        return longestSubstringSize;
    }
};


// Time Complexity : O(N^2)
// Space Complexity : O(N)  for the recursive call stack

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();

        unordered_map<char, int> tracker;

        for (auto ch : s)
            tracker[ch]++;

        for (int idx = 0; idx < n; idx++) {
            if (tracker[s[idx]] < k) {
                int left = 0, right = 0;
                if(idx != 0) {
                    left = longestSubstring(s.substr(0, idx), k);
                }
                if(idx != n - 1) {
                    right = longestSubstring(s.substr(idx + 1), k);
                }
                return max(left, right);
            }
        }


        return s.size();
    }
};