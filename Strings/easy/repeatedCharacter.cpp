// Input:
// S = "geeksforgeeks"
// Output: g
// Explanation: g, e, k and s are the repeating
// characters. Out of these, g occurs first.
// Example 2:

// Input:
// S = "abcde"
// Output: -1
// Explanation: No repeating character present.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function firstRep() which takes the string S as input and returns the the first repeating character in the string. In case there's no repeating character present, return '#'.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1<=|S|<=105

// View Bookmarked Problems
// Company Tags
//  Goldman Sachs

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    char firstRep(string s)
    {
        char ans = '#';
        for (int i = 0; i < s.length(); i++)
        {
            if (s.substr(i + 1).find(s[i]) != -1)
            {
                ans = s[i];
                break;
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
        string s;
        cin >> s;
        Solution ob;
        char res = ob.firstRep(s);
        if (res == '#')
            cout << -1 << endl;
        else
            cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends