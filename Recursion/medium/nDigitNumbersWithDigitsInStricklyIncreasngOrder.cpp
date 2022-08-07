// N Digit numbers with digits in increasing order
// MediumAccuracy: 74.26%Submissions: 5159Points: 4
// Given an integer N, print all the N digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).

// Example 1:

// Input:
// N = 1
// Output:
// 0 1 2 3 4 5 6 7 8 9
// Explanation:
// Single digit numbers are considered to be
// strictly increasing order.
// Example 2:

// Input:
// N = 2
// Output:
// 12 13 14 15 16 17 18 19 23....79 89
// Explanation:
// For N = 2, the correct sequence is
// 12 13 14 15 16 17 18 19 23 and so on
// up to 89.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function increasingNumbers() which takes an integer N as an input parameter and return the list of numbers such that their digits are in strictly increasing order.

// Expected Time Complexity: O(9N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 9

// View Bookmarked Problems
// Company Tags
// ABCO

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//**********************USING DFS AND RECURSION**********************

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    void findNDigitNumbers(int start, int num, int n, vector<int> &ans)
    {
        if (n == 0)
        {
            ans.push_back(num);
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            int curr = (num * 10) + i;
            findNDigitNumbers(i + 1, curr, n - 1, ans);
        }
    }

    vector<int> increasingNumbers(int N)
    {
        vector<int> ans;

        if (N == 1)
        {
            for (int i = 0; i <= 9; i++)
            {
                ans.push_back(i);
            }
            return ans;
        }

        findNDigitNumbers(1, 0, N, ans);
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
        vector<int> ans = ob.increasingNumbers(N);
        for (auto num : ans)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends