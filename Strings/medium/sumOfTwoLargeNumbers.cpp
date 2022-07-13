// Given two strings denoting non-negative numbers X and Y. Calculate the sum of X and Y.

// Example 1:

// Input:
// X = "25", Y = "23"
// Output:
// 48
// Explanation:
// The sum of 25 and 23 is 48.
// Example 2:

// Input:
// X = "2500", Y = "23"
// Output:
// 2523
// Explanation:
// The sum of 2500 and 23 is 2523.

// Your Task:
// Your task is to complete the function findSum() which takes two strings as inputs and returns the string without leading zeros. You do not need to take any input or print anything.

// Expected Time Complexity: O(|X| + |Y|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= |X|, |Y| <= 105

// View Bookmarked Problems
// Company Tags
//  Amazon Microsoft Zoho

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string findSum(string X, string Y)
    {
        bool allAreZeros = true;
        for (int i = 0; i < X.size(); i++)
        {
            if (X[i] != '0')
            {
                allAreZeros = false;
            }
        }
        for (int i = 0; i < Y.size(); i++)
        {
            if (Y[i] != '0')
            {
                allAreZeros = false;
            }
        }
        string ans;
        if (allAreZeros)
        {
            ans += '0';
            return ans;
        }
        else
        {
            int n1 = X.length() - 1;
            int n2 = Y.length() - 1;
            int carry = 0;
            while (n1 >= 0 || n2 >= 0)
            {
                if (n1 < 0)
                {
                    ans.push_back((((Y[n2] - 48) + carry) % 10) + 48);
                    carry = ((Y[n2] - 48) + carry) / 10;
                    n2--;
                }
                else if (n2 < 0)
                {
                    ans.push_back((((X[n1] - 48) + carry) % 10) + 48);
                    carry = ((X[n1] - 48) + carry) / 10;
                    n1--;
                }
                else
                {
                    ans.push_back((((X[n1] - 48) + (Y[n2] - 48) + carry) % 10) + 48);
                    carry = ((X[n1] - 48) + (Y[n2] - 48) + carry) / 10;
                    n1--;
                    n2--;
                }
            }
            if (carry)
            {
                ans.push_back(carry + 48);
            }
            bool gotNum = false;
            string finalAns;
            for (int i = ans.length() - 1; i >= 0; i--)
            {
                if (ans[i] != '0')
                {
                    gotNum = true;
                }
                if (!gotNum and ans[i] == '0')
                {
                    continue;
                }
                finalAns += ans[i];
            }
            return finalAns;
        }
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
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
} // } Driver Code Ends