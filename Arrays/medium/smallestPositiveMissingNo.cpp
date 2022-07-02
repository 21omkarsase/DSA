
// You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

// Example 1:

// Input:
// N = 5
// arr[] = {1,2,3,4,5}
// Output: 6
// Explanation: Smallest positive missing
// number is 6.
// Example 2:

// Input:
// N = 5
// arr[] = {0,-10,1,3,-20}
// Output: 2
// Explanation: Smallest positive missing
// number is 2.
// Your Task:
// The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 106
// -106 <= arr[i] <= 106

// // { Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std;

//  // } Driver Code Ends

// class Solution
// {
//     public:
//     //Function to find the smallest positive number missing from the array.
//     int missingNumber(int arr[], int n)
//     {
//         // Your code here
//         sort(arr,arr+n);
//         int missingNo=1,start=0,count=0;
//         bool allNegative=true;
//         for(int i=0;i<n;i++){
//             if(arr[i]>=1){
//                 start=i;
//                 break;
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(arr[i]>=1){
//                 allNegative=false;
//             }
//         }
//         if(allNegative){
//             return 1;
//         }

//         bool noMissing=false;
//         for(int i=start;i<n;i++){
//             count++;
//             if(arr[i]!=count){
//                 missingNo=count;
//                 noMissing=true;
//                 break;
//             }
//         }
//         if(noMissing){
//             return missingNo;
//         }
//         else{
//             return arr[n-1]+1;
//         }
//     }
// };

// // { Driver Code Starts.

// int missingNumber(int arr[], int n);

// int main() {

//     //taking testcases
//     int t;
//     cin>>t;
//     while(t--){

//         //input number n
//         int n;
//         cin>>n;
//         int arr[n];

//         //adding elements to the array
//         for(int i=0; i<n; i++)cin>>arr[i];

//         Solution ob;
//         //calling missingNumber()
//         cout<<ob.missingNumber(arr, n)<<endl;
//     }
//     return 0;
// }   // } Driver Code Ends

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        // Your code here
        sort(arr, arr + n);
        int start = 1;
        for (int i = 0; i < n; i++)
        {
            if (start == arr[i])
            {
                start++;
            }
        }
        return start;
    }
};

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main()
{

    // taking testcases
    int t;
    cin >> t;
    while (t--)
    {

        // input number n
        int n;
        cin >> n;
        int arr[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        // calling missingNumber()
        cout << ob.missingNumber(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends