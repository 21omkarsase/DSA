

// Maximum AND Value
// MediumAccuracy: 44.82%Submissions: 30379Points: 4
// Given an array arr[] of N positive elements. The task is to find the Maximum AND Value generated by any pair(arri, arrj) from the array such that i != j.
// Note: AND is bitwise '&' operator.

// Example 1:

// Input:
// N = 4
// arr[] = {4, 8, 12, 16}
// Output: 8
// Explanation:
// Pair (8,12) has the Maximum AND Value 8.
// Example 2:

// Input:
// N = 4
// arr[] = {4, 8, 16, 2}
// Output: 0
// Explanation: Any two pairs of the array has
// Maximum AND Value 0.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxAND() which takes the array elements and N (size of the array) as input parameters and returns the maximum AND value generated by any pair in the array.

// Expected Time Complexity: O(N * log M), where M is the maximum element of the array.
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 105
// 1 <= arr[i] <= 105
// View Bookmarked Problems
// Company Tags
// Microsoft

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function for finding maximum AND value.
    int calculateCount(int pattern, int a[], int n)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if ((a[i] & pattern) == pattern)
            {
                count++;
            }
        }
        return count;
    }
    int maxAND(int arr[], int N)
    {
        int res = 0, count;
        for (int bit = 16; bit >= 0; bit--)
        {

            count = calculateCount(res | (1 << bit), arr, N);

            if (count >= 2)
            {
                res |= (1 << bit);
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

// Driver function
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; // input n
        int arr[n + 5], i;

        // inserting elements
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        // calling maxAND() function
        cout << obj.maxAND(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends