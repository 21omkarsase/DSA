// Given an array of size N and you have to tell whether the array is perfect or not. An array is said to be perfect if it's reverse array matches the original array. If the array is perfect then print "PERFECT" else print "NOT PERFECT".

// Example 1:

// Input : Arr[] = {1, 2, 3, 2, 1}
// Output : PERFECT
// Explanation:
// Here we can see we have [1, 2, 3, 2, 1]
// if we reverse it we can find [1, 2, 3, 2, 1]
// which is the same as before.
// So, the answer is PERFECT.

// Example 2:

// Input : Arr[] = {1, 2, 3, 4, 5}
// Output : NOT PERFECT

// User Task:
// The task is to complete the function IsPerfect(), which takes an array (a), size of the array (n), and return the boolean value true if it Perfect else false. The drivercode automatically adds a new line.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ ai ≤ 103

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool IsPerfect(int a[], int n)
    {
        // Complete the function
        bool flag = true;
        int mid = n / 2;
        for (int i = 0; i < mid; i++)
        {
            if (a[i] != a[n - 1 - i])
            {
                flag = false;
            }
        }
        return flag;
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
        Solution ob;
        if (ob.IsPerfect(a, n))
            cout << "PERFECT\n";
        else
            cout << "NOT PERFECT\n";
    }

} // } Driver Code Ends