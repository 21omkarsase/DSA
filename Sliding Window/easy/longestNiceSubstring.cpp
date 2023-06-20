// 1763. Longest Nice Substring
// Easy
// 1.1K
// 734
// Companies

// A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

// Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.

 

// Example 1:

// Input: s = "YazaAay"
// Output: "aAa"
// Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
// "aAa" is the longest nice substring.

// Example 2:

// Input: s = "Bb"
// Output: "Bb"
// Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.

// Example 3:

// Input: s = "c"
// Output: ""
// Explanation: There are no nice substrings.

 

// Constraints:

//     1 <= s.length <= 100
//     s consists of uppercase and lowercase English letters.

// Accepted
// 39.6K
// Submissions
// 64.9K
// Acceptance Rate
// 61.0%

// Time Complexity : O(N^3)
// Space Complexity : O(N)


//                   Divide & Conquer
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        if(n < 2)
            return "";

        unordered_set<char> tracker(s.begin(), s.end());

        for(int idx = 0; idx < s.size(); idx++){
            char oppositeCase = (char) s[idx] ^ 32;

            if(tracker.find(oppositeCase) == tracker.end()){
                string leftStr = longestNiceSubstring(s.substr(0, idx));
                string rightStr = longestNiceSubstring(s.substr(idx + 1));

                if(leftStr.size() >= rightStr.size())
                    return leftStr;
                else
                    return rightStr;
            }
        }

        return s;
    }
};


class Solution {
    void checkForNiceSubstr(int idx1, int idx3, string &longestNiceSubstr, int &startIdx, string &s, unordered_map<char,int> &tracker){
        bool flag = true;
        string substring = "";
        for(int idx2 = idx1; idx2 <= idx3; idx2++){
            if(tracker.find((char) s[idx2] ^ 32)  == tracker.end()){
                flag = false;
                break;
            }

            // if((s[idx2] >= 'a' && s[idx2] <= 'z' && tracker.find(s[idx2] - 32) == tracker.end()) ||
            //     (s[idx2] >= 'A' && s[idx2] <= 'Z' && tracker.find(s[idx2] + 32) == tracker.end())){
            //     flag = false;
            //     break;
            // }

            substring += s[idx2];
        }

        if(flag){
            if((idx3 - idx1 + 1) == longestNiceSubstr.size() && idx1 < startIdx)
                longestNiceSubstr = substring, startIdx = idx1;

            if(idx3 - idx1 + 1 > longestNiceSubstr.size())
                longestNiceSubstr = substring, startIdx = idx1;
        }
    }

public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        
        string longestNiceSubstr = ""; 
        int startIdx = 101;
        for(int idx1 = 0; idx1 < n; idx1++){
            unordered_map<char, int> tracker;
            for(int idx2 = idx1; idx2 < n; idx2++){
                tracker[s[idx2]]++;
                checkForNiceSubstr(idx1, idx2, longestNiceSubstr, startIdx, s, tracker);
            }
        }

        return longestNiceSubstr;
    }
};