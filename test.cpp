//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.

    void getAllCombinations(vector<vector<int>> &ans, vector<int> v, vector<int> t, int s, int i)
    {
        if (s == 0)
        {
            ans.push_back(t);
            return;
        }

        while (i < v.size() and s - v[i] >= 0)
        {
            t.push_back(v[i]);
            getAllCombinations(ans, v, t, s - v[i], i);
            t.pop_back();
            i++;
        }
    }

    void getTaskDone(vector<vector<int>> &ans, vector<int> v, int s)
    {
        vector<int> t;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end()); // removing duplicates
        getAllCombinations(ans, v, t, s, 0);
    }

    vector<vector<int>>
    combinationSum(vector<int> &A, int B)
    {
        vector<vector<int>> ans;
        getTaskDone(ans, A, B);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    int n;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    int sum;
    cin >> sum;
    Solution ob;
    vector<vector<int>> result = ob.combinationSum(A, sum);
    if (result.size() == 0)
    {
        cout << "Empty";
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << '(';
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << " ";
        }
        cout << ")";
    }
    cout << "\n";
    // }
}
// } Driver Code Ends