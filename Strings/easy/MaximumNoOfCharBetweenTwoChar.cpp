// Given a string containing lower and uppercase alphabets, the task is to find the maximum number of characters between any two same character in the string.

// Example 1:

// Input:
// S = "socks"
// Output: 3
// Explanation: There are 3 characters between
// the two occurrences of 's'.
// â€‹Example 2:

// Input:
// S = "FoR"
// Output: -1
// Explanation: No repeating character present.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxChars() which takes the string S as input and returns the maximum number of characters between any two same characters in the string.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1<=|S|<=105

// View Bookmarked Problems
// Company Tags
//  Zoho

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int maxChars(string s);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << maxChars(s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int maxChars(string S)
{
    // your code here
    int maxLen = -1;
    for (int i = 0; i < S.size(); i++)
    {
        int lastOcc = S.find_last_of(S[i]);
        if (i != lastOcc)
        {
            maxLen = max(maxLen, (lastOcc - i - 1));
        }
    }
    return maxLen;
}