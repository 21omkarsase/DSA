// Given a list of names, display the longest name.

// Example:

// Input:
// N = 5
// names[] = { "Geek", "Geeks", "Geeksfor",
//   "GeeksforGeek", "GeeksforGeeks" }

// Output:
// GeeksforGeeks

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longest() which takes the array names[] and its size N as inputs and returns the Longest name in the list of names.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 100
// 1 <= |length of name| <= 1000

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string longest(string names[], int n)
    {
        string longest = "";
        int longStr = longest.length();
        for (int i = 0; i < n; i++)
        {
            if (names[i].length() > longStr)
            {
                longest = names[i];
                longStr = names[i].length();
            }
        }
        return longest;
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
        string names[n];

        for (int i = 0; i < n; i++)
            cin >> names[i];
        Solution ob;
        cout << ob.longest(names, n) << endl;
    }
}
// } Driver Code Ends