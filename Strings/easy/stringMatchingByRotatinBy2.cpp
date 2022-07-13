// Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating another string 'a' by exactly 2 places.

// Example 1:

// Input:
// a = amazon
// b = azonam
// Output: 1
// Explanation: amazon can be rotated anti
// clockwise by two places, which will make
// it as azonam.
// Example 2:

// Input:
// a = geeksforgeeks
// b = geeksgeeksfor
// Output: 0
// Explanation: If we rotate geeksforgeeks by
// two place in any direction , we won't get
// geeksgeeksfor.
// Your Task:
// The task is to complete the function isRotated() which takes two strings as input parameters and checks if given strings can be formed by rotations. The function returns true if string 1 can be obtained by rotating string 2 by two places, else it returns false.

// Expected Time Complexity: O(N).
// Expected Auxilary Complexity: O(N).
// Challenge: Try doing it in O(1) space complexity.

// Constraints:
// 1 ≤ length of a, b ≤ 105

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        string first = str1.substr(0, 2);
        string second = str1.substr(2);
        string ans = second + first;
        if (ans == str2)
        {
            return true;
        }
        first = str1.substr(0, str1.length() - 2);
        second = str1.substr(str1.length() - 2, 2);
        ans = second + first;
        if (ans == str2)
        {
            return true;
        }

        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        string b;
        cin >> s >> b;
        Solution obj;
        cout << obj.isRotated(s, b) << endl;
    }
    return 0;
}
// } Driver Code Ends