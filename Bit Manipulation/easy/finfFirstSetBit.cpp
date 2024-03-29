// Find first set bit
// EasyAccuracy: 52.49%Submissions: 49181Points: 2
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given an integer an N. The task is to return the position of first set bit found from the right side in the binary representation of the number.
// Note: If there is no set bit in the integer N, then return 0 from the function.

// Example 1:

// Input: N = 18
// Output: 2
// Explanation: Binary representation of
// 18 is 010010,the first set bit from the
// right side is at position 2.
// Example 2:

// Input: N = 12
// Output: 3
// Explanation: Binary representation
// of  12 is 1100, the first set bit
// from the right side is at position 3.
// Your Task:
// The task is to complete the function getFirstSetBit() that takes an integer n as a parameter and returns the position of first set bit.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 0 <= N <= 108

// View Bookmarked Problems
// Topic Tags
// Bit Magic

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        unsigned int ans = 0, i = 1;
        while (n)
        {
            if (n & 1)
            {
                ans = i;
                break;
            }
            n = n >> 1;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; // input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
    return 0;
}

// } Driver Code Ends