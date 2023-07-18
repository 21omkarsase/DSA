// Longest Repeating Subsequence
// MediumAccuracy: 48.54%Submissions: 91K+Points: 4
// POTD July Placement Special : All POTD in the month of July are based on popular interview questions. Solve every day to ace the upcoming Placement Season !

// Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

// The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

// Example 1:

// Input:
// str = "axxzxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x z x y 
// 0 1 2 3 4 5

// The longest subsequence is "xx". 
// It appears twice as explained below.

// subsequence A
// x x
// 0 1  <-- index of subsequence A
// ------
// 1 2  <-- index of str 


// subsequence B
// x x
// 0 1  <-- index of subsequence B
// ------
// 2 4  <-- index of str 

// We are able to use character 'x' 
// (at index 2 in str) in both subsequences
// as it appears on index 1 in subsequence A 
// and index 0 in subsequence B.

// Example 2:

// Input:
// str = "axxxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x x y 
// 0 1 2 3 4

// The longest subsequence is "xx". 
// It appears twice as explained below.

// subsequence A
// x x
// 0 1  <-- index of subsequence A
// ------
// 1 2  <-- index of str 


// subsequence B
// x x
// 0 1  <-- index of subsequence B
// ------
// 2 3  <-- index of str 

// We are able to use character 'x' 
// (at index 2 in str) in both subsequences
// as it appears on index 1 in subsequence A 
// and index 0 in subsequence B.


// Your Task:
// You don't need to read or print anything. Your task is to complete the LongestRepeatingSubsequence() which takes str as input parameter and returns the length of the longest repeating subsequnece.


// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(n2)


//                      LCS

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int calculateLongestRepeatingSubsequence(int idx1, int idx2, string &str, vector<vector<int>> &dp) {
        if (idx1 >= str.size() || idx2 >= str.size())
            return 0;
            
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        if (idx1 != idx2 && str[idx1] == str[idx2]) {
            return 1 + calculateLongestRepeatingSubsequence(idx1 + 1, idx2 + 1, str, dp);
        }
        
        return dp[idx1][idx2] = max(calculateLongestRepeatingSubsequence(idx1 + 1, idx2, str, dp), calculateLongestRepeatingSubsequence(idx1, idx2 + 1, str, dp));
    }
public:
    int LongestRepeatingSubsequence(string str){
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return calculateLongestRepeatingSubsequence(0, 0, str, dp);
    }

};

//{ Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends