// Given two stringsaandbconsisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, act and tac are an anagram of each other.

// Example 1:

// Input:a = geeksforgeeks, b = forgeeksgeeks
// Output: YES
// Explanation: Both the string have samecharacters with
//         same frequency. So, both are anagrams.
// Example 2:

// Input:a = allergy, b = allergic
// Output: NO
// Explanation:Characters in both the strings are
//         not same, so they are not anagrams.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isAnagram() which takes the string a and string b as input parameter and check if the two strings are an anagram of each other. The function returns true if the strings are anagram else it returns false.

// Note: In python, you have to return True or False.

// Expected Time Complexity:O(|a|+|b|).
// Expected Auxiliary Space:O(Number of distinct characters).

// Note: |s| represents the length of string s.

// Constraints:
// 1 ≤ |a|,|b| ≤ 105

// View Bookmarked Problems
// Company Tags
//  Nagarro Media.net Directi Google Adobe Flipkart
// Topic Tags
//  Strings Sorting

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a == b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// { Driver Code Starts.

int main()
{

    int t;

    cin >> t;

    while (t--)
    {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
// } Driver Code Ends