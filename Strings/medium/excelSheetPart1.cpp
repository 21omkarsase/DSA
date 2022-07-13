// Given a positive integer N, return its corresponding column title as it would appear in an Excel sheet.
// For N =1 we have column A, for 27 we have AA and so on.

// Note: The alphabets are all in uppercase.

// Example 1:

// Input:
// N = 51
// Output: AY
// Your Task:
// Complete the function ExcelColumn() which takes N as input and returns output string.

// Expected Time Complexity: O(Log(N))
// Expected Auxiliary Space: O(Log(N))

// Constraints:
// 1 ≤ N ≤ 107

// View Bookmarked Problems
// Company Tags
//  Amazon
// Topic Tags
//  Strings

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string ExcelColumn(int N)
    {
        string ans;
        while (N)
        {
            int rem = N % 26;
            if (rem == 0)
            {
                ans = 'Z' + ans;
                N = N / 26 - 1;
            }
            else
            {
                char c = 'A' + rem - 1;
                ans = c + ans;
                N /= 26;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.ExcelColumn(n) << endl;
    }
    return 0;
}
// } Driver Code Ends