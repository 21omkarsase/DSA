

// Toggle bits given range
// BasicAccuracy: 67.51%Submissions: 4995Points: 1
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given a non-negative number N and two values L and R. The problem is to toggle the bits in the range L to R in the binary representation of N, i.e, to toggle bits from the rightmost Lth bit to the rightmost Rth bit. A toggle operation flips a bit 0 to 1 and a bit 1 to 0. Print N after the bits are toggled.

// Example 1:

// Input:
// N = 17 , L = 2 , R = 3
// Output:
// 23
// Explanation:
// (17)10 = (10001)2.  After toggling all
// the bits from 2nd to 3rd position we get
// (10111)2 = (23)10
// Example 2:

// Input:
// N = 50 , L = 2 , R = 5
// Output:
// 44
// Explanation:
// (50)10 = (110010)2.  After toggling all
// the bits from 2nd to 3rd position we get
// (101100)2 = (44)10

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function toggleBits() which takes 3 Integers N,L and R as input and returns the answer.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= L<=R <= Number of Bits in N

// View Bookmarked Problems
// Topic Tags
// Bit Magic

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int toggleBits(int N, int L, int R)
    {
        int n = N;
        int i = L - 1;
        while (i <= R - 1)
        {
            if (n & (1 << i))
            {
                N = N & (~(1 << i));
            }
            else
            {
                N = N | (1 << i);
            }
            i++;
        }
        return N;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, L, R;

        cin >> N >> L >> R;

        Solution ob;
        cout << ob.toggleBits(N, L, R) << endl;
    }
    return 0;
}
// } Driver Code Ends