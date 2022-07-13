// Given a string S consisting of uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

// Example 1:

// Input:
// N = 12
// S = defRTSersUXI
// Output: deeIRSfrsTUX
// Explanation: Sorted form of given string
// with the same case of character as that
// in original string is deeIRSfrsTUX
// Example 2:

// Input:
// N = 6
// S = srbDKi
// Output: birDKs
// Explanation: Sorted form of given string
// with the same case of character will
// result in output as birDKs.
// Your Task:
// You only need to complete the function caseSort that returns sorted string.

// Expected Time Complexity: O(N*Log(N)).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 103

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        unordered_map<int, char> m;
        for (int i = 0; i < n; i++)
        {
            if (str[i] >= 'A' and str[i] <= 'Z')
            {
                m[i] = 'c';
            }
            else if (str[i] >= 'a' and str[i] <= 'z')
            {
                m[i] = 's';
            }
        }
        sort(str.begin(), str.end());
        string capital, small;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 'A' and str[i] <= 'Z')
            {
                capital += str[i];
            }
            else if (str[i] >= 'a' and str[i] <= 'z')
            {
                small += str[i];
            }
        }
        int c = 0, s = 0;
        string ans;
        for (int i = 0; i < n; i++)
        {
            if (m[i] == 'c')
            {
                ans += capital[c];
                c++;
            }
            else if (m[i] == 's')
            {
                ans += small[s];
                s++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        Solution obj;
        cout << obj.caseSort(str, n) << endl;
    }
} // } Driver Code Ends