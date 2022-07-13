// In this problem, a String S is composed of lowercase alphabets and wildcard characters i.e. '?'. Here, '?' can be replaced by any of the lowercase alphabets. Now you have to classify the given String on the basis of following rules:

// If there are more than 3 consonants together or more than 5 vowels together, the String is considered to be "BAD". A String is considered "GOOD" only if it is not “BAD”.

// NOTE: String is considered as "BAD" if the above condition is satisfied even once. Else it is "GOOD" and the task is to make the string "BAD".

// Example 1:

// Input:
// S = aeioup??
// Output:
// 1
// Explanation: The String doesn't contain more
// than 3 consonants or more than 5 vowels together.
// So, it's a GOOD string.
// Example 2:

// Input:
// S = bcdaeiou??
// Output:
// 0
// Explanation: The String contains the
// Substring "aeiou??" which counts as 7
// vowels together. So, it's a BAD string.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isGoodorBad() which takes the String S as input and returns 0 or 1.

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= |S| <= 100000

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int isGoodorBad(string S)
    {
        int ans = 1;
        string vowels = "aeiou";

        int currConstCount = 0, currVowelsCount = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if (vowels.find(S[i]) == -1)
            {
                if (S[i] != '?' and vowels.find(S[i]) == -1)
                {
                    currVowelsCount = 0;
                }
                currConstCount++;
                if (currConstCount > 3)
                {
                    ans = 0;
                    break;
                }
            }
            if (vowels.find(S[i]) != -1 or S[i] == '?')
            {
                if (vowels.find(S[i]) != -1)
                {
                    currConstCount = 0;
                }
                currVowelsCount++;
                if (currVowelsCount > 5)
                {
                    ans = 0;
                    break;
                }
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
        string S;

        cin >> S;

        Solution ob;
        cout << ob.isGoodorBad(S) << endl;
    }
    return 0;
} // } Driver Code Ends