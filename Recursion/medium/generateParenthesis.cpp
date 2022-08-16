//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);

// } Driver Code Ends
// User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
public:
    void getStrings(vector<string> &v, string s, int ob, int cb, int n)
    {

        if (ob == n and cb == n)
            v.push_back(s);

        if (ob < n)
            getStrings(v, s + "(", ob + 1, cb, n);

        if (cb < ob)
            getStrings(v, s + ")", ob, cb + 1, n);
    }

    vector<string> AllParenthesis(int n)
    {
        vector<string> v;
        getStrings(v, "", 0, 0, n);
        cout << endl;
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> result = ob.AllParenthesis(n);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";
    }
    return 0;
}

// } Driver Code Ends