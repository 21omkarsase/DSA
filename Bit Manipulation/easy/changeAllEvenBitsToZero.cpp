

// Change all even bits in a number to 0
// BasicAccuracy: 71.77%Submissions: 5098Points: 1
// Given a number N, change all bits at even positions to 0.

// Example 1:

// Input: N = 30
// Output: 10
// Explanation: Binary representation of
// 11110. Bits at Even positions are
// highlighted. After making all of them
// 0, we get 01010. Hence the answer is 10.
// Example 2:

// Input:  N = 10
// Output: 10
// Explanation: Binary representation of
// 1010. Bits at Even positions are
// highlighted. After making all of them
// 0, we get 1010. Hence the answer is 10.

// Your Task:
// You dont need to read input or print anything. Complete the function convertEvenBitToZero() which takes n as input parameter and returns the value of N after changing bits at even positions.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<= N <=(32-bit number)

// View Bookmarked Problems
// Company Tags
// QualcommSamsung

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long int convertEvenBitToZero(long long int n)
    {
        // long long k = n;
        // int i = 0;
        // while (k)
        // {
        //     if (!(i & 1))
        //     {
        //         n = n & (~(1 << i));
        //     }
        //     k = k >> 1;
        //     i++;
        // }
        // return n;

        // *******************or***************
        return (n & 0xaaaaaaaa);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.convertEvenBitToZero(n) << endl;
    }
    return 0;
}

// } Driver Code Ends