// Given an array arr[] containing positive elements. ‘A’ and ‘B’ are two numbers defining a range. The task is to check if the array contains all elements in the given range.

// Example 1:

// Input: N = 7, A = 2, B = 5
// arr[] =  {1, 4, 5, 2, 7, 8, 3}
// Output: Yes
// Explanation: It has elements between
// range 2-5 i.e 2,3,4,5
// Example 2:

// Input: N = 7, A = 2, B = 6
// arr[] = {1, 4, 5, 2, 7, 8, 3}
// Output: No
// Explanation: Array does not contain 6.

// Your Task:
// This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function check_elements() that takes array arr, integer N, integer A, and integer B  as parameters and returns the boolean True if array elements contain all elements in the given range else boolean False.

// Note: If the array contains all elements in the given range then driver code outputs Yes otherwise, it outputs No

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 107

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    bool check_elements(int arr[], int n, int A, int B)
    {
        // Your code goes here
        set<int> s;
        for (int i = A; i <= B; i++)
        {
            s.insert(i);
        }
        for (int i = 0; i < n; i++)
        {
            if (s.count(arr[i]))
            {
                s.erase(arr[i]);
            }
        }
        return s.empty();
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, A, B;
        cin >> n >> A >> B;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        Solution ob;
        if (ob.check_elements(a, n, A, B))
            cout << "Yes";
        else
            cout << "No";

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends