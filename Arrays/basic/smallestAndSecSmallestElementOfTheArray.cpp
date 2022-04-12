// Given an array of integers, your task is to find the smallest and second smallest element in the array. If smallest and second smallest do not exist, print -1.

// Example 1:

// Input :
// 5
// 2 4 3 5 6
// Output :
// 2 3
// Explanation:
// 2 and 3 are respectively the smallest
// and second smallest elements in the array.

// Example 2:

// Input :
// 6
// 1 2 1 3 6 7
// Output :
// 1 2
// Explanation:
// 1 and 2 are respectively the smallest
// and second smallest elements in the array.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minAnd2ndMin() which takes the array A[] and its size N as inputs and returns a vector containing the smallest and second smallest element if possible, else return {-1,-1}.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=N<=105
// 1<=A[i]<=105

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

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

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
} // } Driver Code Ends

vector<int> minAnd2ndMin(int a[], int n)
{
    vector<int> ans;
    int firstSmall = a[0];
    int secSmall = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < firstSmall)
        {
            secSmall = firstSmall;
            firstSmall = a[i];
        }
        else if (a[i] > firstSmall and a[i] < secSmall)
        {
            secSmall = a[i];
        }
    }

    if (secSmall != INT_MAX)
    {
        ans.push_back(firstSmall);
        ans.push_back(secSmall);
    }
    else
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }

    return ans;
}