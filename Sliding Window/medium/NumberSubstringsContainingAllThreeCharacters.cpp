// 1358. Number of Substrings Containing All Three Characters
// Medium
// 2.5K
// 39
// Companies

// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

// Example 3:

// Input: s = "abc"
// Output: 1

 

// Constraints:

//     3 <= s.length <= 5 x 10^4
//     s only consists of a, b or c characters.

// Accepted
// 59.6K
// Submissions
// 93.7K
// Acceptance Rate
// 63.6%


// Time Complexity : O(N^2)
// Space Complexity : O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int substrCount = 0;

        for(int idx1 = 0; idx1 < n; idx1++) {
            int acnt = 0, bcnt = 0, ccnt = 0;

            for(int idx2 = idx1; idx2 < n; idx2++) {
                s[idx2] == 'a' ? acnt++ : bcnt++;
                if(s[idx2] == 'c')
                    bcnt--, ccnt++;
                
                if(acnt > 0 && bcnt > 0 && ccnt > 0)
                    substrCount++;
            }
        }

        return substrCount;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int substrCount = 0;

        int left = 0, range = 0; 
        unordered_map<char, int> tracker;
        for(int right = 0; right < n; right++) {
            tracker[s[right]]++;

            while(tracker['a'] > 0 && tracker['b'] > 0 && tracker['c'] > 0) {
                tracker[s[left++]]--;
                range++;
            }
            substrCount += range;
        }
     
        return substrCount;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int substrCount = 0;
        
        int left = 0;
        unordered_map<char, int> tracker;
        for(int right = 0; right < n; right++) {
            tracker[s[right]]++;

            if(right - left >= 2){
                if(tracker['a'] > 0 && tracker['b'] > 0 && tracker['c'] > 0) {
                    int duplicates = tracker['a'] + tracker['b'] + tracker['c'] - 3;
                    substrCount += ((right - left - 1 - duplicates) + (n - right - 1));
                    if(right - left > 2) 
                        tracker[s[right--]]--;
                    
                    tracker[s[left++]]--;
                }
            }            
        }

        return substrCount;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int substrCount = 0;
        
        int left = 0;
        int aCnt = 0, bCnt = 0, cCnt = 0;
        for(int right = 0; right < n; right++) {
            s[right] == 'a' ? aCnt++ : bCnt++;
            if(s[right] == 'c')
                bCnt--, cCnt++;

            if(right - left >= 2){
                if(aCnt > 0 && bCnt > 0 && cCnt > 0) {
                    int duplicates = aCnt + bCnt + cCnt - 3;
                    substrCount += ((right - left - 1 - duplicates) + (n - right - 1));
                    if(right - left > 2) {
                        s[right] == 'a' ? aCnt-- : bCnt--;
                        if(s[right] == 'c')
                            bCnt++, cCnt--;
                        right --;
                    }
                    
                    s[left] == 'a' ? aCnt-- : bCnt--;
                    if(s[left++] == 'c')
                        bCnt++, cCnt--;
                }
            }            
        }

        return substrCount;
    }
};