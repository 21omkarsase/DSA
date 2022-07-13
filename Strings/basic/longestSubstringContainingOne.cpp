// Given a function that takes a binary string. The task is to return the longest size of contiguous substring containing only ‘1’.

// Input:
// The first line of input contains an integer T denoting the no of test cases.Then T test cases follow. Each test case contains a string S.

// Output:
// For each test case return the maximum length of required sub string.

// Constraints:
// 1<=T<=100
// 1<=|string length|<=104

// Example:
// Input:
// 2
// 110
// 11101110
// Output:
// 2
// 3

// View Bookmarked Problems
// Company Tags
//  Microsoft

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int maxlength(string s);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << maxlength(s) << endl;
    }
    return 0;
}
// } Driver Code Ends

int maxlength(string s)
{
    // your code here
    int currCount = 0, maxCount = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            currCount = 0;
        }
        else
        {
            currCount++;
            maxCount = max(maxCount, currCount);
        }
    }
    return maxCount;
}