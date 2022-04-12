// Given a number N. Your task is to check whether it is fascinating or not.
// Fascinating Number: When a number(should contain 3 digits or more) is multiplied by 2 and 3 ,and when both these products are concatenated with the original number, then it results in all digits from 1 to 9 present exactly once.

// Example 1:

// Input:
// N = 192
// Output: Fascinating
// Explanation: After multiplication with 2
// and 3, and concatenating with original
// number, number will become 192384576
// which contains all digits from 1 to 9.
// Example 2:

// Input:
// N = 853
// Output: Not Fascinating
// Explanation: It's not a fascinating
// number.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function fascinating() which takes the integer n parameters and returns boolean denoting the answer.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// 100 <= N <= 109

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    bool fascinating(int n)
    {
        // code here
        int twoMul = n * 2;
        int threeMul = n * 3;

        string s1 = to_string(twoMul);
        string s2 = to_string(threeMul);
        string s3 = to_string(n);

        string final = s3 + s1 + s2;
        // cout << final.length() << endl;
        // bool ans[final.length()+1];
        // for (int i = 0; i < final.length(); i++)
        // {
        //     ans[i] = false;
        // }
        // for (int i = 1; i <= final.length(); i++)
        // {
        //     ans[final[i]] = true;
        // }

        // for (int i = 1; i <=final.length(); i++)
        // {
        //     if (ans[i] == false)
        //     {
        //         return false;
        //     }
        // }
        sort(final.begin(), final.end());
        if (final == "123456789")
        {
            return true;
        }
        return false;
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
        Solution ob;
        auto ans = ob.fascinating(n);
        if (ans)
        {
            cout << "Fascinating\n";
        }
        else
        {
            cout << "Not Fascinating\n";
        }
    }
    return 0;
} // } Driver Code Ends