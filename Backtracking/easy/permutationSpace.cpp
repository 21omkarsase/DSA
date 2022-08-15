

// Permutation with Spaces
// EasyAccuracy: 60.83%Submissions: 12900Points: 2
// Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings

// Example 1:

// Input:
// S = "ABC"
// Output: (A B C)(A BC)(AB C)(ABC)
// Explanation:
// ABC
// AB C
// A BC
// A B C
// These are the possible combination of "ABC".

// Example 2:

// Input:
// S = "AB"
// Output: (A B)(AB)

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function permutation() which takes the string S as input parameters and returns the sorted array of the string denoting the different permutation (DON'T ADD '(' and ')' it will be handled by the driver code only).

// Expected Time Complexity: O(2^n)
// Expected Auxiliary Space: O(1)

// CONSTRAINTS:
// 1 <= |S| < 10
// S only contains lowercase and Uppercase English letters.

// View Bookmarked Problems
// Company Tags
// Amazon

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void generateSequence(vector<string> &v, string s, int n, int i)
    {
        if (i >= s.length())
            return;

        string st = s.substr(0, i), en = s.substr(i);
        s = st + " " + en;
        v.push_back(s);
        generateSequence(v, s, n, i + 2);
        s = st + en;
        generateSequence(v, s, n, i + 1);
    }

    vector<string> permutation(string S)
    {
        vector<string> v;
        int len = S.length();
        generateSequence(v, S, len, 1);

        v.push_back(S);
        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    }
}

// } Driver Code Ends