// Permutations of a given string
// MediumAccuracy: 49.85%Submissions: 60577Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.

// Example 1:

// Input: ABC
// Output:
// ABC ACB BAC BCA CAB CBA
// Explanation:
// Given string ABC has permutations in 6
// forms as ABC, ACB, BAC, BCA, CAB and CBA .
// Example 2:

// Input: ABSG
// Output:
// ABGS ABSG AGBS AGSB ASBG ASGB BAGS
// BASG BGAS BGSA BSAG BSGA GABS GASB
// GBAS GBSA GSAB GSBA SABG SAGB SBAG
// SBGA SGAB SGBA
// Explanation:
// Given string ABSG has 24 permutations.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function find_permutaion() which takes the string S as input parameter and returns a vector of string in lexicographical order.

// Expected Time Complexity: O(n! * n)

// Expected Space Complexity: O(n)

// Constraints:
// 1 <= length of string <= 5

// View Bookmarked Problems
// Company Tags
// Accolite Amazon Cisco Citrix MAQ Software OYO Rooms Samsung Snapdeal Walmart Zoho Microsoft
// Topic Tags
// Recursion Strings Backtracking

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void getPermutations(vector<string> &ans, string s, int start)
    {
        if (start == s.size() - 1)
        {
            auto it = find(ans.begin(), ans.end(), s);

            if (it == ans.end())
            {
                ans.push_back(s);
            }

            return;
        }
        for (int j = start; j < s.size(); j++)
        {
            swap(s[start], s[j]);

            getPermutations(ans, s, start + 1);
            swap(s[start], s[j]);
        }
    }

    vector<string> find_permutation(string S)
    {
        vector<string> ans;
        getPermutations(ans, S, 0);
        sort(ans.begin(), ans.end());
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
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends