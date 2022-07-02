// Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.

// Example 1:

// Input:
// N = 6
// arr[] = {3,0,0,2,0,4}
// Output:
// 10
// Explanation:

// Example 2:

// Input:
// N = 4
// arr[] = {7,4,0,9}
// Output:
// 10
// Explanation:
// Water trapped by above
// block of height 4 is 3 units and above
// block of height 0 is 7 units. So, the
// total unit of water trapped is 10 units.
// Example 3:

// Input:
// N = 3
// arr[] = {6,9,9}
// Output:
// 0
// Explanation:
// No water will be trapped.

// Your Task:
// You don't need to read input or print anything. The task is to complete the function trappingWater() which takes arr[] and N as input parameters and returns the total amount of water that can be trapped.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 3 < N < 106
// 0 < Ai < 108

// // { Driver Code Starts
// #include<bits/stdc++.h>

// using namespace std;

//  // } Driver Code Ends
// class Solution{

//     // Function to find the trapped water between the blocks.
//     public:
//     long long trappingWater(int arr[], int n){
//         // code here
//         if(n<2){
//             return 0;
//         }
//         bool sameHeight=true;
//         for(int i=0;i<n-1;i++){
//             if(arr[i]!=arr[i+1]){
//                 sameHeight=false;
//             }
//         }
//         if(sameHeight){
//             return 0;
//         }

//         int blockCount = arr[0];
//         long long ans = 0;
//         int max = arr[0];
//         int rows = 1;
//         for (int i = 1; i < n; i++)
//         {
//             rows++;
//             blockCount += arr[i];
//             if (arr[i] >= max and rows > 2)
//             {
//                 blockCount = blockCount - (arr[i] - max);
//                 int totalBlocks = max * rows;
//                 ans += totalBlocks - blockCount;
//                 max = arr[i];
//                 blockCount = arr[i];
//                 rows = 1;
//                 cout << ans << endl;
//             }
//             else if (arr[i] < max && i == (n - 1))
//             {
//                 blockCount = blockCount - (max - arr[n - 1]);
//                 int totalBlocks = rows * arr[n - 1];
//                 ans += totalBlocks - blockCount;
//                 cout << ans << endl;
//             }
//         }
//         return ans;
//     }
// };

// // { Driver Code Starts.

// int main(){

//     int t;
//     //testcases
//     cin >> t;

//     while(t--){
//         int n;

//         //size of array
//         cin >> n;

//         int a[n];

//         //adding elements to the array
//         for(int i =0;i<n;i++){
//             cin >> a[i];
//         }
//         Solution obj;
//         //calling trappingWater() function
//         cout << obj.trappingWater(a, n) << endl;

//     }

//     return 0;
// }  // } Driver Code Ends

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        // code here
        long long ans = 0;
        int left[n], right[n];
        int lMax = arr[0];
        int rMax = arr[n - 1];
        for (int i = 0; i < n; i++)
        {
            left[i] = max(lMax, arr[i]);
            lMax = left[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            right[i] = max(arr[i], rMax);
            rMax = right[i];
        }

        for (int i = 0; i < n; i++)
        {
            int minNo = min(right[i], left[i]);
            ans += minNo - arr[i];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends