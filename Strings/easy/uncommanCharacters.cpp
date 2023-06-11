// Given two strings A and B. Find the characters that are not common in the two strings.

// Example 1:

// Input:
// A = geeksforgeeks
// B = geeksquiz
// Output: fioqruz
// Explanation:
// The characters 'f', 'i', 'o', 'q', 'r', 'u','z'
// are either present in A or B, but not in both.
// Example 2:

// Input:
// A = characters
// B = alphabets
// Output: bclpr
// Explanation: The characters 'b','c','l','p','r'
// are either present in A or B, but not in both.

// Your Task:
// You dont need to read input or print anything. Complete the function UncommonChars() which takes strings A and B as input parameters and returns a string that contains all the uncommon characters in sorted order. If no such character exists return "-1".

// Expected Time Complexity: O(M+N) where M and N are the sizes of A and B respectively.
// Expected Auxiliary Space: O(M+N)

// Constraints:
// 1<= M,N <= 104
// String may contain duplicate characters.

// View Bookmarked Problems
// Company Tags
//  Amazon

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string UncommonChars(string A, string B)
    {
        string ans;
        for (int i = 0; i < A.length(); i++)
        {
            if (B.find(A[i]) == -1 and ans.find(A[i]) == -1)
            {
                ans += A[i];
            }
        }

        for (int i = 0; i < B.length(); i++)
        {
            if (A.find(B[i]) == -1 and ans.find(B[i]) == -1)
            {
                ans += B[i];
            }
        }

        sort(ans.begin(), ans.end());
        if (ans.length() == 0)
            ans = "-1";
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
        string A, B;
        cin >> A;
        cin >> B;
        Solution ob;
        cout << ob.UncommonChars(A, B);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends