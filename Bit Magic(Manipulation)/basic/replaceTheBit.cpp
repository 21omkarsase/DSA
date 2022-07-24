// Replace the Bit
// BasicAccuracy: 40.83%Submissions: 1490Points: 1
// Given two numbers N and K, change the Kth (1-based indexing) bit from the left of the binary representation of the number N to '0' if it is  '1', else return the number N itself.

// Example 1:

// Input:
// N = 13, K = 2
// Output: 9
// Explanation: Binary representation of 13 is
// 1101. The 2nd bit from left is 1, we make
// it 0 and result is 1001 = 9 (decimal).
// Example 2:

// Input:
// N = 13, K = 6
// Output: 13
// Explanation: Binary representation of 13 is
// 1101. There's no 6th bit from left,
// hence we return the number itself.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function replaceBit() which takes the integers N and K as inputs and returns the resultant number after the stated modifications.

// Expected Time Complexity: O(LogN).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1<=N<=106

// View Bookmarked Problems
// Company Tags
// Microsoft

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int replaceBit(int n, int k)
    {
        // code here.
        int m = n, cnt;
        while (m)
        {
            cnt++;
            m = m >> 1;
        }
        return (n & (~(1 << (cnt - k))));
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.replaceBit(n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends