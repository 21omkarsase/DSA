//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
#define mod 1000000007
class Solution
{
public:
    vector<ll> nthRowOfPascalTriangle(int n)
    {
        vector<vector<ll>> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i].resize(i + 1);
            ans[i][0] = ans[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                ans[i][j] = (ans[i - 1][j - 1] + ans[i - 1][j]) % mod;
            }
        }
        vector<ll> pas;
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1)
            {
                continue;
            }
            for (int j = 0; j < i + 1; j++)
            {
                //   cout<<ans[i][j]<<" ";
                pas.push_back(ans[i][j]);
            }
            //   cout<<endl;
        }
        return pas;
    }
};

//{ Driver Code Starts.

void printAns(vector<ll> &ans)
{
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends