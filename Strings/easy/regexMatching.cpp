// Given a pattern string and a test string, If the pattern is preceded by a ^, the pattern(excluding the ^) will be matched with the starting position of the text string. Similarly, if it is preceded by a $, the pattern(excluding the ^) will be matched with the ending position of the text string. If no such markers are present, it will be checked whether pattern is a substring of test.

// Example 1:

// Input:
// P = "^coal"
// S = "coaltar"
// Output:
// 1
// Explanation:
// The pattern "coal" is present at the
// beginning of the string, so Output is 1.
// Example 2:

// Input:
// P = "tar$"
// S = "coaltar"
// Output:
// 1
// Explanation:
// The pattern "tar" is present at the
// end of the string, so Output is 1.
// Example 3:

// Input:
// P = "rat"
// S = "algorate"
// Output:
// 1
// Explanation:
// The pattern "rat" is present as a
// substring of the string S,
// so Output is 1.
// Example 4:

// Input:
// P = "abcd"
// S = "efgh"
// Output:
// 0
// Explanation:
// There is no substring which is equal
// to P in string S, so output is 0.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isPatternPresent() which takes Strings P and S as input and returns 0 or 1.

// Expected Time Complexity: O(|P|*|S|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= |S| <= 105
// 1 <= |P| <= 10
// String S may contain both Uppercase and Lowercase letters.

// View Bookmarked Problems
// Company Tags
//  Microsoft

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int isPatternPresent(string S, string P)
    {
        int ls = S.size(), lp = P.size();
        if (P.find('^') == -1 and P.find('$') == -1)
        {
            for (int i = 0; i <= ls - lp; i++)
            {
                int j = 0;
                for (j = 0; j < lp; j++)
                {
                    if (S[i + j] != P[j])
                    {
                        break;
                    }
                }
                if (j == lp)
                {
                    return 1;
                }
            }
            return 0;
        }
        else
        {
            if (P[0] == '^')
            {
                for (int i = 1; i < lp; i++)
                {
                    if (S[i - 1] != P[i])
                    {
                        return 0;
                    }
                }
            }
            else
            {
                for (int j = 0, i = ls - lp + 1; i < ls; i++, j++)
                {
                    if (S[i] != P[j])
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string P, S;

        cin >> P;
        cin >> S;

        Solution ob;
        cout << ob.isPatternPresent(S, P) << endl;
    }
    return 0;
} // } Driver Code Ends