// Given an 2-d array ofintegers havingN*Nelements, print the transpose of the array.

// Example 1:

// Input : arr[] = {{1,2,3}, {4,5,6}, {7,8,9}}         and N = 3Output : 1 4 7 2 5 8 3 6 9Explanation:1 2 3       1 4 74 5 6 ----> 2 5 87 8 9       3 6 9Transpose of array.

// Example 2:

// Input : arr[ ] = {{1, 2}, {1, 2}} and N = 2 Output :  1 1 2 2
// Your Task:
// This is a function problem. The input is already taken care of by the driver code. You only need to complete the function transpose() that takes a two-dimensionarray (arr), sizeOfArray (n), and return the transpose of the array. The driver code takes care of the printing.

// Expected Time Complexity:O(N2).
// Expected Auxiliary Space:O(1).

// Constraints:
// 1 ≤ N ≤ 100
// 0 ≤ A[i] ≤ 1000

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define M 101

vector<vector<int>> transpose(int a[][M], int n);

int main()
{
    int t;
    cin >> t;
    int a[M][M];
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> b;
        b = transpose(a, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << b[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends

vector<vector<int>> transpose(int a[][M], int n)
{
    vector<vector<int>> ans;
    for (int i = 0; i < M; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(a[j][i]);
        }
        ans.push_back(v);
    }

    return ans;
}
