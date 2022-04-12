// You are given an array A, of N elements. Find minimum index based distance between two elements of the array, x and y.

// Example 1:

// Input:
// N = 4
// A[] = {1,2,3,2}
// x = 1, y = 2
// Output: 1
// Explanation: x = 1 and y = 2. There are
// two distances between x and y, which are
// 1 and 3 out of which the least is 1.
// Example 2:

// Input:
// N = 7
// A[] = {86,39,90,67,84,66,62}
// x = 42, y = 12
// Output: -1
// Explanation: x = 42 and y = 12. We return
// -1 as x and y don't exist in the array.
// Your Task:
// Complete the function minDist() which takes the array, n, x and y as input parameters and returns the minimum distance between x and y in the array. If no such distance is possible then return -1.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 0 <= A[i], x, y <= 105

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int minDist(int a[], int n, int x, int y)
    {
        int mDist = INT_MAX;
        // int low=min(x,y);
        // int high=max(x,y);

        int xIdx = -1;
        int yIdx = -1;

        // for(int i=0;i<n;i++)
        // {
        //     if(a[i]==low)
        //     {
        //         minIdx=i;
        //     }
        //     if(a[i]==high)
        //     {
        //         maxIdx=i;
        //     }
        // }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
            {
                xIdx = i;
            }
            else if (a[i] == y)
            {
                yIdx = i;
            }
            if (xIdx != -1 and yIdx != -1)
            {
                mDist = min(mDist, (abs(yIdx - xIdx)));
            }
        }
        if (xIdx == -1 || yIdx == -1)
        {
            return -1;
        }

        return mDist;
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
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}
// } Driver Code Ends