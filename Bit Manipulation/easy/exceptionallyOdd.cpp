

// Exceptionally odd
// BasicAccuracy: 59.18%Submissions: 13031Points: 1
// Given an array of N positive integers where all numbers occur even number of times except one number which occurs odd number of times. Find the exceptional number.

// Example 1:

// Input:
// N = 7
// Arr[] = {1, 2, 3, 2, 3, 1, 3}
// Output: 3

// Example 2:

// Input:
// N = 7
// Arr[] = {5, 7, 2, 7, 5, 2, 5}
// Output: 5

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function getOddOccurrence() which takes arr[] and n as input parameters and returns the exceptional number.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ arr[i] ≤ 106

// View Bookmarked Problems
// Company Tags
// AmazonSnapdeal

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getOddOccurrence(int arr[], int n)
    {
        int x = arr[0];
        for (int i = 1; i < n; i++)
        {
            x = x ^ arr[i];
        }
        return x;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getOddOccurrence(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends