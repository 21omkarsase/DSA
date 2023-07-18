// 844. Backspace String Compare
// Easy
// 6.5K
// 297
// Companies

// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

 

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".

// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".

// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".

 

// Constraints:

//     1 <= s.length, t.length <= 200
//     s and t only contain lowercase letters and '#' characters.

 

// Follow up: Can you solve it in O(n) time and O(1) space?
// Accepted
// 647.6K
// Submissions
// 1.3M
// Acceptance Rate
// 48.1%

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st1, st2;

        for (char ch : s) {
            if (ch == '#') {
                if (!st1.empty())
                    st1.pop();
                continue;
            }
            
            st1.push(ch);
        }

        for (char ch : t) {
            if (ch == '#') {
                if (!st2.empty())
                    st2.pop();
                continue;
            }

            st2.push(ch);
        }

        while (!st1.empty() && !st2.empty()) {
            if (st1.top() != st2.top())
                return false;

            st1.pop();
            st2.pop();
        }

        return st1.empty() && st2.empty();
    }
};


// using O(1) space


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size(), m = t.size();

        int string1Count = n, string2Count = m;

        for (int idx = n - 1; idx >= 0; idx--) {
            int hashCount = 0;
            
            while(idx >= 0 && s[idx] == '#') {
                idx--;
                hashCount++;
                string1Count--;
            }
            
            bool flag = true;

            while(idx >= 0 && hashCount > 0) {
                if (s[idx] == '#') {
                    hashCount += 1;
                } else {
                    s[idx] = '#';
                    hashCount--;
                }

                idx--;
                string1Count--;
                flag = false;
            }

            if (!flag)
                idx++;
        }

        for (int idx = m - 1; idx >= 0; idx--) {
            int hashCount = 0;
           
            while(idx >= 0 && t[idx] == '#') {
                idx--;
                hashCount++;
                string2Count--;
            }
          
            bool flag = true;
          
            while(idx >= 0 && hashCount) {
                if (t[idx] == '#') {
                    hashCount += 1;
                } else {
                    t[idx] = '#';
                    hashCount--;
                }

                idx--;
                string2Count--;
                flag = false;
            }

            if (!flag)
                idx++;
        }

        if (string1Count != string2Count)
            return false;

        int idx1 = 0, idx2 = 0;

        while (idx1 < n || idx2 < m) {
            if (idx1 < n && s[idx1] == '#') {
                idx1++;    
            }
            else if (idx2 < m && t[idx2] == '#') {
                idx2++;
            } else {
                if (s[idx1++] != t[idx2++]) {
                    return false;
                }
            }
        }

        return true;
    }
};