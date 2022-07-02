// Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.

// Example 1:

// Input:
// N = 7
// arr[] = {8,-8,9,-9,10,-11,12}
// Output:
// 22
// Explanation:
// Starting from the last element
// of the array, i.e, 12, and
// moving in a circular fashion, we
// have max subarray as 12, 8, -8, 9,
// -9, 10, which gives maximum sum
// as 22.
// Example 2:

// Input:
// N = 8
// arr[] = {10,-3,-4,7,6,5,-4,-1}
// Output:
// 23
// Explanation: Sum of the circular
// subarray with maximum sum is 23

// Your Task:
// The task is to complete the function circularSubarraySum() which returns a sum of the circular subarray with maximum sum.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 106
// -106 <= Arr[i] <= 106

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // num: size of array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num)
    {

        int totalSum = 0, negMax = INT_MIN;
        bool allNegative = true;
        for (int i = 0; i < num; i++)
        {
            totalSum += arr[i];
            if (arr[i] >= 0)
            {
                allNegative = false;
            }
            negMax = max(negMax, arr[i]);
        }

        if (allNegative)
        {
            return negMax;
        }

        int maxSum = INT_MIN, currSum = 0;
        for (int i = 0; i < num; i++)
        {
            currSum += arr[i];
            if (currSum < 0)
            {
                currSum = 0;
            }
            maxSum = max(maxSum, currSum);
        }

        for (int i = 0; i < num; i++)
        {
            arr[i] = -arr[i];
        }

        int maxChangeSum = INT_MIN;
        currSum = 0;
        for (int i = 0; i < num; i++)
        {
            currSum += arr[i];
            if (currSum < 0)
            {
                currSum = 0;
            }
            maxChangeSum = max(maxChangeSum, currSum);
        }

        return max(maxSum, totalSum + maxChangeSum);
    }
};

// { Driver Code Starts.

int main()
{
    int T;

    // testcases
    cin >> T;

    while (T--)
    {
        int num;

        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];

        Solution ob;
        // calling function
        cout << ob.circularSubarraySum(arr, num) << endl;
    }

    return 0;
} // } Driver Code Ends