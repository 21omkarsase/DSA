// Given a sorted array A[] of size N, delete all the duplicates elements from A[].
// Note: Don't use set or HashMap to solve the problem.

// Example 1:

// Input:
// N = 5
// Array = {2, 2, 2, 2, 2}
// Output: 1
// Explanation: After removing all the duplicates
// only one instance of 2 will remain.
// Example 2:

// Input:
// N = 3
// Array = {1, 2, 2}
// Output: 2

// Your Task:
// You don't need to read input or print anything. Complete the function remove_duplicate() which takes the array A[] and its size N as input parameters and modifies it in place to delete all the duplicates. The function must return an integer X denoting the new modified size of the array.
// Note: The generated output will print all the elements of the modified array from index 0 to X-1.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 104
// 1 ≤ A[i] ≤ 106

// // { Driver Code Starts
// //Initial template for C++

// #include <bits/stdc++.h>
// using namespace std;

//  // } Driver Code Ends
// //User function template for C++

// class Solution{
// public:
//     int remove_duplicate(int a[],int n){
//         // code here
//         int count=n;
//         unordered_map<int,int>m;
//         for(int i=0;i<n;i++)
//         {
//             m[a[i]]++;
//         }
//         for(auto it:m){
//             if(it.second>1)
//             {
//                 count=count-it.second+1;
//             }
//         }
//         return count;

//     }
// };

// // { Driver Code Starts.
// int main()
// {
//     int T;
//     cin>>T;
//     while(T--)
//     {
//         int N;
//         cin>>N;
//         int a[N];
//         for(int i=0;i<N;i++)
//         {
//             cin>>a[i];
//         }
//     Solution ob;
//     int n = ob.remove_duplicate(a,N);

//     for(int i=0;i<n;i++)
//         cout<<a[i]<<" ";
//     cout<<endl;
//     }
// }  // } Driver Code Ends

// { Driver Code Starts
// Initial template for C++

// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// // User function template for C++

// class Solution
// {
// public:
//     int remove_duplicate(int a[], int n)
//     {
//         int count = n;
//         for (int i = 1; i < n; i++)
//         {
//             if (a[i] == a[i - 1])
//             {
//                 count--;
//             }
//         }
//         return count;
//     }
// };

// // { Driver Code Starts.
// int main()
// {
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         int N;
//         cin >> N;
//         int a[N];
//         for (int i = 0; i < N; i++)
//         {
//             cin >> a[i];
//         }
//         Solution ob;
//         int n = ob.remove_duplicate(a, N);

//         for (int i = 0; i < n; i++)
//             cout << a[i] << " ";
//         cout << endl;
//     }
// } // } Driver Code Ends

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int remove_duplicate(int a[], int n)
    {
        int i = 0, j = 1;
        while (j < n)
        {
            if (a[j] != a[j - 1])
            {
                i++;
                a[i] = a[j];
            }
            j++;
        }
        return i + 1;

        // int ans = n;
        // for (int i = 1; i < n; i++)
        // {
        //     if (a[i] == a[i - 1])
        //         ans--;
        // }
        // cout << ans << " ";
        // cout << endl;
        // return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int a[N];
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        int n = ob.remove_duplicate(a, N);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends
