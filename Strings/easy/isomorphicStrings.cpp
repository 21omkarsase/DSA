// Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
// Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
// Note: All occurrences of every character in str1 should map to the same character in str2

// Example 1:

// Input:
// str1 = aab
// str2 = xxy
// Output: 1
// Explanation: There are two different
// charactersin aab and xxy, i.e a and b
// with frequency 2and 1 respectively.
// Example 2:

// Input:
// str1 = aab
// str2 = xyz
// Output: 0
// Explanation: There are two different
// charactersin aab but there are three
// different charactersin xyz. So there
// won't be one to one mapping between
// str1 and str2.
// Your Task:
// You don't need to read input or print anything.Your task is to complete the function areIsomorphic() which takes the string str1 and string str2 as input parameter and  check if two strings are isomorphic. The function returns true if strings are isomorphic else it returns false.

// Expected Time Complexity: O(|str1|+|str2|).
// Expected Auxiliary Space: O(Number of different characters).
// Note: |s| represents the length of string s.

// Constraints:
// 1 <= |str1|, |str2| <= 2*104

// View Bookmarked Problems
// Company Tags
//  Google

// { Driver Code Starts
// C++ program to check if two strings are isomorphic

#include <bits/stdc++.h>

using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int l1 = str1.size(), l2 = str2.size();
        if (l1 != l2)
        {
            return false;
        }
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;

        for (int i = 0; i < l1; i++)
        {
            if (m1.find(str1[i]) == m1.end())
            {
                m1[str1[i]] = str2[i];
            }
            else
            {
                if (m1[str1[i]] != str2[i])
                {
                    return false;
                }
            }
        }

        for (int i = 0; i < l2; i++)
        {
            if (m2.find(str2[i]) == m2.end())
            {
                m2[str2[i]] = str1[i];
            }
            else
            {
                if (m2[str2[i]] != str1[i])
                {
                    return false;
                }
            }
        }

        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin >> t;
    string s1, s2;
    while (t--)
    {
        cin >> s1;
        cin >> s2;
        Solution obj;
        cout << obj.areIsomorphic(s1, s2) << endl;
    }

    return 0;
} // } Driver Code Ends