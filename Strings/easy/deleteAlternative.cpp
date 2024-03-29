// Given a string S as input. Delete the characters at odd indices of the string.

// Example 1:

// Input: S = "Geeks"
// Output: "Ges"
// Explanation: Deleted "e" at index 1
// and "k" at index 3.
// Example 2:

// Input: S = "GeeksforGeeks"
// Output: "GesoGes"
// Explanation: Deleted e, k, f, r, e
// k at index 1, 3, 5, 7, 9, 11.

// Your Task:
// You dont need to read input or print anything. Complete the function delAlternate() which takes S as input parameter and returns the final string after deletion of characters at odd indices.

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(|S|)

// Constraints:
// 1<= |S| <=1000

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    string delAlternate(string S)
    {
        // code here
        string ans = "";
        for (int i = 0; i < S.length(); i += 2)
        {
            ans += S[i];
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.delAlternate(S) << endl;
    }
    return 0;
}
// } Driver Code Ends