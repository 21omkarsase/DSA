
// Given two strings A and B, find the minimum number of times A has to be repeated such that B becomes a substring of the repeated A. If B cannot be a substring of A no matter how many times it is repeated, return -1.

// Example 1:

// Input: A = "abcd", B = "cdabcdab"
// Output: 3
// Explanation: After repeating A three times,
// we get "abcdabcdabcd".
// Example 2:

// Input: A = "aa", B = "a"
// Output: 1
// Explanation: B is already a substring of A.
// Your Task:
// You don't need to read input or print anything. Complete the function repeatedStringMatch() which takes strings A and B as input parameters and returns the minimum number of operations to complete the task. If it is not possible then return -1.

// Expected Time Complexity: O(|A| * |B|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ |A|, |B| ≤ 4 * 103

// View Bookmarked Problems
// Company Tags
//  Google
// Topic Tags
//  Strings

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int repeatedStringMatch(string A, string B)
    {
        string temp = A;
        if (A.find(B) != -1)
        {
            return 1;
        }
        else
        {
            int count = 1;
            while (A.length() < B.length())
            {
                A += temp;
                count++;
            }
            if (A.find(B) != -1)
            {
                return count;
            }
            A += temp;
            if (A.find(B) != -1)
            {
                return count + 1;
            }
            return -1;
        }
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
        Solution obj;
        cout << obj.repeatedStringMatch(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends