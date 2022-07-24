

// Find element occuring once when all other are present thrice
// MediumAccuracy: 70.6%Submissions: 5719Points: 4
// Given an array of integers arr[] of length N, every element appears thrice except for one which occurs once.
// Find that element which occurs once.

// Example 1:

// Input:
// N = 4
// arr[] = {1, 10, 1, 1}
// Output:
// 10
// Explanation:
// 10 occurs once in the array while the other
// element 1 occurs thrice.
// Example 2:

// Input:
// N = 10
// arr[] = {3, 2, 1, 34, 34, 1, 2, 34, 2, 1}
// Output:
// 3
// Explanation:
// All elements except 3 occurs thrice in the array.

// Your Task:
// The task is to complete the function singleElement() which finds and returns the element occuring once in the array.

// Constraints:
// 1 ≤ N ≤ 106
// -109 ≤ A[i] ≤ 109

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// View Bookmarked Problems
// Company Tags
// Google

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int singleElement(int arr[], int N)
    {
        // unordered_map<int,int>m;
        // for(int i=0;i<N;i++){
        //     m[arr[i]]++;
        // }
        // for(auto i:m){
        //     if(i.second==1){
        //         return i.first;
        //     }
        // }

        // **********************or******************

        // sort(arr,arr+N);
        // int sum=0,s=0;
        // for(int i=0;i<N-1;i++){
        //     if(arr[i]!=arr[i+1]){
        //         sum+=(arr[i]*3);
        //     }
        //     s+=arr[i];
        // }
        // sum+=(3*arr[N-1]);
        // s+=arr[N-1];
        // return (sum-s)/2;

        // **********************or******************

        bool sign = false;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] < 0)
            {
                arr[i] = -arr[i];
                sign = true;
            }
        }

        int tn = INT_MAX, tn1 = 0, tn2 = 0;
        for (int i = 0; i < N; i++)
        {
            int cwtn = arr[i] & tn;
            int cwtn1 = arr[i] & tn1;
            int cwtn2 = arr[i] & tn2;

            tn = tn & (~cwtn);
            tn1 = tn1 | cwtn;

            tn1 = tn1 & (~cwtn1);
            tn2 = tn2 | cwtn1;

            tn2 = tn2 & (~cwtn2);
            tn = tn | cwtn2;
        }
        if (sign)
            return -tn1;
        else
            return tn1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;
        int arr[N];

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.singleElement(arr, N);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends