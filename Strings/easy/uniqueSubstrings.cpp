// Given a string S, consisting only of ‘0’ and ‘1’, and also you are given an integer k. You are asked to find the sum of all unique substrings (in decimal notation) of length k in the string, such that string S is the repetition of these substrings.

// Example 1:

// Input:
// 010100010010 3
// Output:
//  6
// Exaplanation:
// Unique substrings are “010” and “100”.
// The required sum is 2+4=6.
// Example 2:

// Input:
// 00100110 4
// Output:
// 8

// Your Task:
// You don't need to read or print anything. Your task is to complete the function unique_substring_sum() which takes the binary string S as first parameter and k as the second parameter and returns the sum of unique substring (In decimal notation).If the string S can’t be split into substrings of length k without leaving any characters in the string return -1.

// Expected Time Complexity:  O(n)
// Expected Space Complexity: O(n)

// Constraints:
// 1 <= length of string <= 1000
// k will not exceed 20

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long int binaryToString(string s)
    {
        long int n = stol(s), ans = 0;
        int count = 0;
        while (n)
        {
            int lastDigit = n % 10;
            ans += (long int)(pow(2, count)) * lastDigit;
            n /= 10;
            count++;
        }
        return ans;
    }
    long int unique_substring_sum(string s, int k)
    {
        long int ans = -1;
        string str;
        unordered_map<string, int> m;
        int i = 0, con = k;
        while (i < s.length())
        {
            m[s.substr(i, k)]++;
            str = "";
            i += con;
        }
        if (s.length() % k == 0)
        {
            ans = 0;
            for (auto i : m)
            {
                ans += binaryToString(i.first);
            }
        }
        else
        {
            return -1;
        }

        return ans;
    }
};
// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        int k;
        cin >> s >> k;
        Solution ob;
        long int ans = ob.unique_substring_sum(s, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
