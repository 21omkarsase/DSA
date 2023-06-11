// Given an array of distinct elements. Find the third largest element in it.

// Suppose you have A[] = {1, 2, 3, 4, 5, 6, 7}, its output will be 5 because it is the 3 largest element in the array A.

// Example 1:

// Input:
// N = 5
// A[] = {2,4,1,3,5}
// Output: 3
// Example 2:

// Input:
// N = 2
// A[] = {10,2}
// Output: -1
// Your Task:
// Complete the function thirdLargest() which takes the array a[] and the size of the array, n, as input parameters and returns the third largest element in the array. It return -1 if there are less than 3 elements in the given array.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ A[i] ≤ 105

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int thirdLargest(int a[], int n)
    {
        //  Your code here
        sort(a, a + n);
        if (n < 3)
        {
            return -1;
        }
        return a[n - 3];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.thirdLargest(a, n) << endl;
    }
} // } Driver Code Ends