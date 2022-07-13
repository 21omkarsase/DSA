// Given a string S consisting of lowercase Latin Letters. Return the first non-repeating character in S. If there is no non-repeating character, return '$'.

// Example 1:

// Input:
// S = hello
// Output: h
// Explanation: In the given string, the
// first character which is non-repeating
// is h, as it appears first and there is
// no other 'h' in the string.
// Example 2:

// Input:
// S = zxvczbtxyzvy
// Output: c
// Explanation: In the given string, 'c' is
// the character which is non-repeating.
// Your Task:
// You only need to complete the function nonrepeatingCharacter() that takes string S as a parameter and returns the character. If there is no non-repeating character then return '$' .

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Number of distinct characters).
// Note: N = |S|

// Constraints:
// 1 <= N <= 103

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        map<char, int> m;
        int minIdx = INT_MAX;
        string ans;
        for (int i = 0; i < S.length(); i++)
        {
            m[S[i]]++;
        }
        for (auto it : m)
        {
            if (it.second == 1)
            {
                if (S.find(it.first) < minIdx)
                {
                    minIdx = S.find(it.first);
                    ans = it.first;
                }
            }
        }
        if (ans.size() == 0)
        {
            return '$';
        }
        return ans[0];
    }
};

// { Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonrepeatingCharacter(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends