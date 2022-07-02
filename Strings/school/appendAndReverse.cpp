//

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    string conRevstr(string S1, string S2)
    {
        // code here
        S1.append(S2);
        int l = S1.length() / 2, n = S1.length();
        for (int i = 0; i < l; i++)
        {
            char temp = S1[i];
            S1[i] = S1[n - i - 1];
            S1[n - i - 1] = temp;
        }
        return S1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S1, S2;
        cin >> S1;
        cin >> S2;
        Solution ob;
        cout << ob.conRevstr(S1, S2) << endl;
    }
    return 0;
}
// } Driver Code Ends