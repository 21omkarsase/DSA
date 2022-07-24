

// Maximum subset XOR
// HardAccuracy: 47.81%Submissions: 17467Points: 8
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given an array arr[] of N positive integers. Find an integer denoting the maximum XOR subset value in the given array arr[].

// Example 1:

// Input :
// N = 3
// arr[] = {2, 4, 5}
// Output : 7
// Explanation :
// The subset {2, 5} has maximum
// subset XOR value.
// Example 2 :

// Input :
// N= 3
// arr[] = {9, 8, 5}
// Output : 13
// Explanation :
// The subset {8, 5} has maximum
// subset XOR value.
// Your Task :
// You don't need to read input or print anything. Your task is to complete the function maxSubarrayXOR() which takes the array and an integer as input and returns the maximum subset XOR value.

// Expected Time Complexity : O(N*Log(max(arr[i])))
// Expected Auxiliary Space : O(1)

// Contraints :
// 1 <= N <= 105
// 1 <= arr[i] <= 106
// View Bookmarked Problems
// Company Tags
// Microsoft

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
public:
    int maxSubarrayXOR(int arr[], int N)
    {
        int idx = 0;
        for (int i = 31; i >= 0; i--)
        {
            int maxIdx = idx, maxEle = INT_MIN;

            for (int j = idx; j < N; j++)
            {
                if ((arr[j] & (1 << i)) != 0 and arr[j] > maxEle)
                {
                    maxEle = arr[j], maxIdx = j;
                }
            }

            if (maxEle == INT_MIN)
                continue;

            swap(arr[idx], arr[maxIdx]);
            maxIdx = idx;

            for (int j = 0; j < N; j++)
            {
                if (j != maxIdx && (arr[j] & (1 << i)) != 0)
                {
                    arr[j] = arr[j] ^ arr[maxIdx];
                }
            }
            idx++;
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            ans ^= arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t, n, a[100004], k;
    scanf("%d", &t);
    while (t--)
    {
        // cin>>n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        Solution obj;
        printf("%d\n", obj.maxSubarrayXOR(a, n));
        // cout<<bin(a,0,n-1,k)<<endl;
    }
}
// } Driver Code Endsz