// Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
// For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

// Example 1:

// Input:
// {([])}
// Output:
// true
// Explanation:
// { ( [ ] ) }. Same colored brackets can form
// balaced pairs, with 0 number of
// unbalanced bracket.
// Example 2:

// Input:
// ()
// Output:
// true
// Explanation:
// (). Same bracket can form balanced pairs,
// and here only 1 type of bracket is
// present and in balanced way.
// Example 3:

// Input:
// ([]
// Output:
// false
// Explanation:
// ([]. Here square bracket is balanced but
// the small bracket is not balanced and
// Hence , the output will be unbalanced.
// Your Task:
// This is a function problem. You only need to complete the function ispar() that takes a string as a parameter and returns a boolean value true if brackets are balanced else returns false. The printing is done automatically by the driver code.

// Expected Time Complexity: O(|x|)
// Expected Auixilliary Space: O(|x|)

// Constraints:
// 1 ≤ |x| ≤ 32000

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool ispar(string x)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < x.length(); i++)
        {
            m[x[i]]++;
        }
        int soc = m['('], scc = m[')'], coc = m['{'], ccc = m['}'], xoc = m['['], xcc = m[']'];
        stack<char> s;
        if (soc == scc and coc == ccc and xoc == xcc)
        {
            for (int i = 0; i < x.length(); i++)
            {
                if (x[i] == '{' or x[i] == '[' or x[i] == '(')
                {
                    s.push(x[i]);
                }
                else
                {
                    if (!s.empty())
                    {
                        if (x[i] == ')' and s.top() == '(')
                        {
                            s.pop();
                        }
                        else if (x[i] == '}' and s.top() == '{')
                        {
                            s.pop();
                        }
                        else if (x[i] == ']' and s.top() == '[')
                        {
                            s.pop();
                        }
                    }
                }
            }
            if (s.empty())
            {
                return true;
            }
            else
            {
                return false;
            }
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
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
} // } Driver Code Ends