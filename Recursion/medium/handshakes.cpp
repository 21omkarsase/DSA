// Handshakes
// MediumAccuracy : 57.82 %
//  Submissions : 8447Points : 4 We have N persons sitting on a round table.Any person can do a handshake with any other person.

//  1 2 3 4

//  Handshake with 2 -
// 3 and 1 - 4 will cause cross.

// In how many ways these N people can make handshakes so that no two handshakes cross each other.N would be even.

// Example 1 :

// Input : N = 2 Output : 1 Explanation : {1, 2} handshake is
// possible.Example 2 :

// Input : N = 4 Output : 2 Explanation:
// {
// {1, 2}, { 3, 4 }
// }
// are the
// two handshakes possible.
// {
// {1, 3}, { 2, 4 }
// }
// is another
//  set of handshakes possible.

// Your Task : You don't need to read input or print anything. Your task is to complete the function count() which takes an integer N as input parameters and returns an integer, the total number of handshakes possible so that no two handshakes cross each other.

//   Expected Time Complexity : O(2N)
// Expected Space Complexity : O(1)

//   Constraints : 1 <= N
// <= 30

// View Bookmarked Problems
// Company Tags
// Amazon
// Topic Tags
// Recursion

// ************************USING DYNAMIC PROGRAMMING**********************

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int count(int N)
    {
        vector<int> dp(N + 1, 0); // N+1 because we want to store for 0 peoples also           // TO STORE ANSWER FOR EVERY INSTANCE
        dp[0] = 1;                // to not get handhake val 0

        for (int n = 2; n <= N; n += 2) // for every even no of peoples storing ans
        {
            for (int i = 0; i <= n - 2; i += 2) // calculating no of ways in which they can handshake
            // e.g
            // for N=6
            // checking when pairs are 1-2(dp[0]+dp[4]) , 2-4(dp[2]+dp[2]) , 1-3(dp[4]+dp[0])

            {
                dp[n] += dp[i] * dp[n - 2 - i];
            }
        }

        return dp[N];
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
        cout << ob.count(N) << endl;
    }
    return 0;
}
// } Driver Code Ends

// *****************USING RECURSION*********************
// int count(int N)
// {
//     if (N == 0)
//         return 1;

//     int ans = 0;
//     for (int i = 2; i <= N; i += 2)
//     {
//         int left = count(i - 2);
//         int right = count(N - i);
//         ans += (left * right);
//     }

//     return
// }