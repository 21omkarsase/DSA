//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

//***********************Recursive solution**********************
// void reverseTheStack(stack<int> s, vector<int> &ans)
// {

//     if (s.empty())
//         return;

//     int a = s.top();
//     s.pop();
//     ans.push_back(a);
//     reverseTheStack(s, ans);
// }

// vector<int> Reverse(stack<int> St)
// {
//     vector<int> ans;
//     reverseTheStack(St, ans);
//     return ans;
// }

// ***************Non recursive solution*****************
class Solution
{
public:
    void reverseTheStack(stack<int> &s, vector<int> &ans)
    {
        if (s.empty())
            return;

        int a = s.top();
        cout << a << " ";
        s.pop();
        ans.push_back(a);
    }

    vector<int> Reverse(stack<int> St)
    {
        vector<int> ans;
        while (!St.empty())
        {
            ans.push_back(St.top());
            St.pop();
        }
        // cout << endl;

        // reverseTheStack(St, ans);
        // cout << endl;

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    // int T;
    // cin >> T;
    // while (T--)
    // {
    int N;
    cin >> N;
    stack<int> St;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        St.push(x);
    }
    Solution ob;
    vector<int> ans = ob.Reverse(St);
    for (int i = 0; i < N; i++)
    {
        cout << ans[i];
        if (i != N - 1)
            cout << " ";
    }
    cout << endl;
    // }
}
// } Driver Code Ends