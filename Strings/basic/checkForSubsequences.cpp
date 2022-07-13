// Check for subsequence
// Basic Accuracy: 52.09% Submissions: 15851 Points: 1
// Given two strings A and B, find if A is a subsequence of B.

// Example 1:

// Input:
// A = AXY
// B = YADXCP
// Output: 0
// Explanation: A is not a subsequence of B
// as 'Y' appears before 'A'.

// Example 2:

// Input:
// A = gksrek
// B = geeksforgeeks
// Output: 1
// Explanation: A is a subsequence of B.

// Your Task:
// You dont need to read input or print anything. Complete the function isSubSequence() which takes A and B as input parameters and returns a boolean value denoting if A is a subsequence of B or not.

// Expected Time Complexity: O(N) where N is length of string B.
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<= |A|,|B| <=104

// Company Tags
//  Accolite Amazon Tesco Zoho

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isSubSequence(string A, string B)
    {

        int i = 0, j;
        while (i < A.length())
        {
            j = B.find(A[i]);
            if (j == -1)
            {
                return 0;
            }
            B = B.substr(j + 1);
            i++;
        }
        return 1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        string A, B;
        cin >> A;
        cin >> B;
        Solution ob;
        if (ob.isSubSequence(A, B))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}
// } Driver Code Ends
