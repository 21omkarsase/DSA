

// Even Subsets
// EasyAccuracy: 48.56%Submissions: 6102Points: 2
// As we mentioned earlier, bitwise operations can be used to find number of subsets. Here, we will use that.

// Given an array arr of N elements. The task is to count all the subsets whose sum is even.

// Example:

// Input:N = 3arr[] = 1 2 3Output:3Explanation:Three subsets are there whose sum of elements is even. Subsets are (3, 2, 1), (1, 3), (2).
// Your Task:
// Your task is to complete the function countSumSubsets() which counts all the subsets in which sum of all the elements is even. Print the count of subsets whose sum of all elements is even.

// Constraints:
// 1 <= N <= 10
// 1 <= arr[i] <= 10

// View Bookmarked Problems
// Topic Tags
// Bit Magic

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*Function to count subset with even sum
 * arr : array input
 * N : size of array
 */
class Solution
{
public:
    int countSumSubsets(int arr[], int N)
    {
        int len = pow(2, N) - 1, ans = 0, oddCnt = 0, evenCnt = 0;
        for (int i = 1; i <= len; i++)
        {
            int j = 0;
            while (i and j < N)
            {
                if (i & (1 << j))
                {
                    if (arr[j] & 1)
                        oddCnt++;
                    else
                        evenCnt++;
                }
                j++;
            }
            ans++;
            if (oddCnt & 1)
                ans--;
            evenCnt = 0;
            oddCnt = 0;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code to test columnWithMaxZeros function
int main()
{

    int testcase;

    cin >> testcase;

    while (testcase--)
    {
        int N;
        cin >> N;

        int arr[N];

        // Taking elements input into the matrix
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.countSumSubsets(arr, N) << endl;
    }

    return 0;
}
// } Driver Code Ends