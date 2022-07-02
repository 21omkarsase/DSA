// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Example 1:

// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.
// Your Task:
// You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 105
// -1000 <= A[i] <= 1000, for each valid i

// { Driver Code Starts
// Initial Template for C++

// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// /*You are required to complete this function*/

// class Solution
// {
// public:
//     int maxLen(vector<int> &A, int n)
//     {
//         vector<vector<int>> vec;
//         // Your code here
//         for (int i = 0; i < n - 1; i++)
//         {
//             for (int j = i; j < n; j++)
//             {
//                 vector<int> v;
//                 for (int k = i; k < j; k++)
//                 {
//                     v.push_back(A[k]);
//                 }
//                 vec.push_back(v);
//             }
//         }
//         int mLen = 0;
//         int sum = 0;
//         for (auto it : vec)
//         {
//             sum = 0;
//             for (auto i : it)
//             {
//                 sum += i;
//             }
//             if (sum == 0)
//             {
//                 int length = it.size();
//                 mLen = max(mLen, length);
//             }
//         }
//         return mLen;
//     }
// };

// // { Driver Code Starts.

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int m;
//         cin >> m;
//         vector<int> array1(m);
//         for (int i = 0; i < m; ++i)
//         {
//             cin >> array1[i];
//         }
//         Solution ob;
//         cout << ob.maxLen(array1, m) << endl;
//     }
//     return 0;
// }

// // } Driver Code Ends

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this function*/

class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        map<int, int> Map;
        int sum = 0, largest = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            if (sum == 0 || Map[sum])
            {
                largest = max(largest, i - Map[sum] + 1);
            }
            else
            {
                Map[sum] = i + 1;
            }
        }
        return largest;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends