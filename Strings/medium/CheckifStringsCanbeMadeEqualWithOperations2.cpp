// 2840. Check if Strings Can be Made Equal With Operations II
// Medium
// 160
// 3
// Companies

// You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.

// You can apply the following operation on any of the two strings any number of times:

//     Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.

// Return true if you can make the strings s1 and s2 equal, and false otherwise.

 

// Example 1:

// Input: s1 = "abcdba", s2 = "cabdab"
// Output: true
// Explanation: We can apply the following operations on s1:
// - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
// - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
// - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.

// Example 2:

// Input: s1 = "abe", s2 = "bea"
// Output: false
// Explanation: It is not possible to make the two strings equal.

 

// Constraints:

//     n == s1.length == s2.length
//     1 <= n <= 105
//     s1 and s2 consist only of lowercase English letters.

// Accepted
// 19.8K
// Submissions
// 37.4K
// Acceptance Rate
// 53.1%

// Time Complexity : O() 
// Space Complexity : O() 

class Solution {
    bool isPossible(int idx, string &s1, const string &s2) {
        if (idx >= s1.size()) {
            return true;
        }
        
        if (s1[idx] == s2[idx]) {
            return isPossible(idx + 1, s1, s2);
        }
        
        for (int k = idx + 2; k < s1.size(); k += 2) {
            if (s1[k] == s2[idx]) {
                swap(s1[k], s1[idx]);
                
                if (isPossible(idx + 1, s1, s2)) {
                    return true;
                }
                
                swap(s1[k], s1[idx]);
            }
        }
        
        return false;
    }
public:
    bool checkStrings(string s1, string s2) {
        return isPossible(0, s1, s2) || isPossible(0, s2, s1);
    }
};


// Time Complexity : O()
// Space Complexity : O() 

class Solution {
    bool isPossible(int idx, string &s1, const string &s2) {
        if (idx >= s1.size()) {
            return true;
        }
        
        if (s1[idx] == s2[idx]) {
            return isPossible(idx + 1, s1, s2);
        }
        
        for (int k = idx + 2; k < s1.size(); k += 2) {
            if (s1[k] == s2[idx]) {
                swap(s1[k], s1[idx]);
                
                if (isPossible(idx + 1, s1, s2)) {
                    return true;
                }
                
                swap(s1[k], s1[idx]);
            }
        }
        
        return false;
    }
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        string temp1 = "", temp2 = "", temp3 = "", temp4 = "";

        for (int idx = 0; idx < n; idx += 2) {
            temp1 += s1[idx]; 
            temp3 += s2[idx]; 
            
            if (idx + 1 < n) {
                temp2 += s1[idx + 1];
                temp4 += s2[idx + 1];
            }
        }

        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        sort(temp3.begin(), temp3.end());
        sort(temp4.begin(), temp4.end());

        return temp1 == temp3 && temp2 == temp4;
    }
};

