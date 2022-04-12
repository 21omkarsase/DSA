// An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists).
// Given an array arr[] of size N, find the index of any one of its peak elements.
// Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0.

// Example 1:

// Input:
// N = 3
// arr[] = {1,2,3}
// Output: 2
// Explanation: index 2 is 3.
// It is the peak element as it is
// greater than its neighbour 2.
// Example 2:

// Input:
// N = 2
// arr[] = {3,4}
// Output: 1
// Explanation: 4 (at index 1) is the
// peak element as it is greater than
// its only neighbour element 3.

// Your Task:
// You don't have to read input or print anything. Complete the function peakElement() which takes the array arr[] and its size N as input parameters and return the index of any one of its peak elements.

// Can you solve the problem in expected time complexity?

// Expected Time Complexity: O(log N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ A[] ≤ 106

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
public:
    int peakElement(int arr[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            if (i != n - 1)
            {
                if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
                {
                    return i;
                }
            }
        }
        if (arr[0] > arr[1])
        {
            return 0;
        }
        if (arr[n - 1] > arr[n - 2])
        {
            return n - 1;
        }
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
        int a[n], tmp[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            tmp[i] = a[i];
        }
        bool f = 0;
        Solution ob;

        int A = ob.peakElement(tmp, n);

        if (A < 0 and A >= n)
            cout << 0 << endl;
        else
        {
            if (n == 1 and A == 0)
                f = 1;
            else if (A == 0 and a[0] >= a[1])
                f = 1;
            else if (A == n - 1 and a[n - 1] >= a[n - 2])
                f = 1;
            else if (a[A] >= a[A + 1] and a[A] >= a[A - 1])
                f = 1;
            else
                f = 0;
            cout << f << endl;
        }
    }

    return 0;
} // } Driver Code Ends