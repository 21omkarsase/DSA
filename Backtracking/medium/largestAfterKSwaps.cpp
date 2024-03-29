// Largest number in K swaps
// MediumAccuracy: 46.92%Submissions: 47263Points: 4
// Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.

// Example 1:

// Input:
// K = 4
// str = "1234567"
// Output:
// 7654321
// Explanation:
// Three swaps can make the
// input 1234567 to 7654321, swapping 1
// with 7, 2 with 6 and finally 3 with 5
// Example 2:

// Input:
// K = 3
// str = "3435335"
// Output:
// 5543333
// Explanation:
// Three swaps can make the input
// 3435335 to 5543333, swapping 3
// with 5, 4 with 5 and finally 3 with 4

// Your task:
// You don't have to read input or print anything. Your task is to complete the function findMaximumNum() which takes the string and an integer as input and returns a string containing the largest number formed by perfoming the swap operation at most k times.

// Expected Time Complexity: O(n!/(n-k)!) , where n = length of input string
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ |str| ≤ 30
// 1 ≤ K ≤ 10

// View Bookmarked Problems
// Company Tags
// AmazonMakeMyTripWalmartMicrosoftGoogleIntuit
// Topic Tags
// BacktrackingStrings

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the largest number after k swaps.

    void helper(string &maxNo, string str, int k, int idx)
    {
        if (k == 0)
            return;

        int n = str.size();
        char maxc = str[idx];
        for (int i = idx + 1; i < str.size(); i++)
            if (maxc < str[i])
                maxc = str[i];

        if (maxc != str[idx])
            k -= 1;

        for (int i = idx; i < n; i++)
        {
            if (str[i] == maxc)
            {
                swap(str[i], str[idx]);
                if (str.compare(maxNo) > 0)
                    maxNo = str;
                helper(maxNo, str, k, idx + 1);
                swap(str[i], str[idx]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        string maxNo = str;
        helper(maxNo, str, k, 0);

        return maxNo;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends