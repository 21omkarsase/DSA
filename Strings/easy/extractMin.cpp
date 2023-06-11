// Given a alphanumeric string S, extract maximum numeric value from S.

// Example 1:

// Input:
// S = 100klh564abc365bg
// Output: 564
// Explanation: Maximum numeric value
// among 100, 564 and 365 is 564.
// Example 2:

// Input:
// S = abcdefg
// Output: -1
// Explanation: Return -1 if no numeric
// value is present.

// Your Task:
// You dont need to read input or print anything. Complete the function extractMaximum() which takes the string S as input parameters and returns the maximum numeric value. If it is not present in S, return -1.

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ |S| ≤ 104
// -1 ≤ output value ≤ 106

// View Bookmarked Problems
// Company Tags
//  Amazon

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int extractMaximum(string S)
    {
        // code here.
        int ans = 0, currMax = 0;
        bool flag = false;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] >= '0' and S[i] <= '9')
            {
                flag = true;
                currMax = (currMax * 10) + (S[i] - 48);
                ans = max(ans, currMax);
            }
            else
            {
                currMax = 0;
            }
        }
        if (ans > 0)
        {
            return ans;
        }
        else if (flag and ans == 0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
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
        cout << ob.extractMaximum(S) << endl;
    }
    return 0;
} // } Driver Code Ends