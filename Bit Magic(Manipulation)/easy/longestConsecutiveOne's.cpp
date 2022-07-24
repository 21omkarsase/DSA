// Longest Consecutive 1's
// EasyAccuracy: 57.61%Submissions: 29842Points: 2
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given a number N. Find the length of the longest consecutive 1s in its binary representation.

// Example 1:

// Input: N = 14
// Output: 3
// Explanation:
// Binary representation of 14 is
// 1110, in which 111 is the longest
// consecutive set bits of length is 3.
// Example 2:

// Input: N = 222
// Output: 4
// Explanation:
// Binary representation of 222 is
// 11011110, in which 1111 is the
// longest consecutive set bits of length 4.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxConsecutiveOnes() which returns the length of the longest consecutive 1s in the binary representation of given N.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 106
// View Bookmarked Problems
// Company Tags
// Microsoft

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*  Function to calculate the longest consecutive ones
 *   N: given input to calculate the longest consecutive ones
 */
class Solution
{
public:
    int maxConsecutiveOnes(int N)
    {
        if (!N)
            return 0;
        int k = N;
        int ans = 0, cnt = 0, lastBit = 0;
        while (k)
        {
            if (lastBit && k & 1)
                cnt++;
            if (k & 1)
                lastBit = 1;
            else
            {
                lastBit = 0;
                cnt = 0;
            }
            ans = max(ans, cnt);
            k = k >> 1;
        }
        return ans + 1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; // input n
        Solution obj;
        // calling maxConsecutiveOnes() function
        cout << obj.maxConsecutiveOnes(n) << endl;
    }
    return 0;
}
// } Driver Code Ends