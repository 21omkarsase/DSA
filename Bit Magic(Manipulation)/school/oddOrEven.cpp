// Odd or Even
// SchoolAccuracy: 60.61%Submissions: 11923Points: 0
// Given a positive integer N, determine whether it is odd or even.

// Example 1:

// Input:
// N = 1
// Output:
// odd
// Explanation:
// The output is self-
// explanatory.

// Example 2:

// Input:
// N = 2
// Output:
// even
// Explanation:
// The output is self-
// explanatory.

// Your Task:

// You don't need to read input or print anything. Your task is to complete the function oddEven() which takes the integer N and return "even" is number is even and "odd" if the number is odd.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// 0 <= N <= 10000

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string oddEven(int N)
    {
        if (N & 1)
            return "odd";
        else
            return "even";
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
        cout << ob.oddEven(N) << endl;
    }
    return 0;
}
// } Driver Code Ends