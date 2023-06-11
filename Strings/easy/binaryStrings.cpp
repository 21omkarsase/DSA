// Given a binary string S. The task is to count the number of substrings that start and end with 1. For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.

// Example 1:

// Input:
// N = 4
// S = 1111
// Output: 6
// Explanation: There are 6 substrings from
// the given string. They are 11, 11, 11,
// 111, 111, 1111.
// Example 2:

// Input:
// N = 5
// S = 01101
// Output: 3
// Explanation: There 3 substrings from the
// given string. They are 11, 101, 1101.
// Your Task:
// The task is to complete the function binarySubstring() which takes the length of binary string n and a binary string a as input parameter and counts the number of substrings starting and ending with 1 and returns the count.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ |S| ≤ 104

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string a)
    {

        // Your code here
        int currOnes = 0, ans = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == '1')
            {
                if (currOnes > 0)
                {
                    ans += currOnes;
                }
                currOnes++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, n, count;
    string a;
    cin >> t;
    while (t--)
    {
        count = 0;
        cin >> n;
        cin >> a;
        Solution obj;
        cout << obj.binarySubstring(n, a) << endl;
    }
}
// } Driver Code Ends