// Remove all characters except the numeric characters from an alphanumeric string.

// Example 1:

// Input: S = "AA1d23cBB4"
// Output: 1234
// Explanation: Remove all chacactres
// other than numbers
// Example 2:

// Input: S = "a1b2c3"
// Output: 123
// Explanation: Remove all chacactres
// other than numbers
// Your task:
// Your task is to complete the function string() which takes a single string as input and returns the string. You need not take any input or print anything.

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= |S| <= 105

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string removeCharacters(string S)
    {
        // Your code goes here
        string ans = "";
        for (int i = 0; i < S.length(); i++)
        {
            if ((S[i] >= 'a' and S[i] <= 'z') or (S[i] >= 'A' and S[i] <= 'Z'))
            {
                continue;
            }
            ans += S[i];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.removeCharacters(s) << "\n";
    }

    return 0;
} // } Driver Code Ends