// Longest K unique characters substring
// MediumAccuracy: 34.65%Submissions: 106K+Points: 4
// 30% Off on all premium courses! Enrol today and utilize this offer before placement ends

// Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

// Example 1:

// Input:
// S = "aabacbebebe", K = 3
// Output: 
// 7
// Explanation: 
// "cbebebe" is the longest substring with 3 distinct characters.

// Example 2:

// Input: 
// S = "aaaa", K = 2
// Output: -1
// Explanation: 
// There's no substring with 2 distinct characters.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestKSubstr() which takes the string S and an integer K as input and returns the length of the longest substring with exactly K distinct characters. If there is no substring with exactly K distinct characters then return -1.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(|S|).

// Constraints:
// 1 ≤ |S| ≤ 105
// 1 ≤ K ≤ 26
// All characters are lowercase latin characters.

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n = s.size();
        
        int left = 0, longestStrLength = -1;
        unordered_map<char, int> tracker;
        
        for (int right = 0; right < n; right++) {
            tracker[s[right]]++;
            
            while (left <= right && tracker.size() > k) {
                tracker[s[left]]--;
                
                if (tracker[s[left]] == 0) {
                    tracker.erase(s[left]);
                }
                
                left++;
            }
            
            if (tracker.size() == k) {
                longestStrLength = max(longestStrLength, right - left + 1);
            }
        }
        
        return longestStrLength;
    }
};