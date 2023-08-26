// 2663. Lexicographically Smallest Beautiful String
// Hard
// 159
// 13
// Companies

// A string is beautiful if:

//     It consists of the first k letters of the English lowercase alphabet.
//     It does not contain any substring of length 2 or more which is a palindrome.

// You are given a beautiful string s of length n and a positive integer k.

// Return the lexicographically smallest string of length n, which is larger than s and is beautiful. If there is no such string, return an empty string.

// A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ, a has a character strictly larger than the corresponding character in b.

//     For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character, and d is greater than c.

 

// Example 1:

// Input: s = "abcz", k = 26
// Output: "abda"
// Explanation: The string "abda" is beautiful and lexicographically larger than the string "abcz".
// It can be proven that there is no string that is lexicographically larger than the string "abcz", beautiful, and lexicographically smaller than the string "abda".

// Example 2:

// Input: s = "dc", k = 4
// Output: ""
// Explanation: It can be proven that there is no string that is lexicographically larger than the string "dc" and is beautiful.

 

// Constraints:

//     1 <= n == s.length <= 105
//     4 <= k <= 26
//     s is a beautiful string.

// Accepted
// 3.7K
// Submissions
// 9.4K
// Acceptance Rate
// 39.4%

// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
    bool isValid(int idx, int n, string &s, int k) {
        if (idx - 1 >= 0 && s[idx] == s[idx - 1])
            return false;
        else if (idx - 2 >= 0) {
            if (s[idx] == s[idx - 1] || s[idx] == s[idx - 2] || s[idx - 1] == s[idx - 2])
                return false;
        }
        
        return true;
    }
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        int feasible = -1;
        
        for (int idx = n - 1; idx >= 0; idx--) {
            char og = s[idx];

            for (char ch = og + 1; ch < 'a' + k; ch++) {
                s[idx] = ch;

                if (s[idx] != og) {
                    if (isValid(idx, n, s, k)) {
                        feasible = idx;
                        for (int idx = feasible + 1; idx < n; idx++) {
                            s[idx] = 'a';
                        }

                        for (int idx = feasible + 1; idx < n; idx++) {
                            s[idx] = 'a';
                            for (char ch = 'a'; ch < 'a' + k; ch++) {
                                s[idx] = ch;
                                
                                if (isValid(idx, n, s, k)) {
                                    break;
                                }
                            }
                        }
                        return s;
                    }
                }
            }
        }

        return "";
    }
};


// [8,50,65,85,8,73,55,50,29,95,5,68,52,79]
// 74