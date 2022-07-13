// Given a sentence containing several words and numbers. Find the largest number among them which does not contain 9.

// Example 1:

// Input:
// Sentence="This is alpha 5057 and 97"
// Output:
// 5057
// Explanation:
// 5057 is the only number that does
// not have a 9.
// Example 2:

// Input:
// Sentence="Another input 9007"
// Output:
// -1
// Explanation:
// Since there is no number that
// does not contain a 9,output is -1.
// Your task:
// You don't need to read input or print anything. Your task is to complete the function ExtractNumber() which takes a string S as input parameter and returns the largest number that does not contain a 9. If no such number exists, return -1.

// Expected Time Complexity:O(N)
// Expected Auxillary Space:O(1)

// Constraints:
// 1<=Length of Sentence<=106
// 1<=answer<=1018

// View Bookmarked Problems
// Company Tags
//  TCS

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long ExtractNumber(string S)
    {
        int n = S.length();
        long long finalAns = INT_MIN;
        string ans;
        for (int i = 0; i < n; i++)
        {
            if (isdigit(S[i]))
            {
                ans += S[i];
                continue;
            }
            else if (S[i] == ' ' and !ans.empty())
            {
                for (int i = 0; i < ans.length(); i++)
                {
                    if (ans[i] == '9')
                    {
                        ans = "";
                        break;
                    }
                }
                if (!ans.empty())
                {
                    finalAns = max(finalAns, stoll(ans));
                    ans = "";
                }
            }
        }

        for (int i = 0; i < ans.length(); i++)
        {
            if (ans[i] == '9')
            {
                ans = "";
                break;
            }
        }
        if (!ans.empty())
        {
            finalAns = max(finalAns, stoll(ans));
            ans = "";
        }

        return finalAns == INT_MIN ? -1 : finalAns;
    }
};

// { Driver Code Starts.
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends