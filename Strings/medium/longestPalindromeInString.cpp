// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).

// Example 1:

// Input:
// S = "aaaabbaa"
// Output: aabbaa
// Explanation: The longest Palindromic
// substring is "aabbaa".
// Example 2:

// Input:
// S = "abc"
// Output: a
// Explanation: "a", "b" and "c" are the
// longest palindromes with same length.
// The result is the one with the least
// starting index.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestPalin() which takes the string S as input and returns the longest palindromic substring of S.

// Expected Time Complexity: O(|S|2).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ |S| ≤ 103

// View Bookmarked Problems
// Company Tags
//  Accolite Amazon Groupon MakeMyTrip Microsoft Qualcomm Samsung Visa Walmart Zoho Google
// Topic Tags
//  Strings Palindrome

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isPalindrome(string S, int l, int r)
    {
        while (l < r)
        {
            if (S[l++] != S[r--])
            {
                return false;
            }
        }
        return true;
    }
    string longestPalin(string S)
    {
        int n = S.size(), maxLen = 1;
        string longStr;
        longStr += S[0];
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isPalindrome(S, i, j) and (j - i + 1) > maxLen)
                {
                    maxLen = j - i + 1;
                    longStr = S.substr(i, (j - i + 1));
                }
            }
        }
        return longStr;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalin(S) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends