// Binary representation
// SchoolAccuracy: 52.5%Submissions: 3832Points: 0
// Write a program to print Binary representation of a given number N.

// Example 1:

// Input:
// N = 2
// Output:
// 000000000000000000000000000010
// Explanation:
// The binary representation of 2 is '10'
// but we need to print in 30 bits so append
// remaining 0's in the left.
// Example 2:

// Input:
// N = 5
// Output:
// 000000000000000000000000000101
// Explanation:
// The binary representation of 5 is '101'.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function getBinaryRep() which takes an Integer N as input parameter and returns a string of size 30 which is the binary representation of N.

// Expected Time Complexity: O(LogN)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 10^9

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
    string getBinaryRep(int N)
    {
        string ans = "";
        while (N)
        {
            char num = N % 2 + 48;
            ans = num + ans;
            N /= 2;
        }
        int len = ans.size();
        for (int i = 1; i <= (30 - len); i++)
        {
            ans = '0' + ans;
        }
        return ans;
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
        string ans = ob.getBinaryRep(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends