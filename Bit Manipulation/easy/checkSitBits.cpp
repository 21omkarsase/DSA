

// Check set bits
// BasicAccuracy: 56.35%Submissions: 8735Points: 1
// Given a number N. You have to check whether every bit in the binary representation of the given number is set or not.

// Example 1:

// Input:
// N = 7
// Output:
// 1
// Explanation:
// Binary for 7 is 111 all the
// bits are set so output is 1
// Example 2:

// Input:
// N = 8
// Output:
// 0
// Explanation:
// Binary for 8 is 1000 all the
// bits are not set so output is 0.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isBitSet() which takes an integer N as input parameters and returns 1 if all the bits in N's binary representation is set or return 0 otherwise.

// Expected Time Complexity: O(1)
// Expected Space Complexity: O(1)

// Constraints:
// 0<=N<=100000

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
    int isBitSet(int N)
    {
        if (N == 0)
            return 0;
        while (N)
        {
            if (!(N & 1))
                return 0;
            N = N >> 1;
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isBitSet(N) << endl;
    }
    return 0;
}
// } Driver Code Ends