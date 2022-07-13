// Given a string str. The task is to find the maximum occurring character in the string str. If more than one character occurs the maximum number of time then print the lexicographically smaller character.

// Example 1:

// Input:
// str = testsample
// Output: e
// Explanation: e is the character which
// is having the highest frequency.
// Example 2:

// Input:
// str = output
// Output: t
// Explanation:  t and u are the characters
// with the same frequency, but t is
// lexicographically smaller.
// Your Task:
// The task is to complete the function getMaxOccuringChar() which returns the character which is most occurring.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Number of distinct characters).
// Note: N = |s|

// Constraints:
// 1 ≤ |s| ≤ 100

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        unordered_map<char, int> m;
        for (int i = 0; i < str.length(); i++)
        {
            m[str[i]]++;
        }
        int maxLen = 0;
        char ans = 'z';
        for (auto it : m)
        {
            if (it.second >= maxLen)
            {
                if (it.first < ans and it.second == maxLen)
                {
                    ans = it.first;
                    maxLen = it.second;
                }
                else if (it.second > maxLen)
                {
                    ans = it.first;
                    maxLen = it.second;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        cout << obj.getMaxOccuringChar(str) << endl;
    }
} // } Driver Code Ends

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        // unordered_map<char,int>m;
        // for(int i=0;i<str.length();i++){
        //     m[str[i]]++;
        // }
        // int maxLen=0;
        // char ans='z';
        // for(auto it:m){
        //     if(it.second>=maxLen){
        //         if(it.first<ans and it.second==maxLen){
        //             ans=it.first;
        //             maxLen=it.second;
        //         }
        //         else if(it.second>maxLen){
        //             ans=it.first;
        //             maxLen=it.second;
        //         }
        //     }
        // }
        // return ans;

        //****************another way**********************

        int ans, maxLen = 0;
        int count[26] = {0};
        for (int i = 0; i < str.length(); i++)
        {
            count[str[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > maxLen)
            {
                ans = i;
                maxLen = count[i];
            }
        }
        return ans + 'a';
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        cout << obj.getMaxOccuringChar(str) << endl;
    }
} // } Driver Code Ends