// Counts Zeros Xor Pairs
// EasyAccuracy: 58.15%Submissions: 10783Points: 2
// Given an array A[] of size N. Find the number of pairs (i, j) such that
// Ai XOR Aj = 0, and 1 ≤ i < j ≤ N.

// Example 1:

// â€‹Input : arr[ ] = {1, 3, 4, 1, 4}
// Output : 2
// Explanation:
// Index( 0, 3 ) and (2 , 4 ) are only pairs
// whose xors is zero so count is 2.

// â€‹Example 2:

// Input : arr[ ] = {2, 2, 2}
// Output :  3

// Your Task:
// This is a function problem. The input is already taken care of by the driver code. You only need to complete the function calculate() that takes an array (arr), sizeOfArray (n), and return the count of Zeros Xor's Pairs. The driver code takes care of the printing.

// Expected Time Complexity: O(N*Log(N)).
// Expected Auxiliary Space: O(1).

// Output:
// For each test case, output a single integer i.e counts of Zeros Xors Pairs

// Constraints
// 2 ≤ N ≤ 10^5
// 1 ≤ A[i] ≤ 10^5

// View Bookmarked Problems
// Topic Tags
// ArraysBit MagicSorting

//{ Driver Code Starts
// C++ program to find number
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n + 1];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << calculate(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

long long int calculate(int a[], int n)
{
    // Complete the function
    sort(a, a + n);
    long long count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (!(a[i] ^ a[j]))
            {
                count++;
            }
        }
    }
    return count;
}
