

// Is Binary Number Multiple of 3
// MediumAccuracy: 46.33%Submissions: 9745Points: 4
// Given a binary number, Find, if given binary number is a multiple of 3. The given number can be big upto 2^10000. It is recommended to finish the task using one traversal of input binary string.

// Example 1:

// Input: S = "011"
// Output: 1
// Explanation: "011" decimal equivalent
// is 3, which is divisible by 3.
// â€‹Example 2:

// Input: S = "100"
// Output: 0
// Explanation: "100" decimal equivalent
// is 4, which is not divisible by 3.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isDivisible() which takes the string s as inputs and returns 1 if the given number is divisible by 3 otherwise 0.

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ |S| ≤ 105

// View Bookmarked Problems
// Company Tags
// AdobeAmazonMicrosoft

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int isDivisible(string s)
    {
        int oddCnt = 0, evenCnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                if ((i + 1) & 1)
                    oddCnt++;
                else
                    evenCnt++;
            }
        }

        return (abs(oddCnt - evenCnt) % 3 == 0);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
    return 0;
}

// } Driver Code Ends