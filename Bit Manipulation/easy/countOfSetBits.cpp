

// // Number of 1 Bits
// // EasyAccuracy: 64.8%Submissions: 44292Points: 2
// // Given a positive integer N, print count of set bits in it.

// // Example 1:

// // Input:
// // N = 6
// // Output:
// // 2
// // Explanation:
// // Binary representation is '110'
// // So the count of the set bit is 2.
// // Example 2:

// // Input:
// // 8
// // Output:
// // 1
// // Explanation:
// // Binary representation is '1000'
// // So the count of the set bit is 1.
// // Your Task:
// // You don't need to read input or print anything. Your task is to complete the function setBits() which takes an Integer N and returns the count of number of set bits.

// // Expected Time Complexity: O(LogN)
// // Expected Auxiliary Space: O(1)

// // Constraints:
// // 1 ≤ N ≤ 109

// // View Bookmarked Problems
// // Company Tags
// // AdobeBrocadeCiscoJuniper NetworksQualcommSamsungWiproMicrosoft

// Number of 1 Bits
// EasyAccuracy: 64.8%Submissions: 44292Points: 2
// Given a positive integer N, print count of set bits in it.

// Example 1:

// Input:
// N = 6
// Output:
// 2
// Explanation:
// Binary representation is '110'
// So the count of the set bit is 2.
// Example 2:

// Input:
// 8
// Output:
// 1
// Explanation:
// Binary representation is '1000'
// So the count of the set bit is 1.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function setBits() which takes an Integer N and returns the count of number of set bits.

// Expected Time Complexity: O(LogN)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 109

// View Bookmarked Problems
// Company Tags
// AdobeBrocadeCiscoJuniper NetworksQualcommSamsungWiproMicrosoft

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int setBits(int N)
    {
        int cnt = 0;
        while (N)
        {
            if (N & 1)
                cnt++;
            N = N >> 1;
        }
        return cnt;
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

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends