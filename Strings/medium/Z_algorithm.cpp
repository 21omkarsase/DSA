// Search Pattern (Z-algorithm)
// MediumAccuracy: 59.22%Submissions: 7K+Points: 4
// Win from a prize pool of INR 15K and get exciting merch! Register your team for Hack-A-Thon today!

// Given two strings, one is a text string and the other is a pattern string. The task is to print the indexes of all the occurrences of the pattern string in the text string. For printing, Starting Index of a string should be taken as 1.

// Example 1:

// Input:
// S = "batmanandrobinarebat", pat = "bat"
// Output: 1 18
// Explanation: The string "bat" occurs twice
// in S, one starts are index 1 and the other
// at index 18. 

// Example 2:

// Input: 
// S = "abesdu", pat = "edu"
// Output: -1
// Explanation: There's not substring "edu"
// present in S.


// Your Task:
// You don't need to read input or print anything. Your task is to complete the function search() which takes the string S and the string pat as inputs and returns an array denoting the start indices (1-based) of substring pat in the string S. 

// Note: You don't need to return -1 yourself when there are no possible answers, just return an empty list.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(|S|).


// Constraints:
// 1 ≤ |S| ≤ 105
// 1 ≤ |pat| ≤ |S|


// Time Complexity : O(2N)
// Space Complexity : O(N)
class Solution
{
    vector<int> calculateZTable(const int &n, const int &m, const string &txt, const string &pat) {
        string temp = pat + '#' + txt;
        int len = temp.size();
        
        vector<int> z(len, 0);
        int left = 0, right = 0;
        
        for (int idx = 1; idx < len; idx++) {
            if (idx <= right) {
                z[idx] = min(z[idx - left], right - idx + 1);
            }
            
            while (idx + z[idx] < len && temp[idx + z[idx]] == temp[z[idx]]) {
                z[idx]++;
            }
            
            if (idx + z[idx] - 1 > right) {
                left = idx;
                right = idx + z[idx] - 1;
            }
        }
        
        return z;
    }
    public:
        vector <int> search(string pat, string txt)
        {
            int n = txt.size(), m = pat.size();
            
            vector<int> z = calculateZTable(n, m, txt, pat);
            int len = z.size();
            
            vector<int> ans;
            
            for (int idx = 1; idx < len; idx++) {
                if (z[idx] == m) {
                    ans.push_back(idx - m);
                }
            }
            
            return ans;
        }
     
};


