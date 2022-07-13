// Given a string S. For each index i(1<=i<=N-1), erase it if s[i] is equal to s[i-1] in the string.

// Example 1:

// Input:
// S = aabb
// Output:  ab
// Explanation: 'a' at 2nd position is
// appearing 2nd time consecutively.
// Similiar explanation for b at
// 4th position.

// Example 2:

// Input:
// S = aabaa
// Output:  aba
// Explanation: 'a' at 2nd position is
// appearing 2nd time consecutively.
// 'a' at fifth position is appearing
// 2nd time consecutively.

// Your Task:
// You dont need to read input or print anything. Complete the function removeConsecutiveCharacter() which accepts a string as input parameter and returns modified string.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(|S|).

// Constraints:
// 1<=|S|<=105
// All characters are lowercase alphabets.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        for (int i = 0; i < S.length() - 1; i++)
        {
            if (S[i] == S[i + 1])
            {
                S.erase(S.begin() + i);
                i--;
            }
        }
        return S;
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
        cout << ob.removeConsecutiveCharacter(s) << endl;
    }
}

// } Driver Code Ends