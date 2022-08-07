// Concatenate two numbers
// HardAccuracy: 67.57%Submissions: 6705Points: 8
// Given an array numbers[] of N positive integers and a positive integer X, The task is to find the number of ways that X can be obtained by writing pair of integers in the array numbers[] next to each other. In other words, find the number of ordered pairs (i,j) such that i != j and X is the concatenation of numbers[i] and numbers[j]

// Example 1:

// Input:
// N = 4
// numbers[] = {1, 212, 12, 12}
// X = 1212
// Output:
// 3
// Explanation:
// We can obtain X=1212 by concatenating:
// numbers[0] = 1 with numbers[1] = 212
// numbers[2] = 12 with numbers[3] = 12
// numbers[3] = 12 with numbers[2] = 12
// Example 2:

// Input:
// N = 3
// numbers[] = {11, 11, 110}
// X = 11011
// Output:
// 2
// Explanation:
// We can obtain X=11011 by concatenating:
// numbers[2] = 110 with numbers[0] = 11
// numbers[2] = 110 with numbers[1] = 11
// Your Task:
// You dont need to read input or print anything. Your task is to complete the function countPairs() which takes the integer N , the integer X, and the array numbers[] as the input parameters, and returns the number of pairs which satisfies the above condition.

// Expected Time Complexity: O(N*Log10(A[i]) + (Log10X)2)
// Expected Auxiliary Space: O(N*Log10(A[i]))

// Constraints:
// 1 ≤ N ≤ 5*104
// 1 ≤ numbers[] ≤ 109
// 1 ≤ X ≤ 109

// View Bookmarked Problems
// Topic Tags
// MapData Structures

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long countPairs(int N, int X, vector<int> numbers)
    {
        long long ans = 0;
        unordered_map<string, int> m;
        for (int i = 0; i < N; i++)
        {
            m[to_string(numbers[i])]++;
        }

        string x = to_string(X);
        for (int i = 1; i < x.size(); i++)
        {
            string first = x.substr(0, i);
            string second = x.substr(i);

            if (first == second)
                ans += (m[first] * (m[second] - 1));
            else
                ans += (m[first] * m[second]);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, X;
        cin >> N >> X;
        vector<int> numbers(N);
        for (int i = 0; i < N; i++)
            cin >> numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends