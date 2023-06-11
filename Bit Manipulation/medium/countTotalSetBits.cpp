

// Count total set bits
// MediumAccuracy: 45.48%Submissions: 74587Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

// Example 1:

// Input: N = 4
// Output: 5
// Explanation:
// For numbers from 1 to 4.
// For 1: 0 0 1 = 1 set bits
// For 2: 0 1 0 = 1 set bits
// For 3: 0 1 1 = 2 set bits
// For 4: 1 0 0 = 1 set bits
// Therefore, the total set bits is 5.
// Example 2:

// Input: N = 17
// Output: 35
// Explanation: From numbers 1 to 17(both inclusive),
// the total number of set bits is 35.

// Your Task: The task is to complete the function countSetBits() that takes n as a parameter and returns the count of all bits.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 108

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
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int powerOfTwo(int n)
    {
        int x = 0;
        while ((1 << x) <= n)
        {
            x++;
        }
        return x - 1;
    }
    int countSetBits(int n)
    {
        if (!n)
        {
            return 0;
        }
        int x = powerOfTwo(n);

        int bitsUptoTwoRaiseToX = x * (1 << (x - 1));

        int msbFromTwORaiseToN = n - (1 << x) + 1;

        int rest = n - (1 << x);

        int ans = bitsUptoTwoRaiseToX + msbFromTwORaiseToN + countSetBits(rest);

        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}

// } Driver Code Ends