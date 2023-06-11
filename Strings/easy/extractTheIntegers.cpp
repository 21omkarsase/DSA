// Given a string s, extract all the integers from s.

// Example 1:

// Input:
// s = "1: Prakhar Agrawal, 2: Manish Kumar Rai,
//      3: Rishabh Gupta56"
// Output: 1 2 3 56
// Explanation:
// 1, 2, 3, 56 are the integers present in s.
// Example 2:

// Input:
// s = "geeksforgeeks"
// Output: No Integers
// Explanation:
// No integers present in the string.

// Your Task:
// You don't need to read input or print anything. Complete the function extractIntegerWords() which takes string s as input and returns a list of integers. If an empty list is returned the output is printed as "No Integers".

// Expected Time Complexity: O(|s|).
// Expected Auxiliary Space: O(|s|).

// Constraints:
// 1<=|s|<=105

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<string> extractIntegerWords(string s);

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string str;
        getline(cin, str);
        vector<string> ans = extractIntegerWords(str);
        if (ans.size() == 0)
            cout << "No Integers";
        else
            for (auto i : ans)
                cout << i << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<string> extractIntegerWords(string s)
{
    vector<string> ans;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        if (i == 0)
        {
            if (s[i] >= '0' and s[i] <= '9')
            {
                string num = "";
                num += s[i];
                ans.push_back(num);
            }
        }
        else
        {
            if (s[i] >= '0' and s[i] <= '9')
            {
                if (s[i - 1] >= '0' and s[i - 1] <= '9')
                {
                    string num = "";
                    num += s[i];
                    num = ans.back() + num;
                    ans.pop_back();
                    ans.push_back(num);
                }
                else
                {
                    string num = "";
                    num += s[i];
                    ans.push_back(num);
                }
            }
        }
    }
    return ans;
}