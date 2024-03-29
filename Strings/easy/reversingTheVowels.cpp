// Given a string consisting of lowercase english alphabets, reverse only the vowels present in it and print the resulting string.

// Example 1:

// Input:
// S = "geeksforgeeks"
// Output: geeksforgeeks
// Explanation: The vowels are: e, e, o, e, e
// Reverse of these is also e, e, o, e, e.

// Example 2:

// Input:
// S = "practice"
// Output: prectica
// Explanation: The vowels are a, i, e
// Reverse of these is e, i, a.

// Example 3:

// Input:
// S = "bcdfg"
// Output: bcdfg
// Explanation: There are no vowels in S.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function modify() which takes the string S as input and returns the resultant string by reversing only the vowels present in S.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(|S|).

// Constraints:
// 1<=|S|<=105

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string modify(string s)
    {
        string vls = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
            {
                vls += s[i];
            }
        }
        int ptr = vls.length() - 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
            {
                s[i] = vls[ptr];
                ptr--;
            }
        }
        return s;
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
        cout << ob.modify(s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code End