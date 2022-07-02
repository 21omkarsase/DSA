// Given an array A[] of N integers and a range(L, R). The task is to find the number of subarrays having sum in the range L to R (inclusive).

// Example 1:

// Input:
// N = 3, L = 3, R = 8
// A[] = {1, 4, 6}
// Output:
// 3
// Explanation:
// The subarrays are [1,4], [4] and [6]
// Example 2:

// Input:
// N = 4, L = 4, R = 13
// A[] = {2, 3, 5, 8}
// Output:
// 6
// Explanation:
// The subarrays are [2,3], [2,3,5],
// [3,5],[5], [5,8] and [8]
// Your Task:
// You don't need to read input or print anything. Complete the function countSubarray( ) which takes the integer N , the array A[], the integer L and the integer R as input parameters and returns the number of subarays.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 106
// 1 ≤ A[] ≤ 109
// 1 ≤ L ≤ R ≤ 1015

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long count(int n, vector<int> &A, long long x)
    {
        long long ans = 0, sum = 0, r = 0, l = 0;
        while (r < n)
        {
            sum += A[r];
            while (sum > x)
            {
                sum -= A[l];
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }

    long long countSubarray(int N, vector<int> A, long long L, long long R)
    {
        // code here
        long long ans1 = count(N, A, R);
        long long ans2 = count(N, A, L - 1);

        return ans1 - ans2;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        long long L, R;
        cin >> N >> L >> R;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N, A, L, R);
        cout << ans << endl;
    }
} // } Driver Code Ends