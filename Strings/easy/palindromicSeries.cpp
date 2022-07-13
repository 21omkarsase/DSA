// Adobe wants to play a game. He is given a number N. He has to create a alphabetical string in lower case from that number and tell whether the string is palindrome or not. a = 0 , b = 1….. and so on.  For eg : If the number is 61 the substring “gb” will be printed till 7 (6+1) characters i.e. “gbgbgbg” and check if palindrome or not. Adobe is weak in concepts of palindrome and strings, help him in winning the game.
// Note: No number will start with zero. Consider alphabets ' a to j ' only i.e. single digit numbers from 0 to 9.

// Example 1:

// â€‹Input : N = 61
// Output : YES
// Explanation:
// N = 61 the substring “gb” will be
// printed till 7 (6+1) characters i.e.
// “gbgbgbg” and it is palindrome. return
// true.

// â€‹Example 2:

// Input : N = 1998
// Output :  NO

// Your Task:
// This is a function problem. The input is already taken care of by the driver code. You only need to complete the function pallan() that takes an integer (N), and return true if the string is a palindrome otherwise return false if not. The driver code takes care of the printing.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:

// 1 ≤ N ≤ 107

// { Driver Code Starts
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool pallan(int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (pallan(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
} // } Driver Code Ends

bool pallan(int n)
{

    int len = 0;
    string s = to_string(n);
    for (int i = 0; i < s.length(); i++)
    {
        len += s[i] - 48;
        s[i] = s[i] - 48 + 'a';
    }
    int l = len;
    int newLen;
    string str;
    if (len % s.size() != 0)
    {
        len = (len / s.size()) + 1;
        for (int i = 0; i < len; i++)
        {
            str.append(s);
        }
        str = str.substr(0, l);
    }
    else
    {
        len = len / s.size();
        for (int i = 0; i < len; i++)
        {
            str.append(s);
        }
    }

    for (int i = 0; i < (str.length() / 2); i++)
    {
        if (str[i] != str[str.length() - i - 1])
        {
            return false;
        }
    }

    return true;
}
