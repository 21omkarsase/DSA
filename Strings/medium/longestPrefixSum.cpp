// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++


// *********************TLE******************
class Solution
{
public:
    int lps(string s)
    {
        int n = s.length(), i = 0, j = 0;
        string pp = s.substr(0, n - 1 - i);
        string ps = s.substr(1 + j, n - 1 - j);
        int plen = pp.length(), psuf = ps.length();

        while (pp.size() > 0 and ps.size() > 0)
        {
            if (pp != ps)
            {
                j++;
                i++;
                pp = pp.substr(0, n - 1 - i);
                ps = ps.substr(1 + j, n - 1 - j);
            }
            else if (pp == ps)
            {
                return pp.size();
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main()
{

    // ios_base::sync_with_stdio(0);
    // cin.tie(NULL);
    // cout.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    // {
    string str;
    cin >> str;

    Solution ob;

    cout << ob.lps(str) << "\n";
    // }

    return 0;
}
// } Driver Code Ends