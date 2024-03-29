// Given a string str, convert the first letter of each word in the string to uppercase.

// Example 1:

// Input:
// str = "i love programming"
// Output: "I Love Programming"
// Explanation:
// 'I', 'L', 'P' are the first letters of
// the three words.

// Your Task:
// You dont need to read input or print anything. Complete the function transform() which takes s as input parameter and returns the transformed string.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N) to store resultant string

// Constraints:
// 1 <= N <= 104
// The original string str only consists of lowercase alphabets and spaces to separate words.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string str);
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string str;
        getline(cin, str);
        cout << transform(str) << endl;
    }
    return 0;
} // } Driver Code Ends

string transform(string s)
{
    int n = s.length();
    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0)
        {
            s[i] -= 32;
            flag = false;
        }
        else if (s[i] == ' ')
        {
            i++;
            s[i] -= 32;
        }
    }
    return s;
}