// Print N-bit binary numbers having more 1s than 0s
// MediumAccuracy: 69.91%Submissions: 8123Points: 4
// Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

// Example 1:

// Input:  N = 2
// Output: 11 10
// Explanation: 11 and 10 have more than
// or equal 1's than 0's
// Example 2:

// Input:  N = 3
// Output: 111 110 101
// Explanation: 111, 110 and 101 have more
// than or equal 1's than 0's
// User Task:
// Your task is to complete the function NBitBinary() which takes a single number as input and returns the list of strings in decreasing order. You need not take any input or print anything.

// Expected Time Complexity: O(|2N|)
// Expected Auxiliary Space: O(2N)

// Constraints:
// 1 <= N <= 20

// View Bookmarked Problems
// Topic Tags
// RecursionStrings

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void getBinaryNumbers(int n, vector<string> &ans, int zeros, int ones, string num)
    {
        // at very first time num=="1"
        // add 1 or zero
        if (num.length() == n)
        {
            ans.push_back(num); // if we get num with n bits push it to vector
            return;
        }

        num += "0", zeros++; // adding 0 bit and incresing cnt of zeros
        if (ones >= zeros)
            getBinaryNumbers(n, ans, zeros, ones, num); // calling function after adding zero bit

        zeros--;
        num.erase(num.size() - 1); // removing bit and dec cnt of zeros to call fun after adding 1

        num += "1", ones++;
        getBinaryNumbers(n, ans, zeros, ones, num);
    }

    vector<string> NBitBinary(int N)
    {
        vector<string> ans;
        string num = "1";

        getBinaryNumbers(N, ans, 0, 1, num);
        sort(ans.begin(), ans.end(), greater<string>());

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> ans = ob.NBitBinary(n);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends