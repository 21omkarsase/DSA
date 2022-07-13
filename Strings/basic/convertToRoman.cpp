// Given an integer n, your task is to complete the function convertToRoman which prints the corresponding roman number of n. Various symbols and their values are given below
// Note:- There are a few exceptions for some numbers like 4 in roman is IV,9 in roman is IX, similarly, 40 is XL while 90 is XC. Similarly, 400 is CD while 900 is CM

// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000

// Example 1:

// Input:
// n = 5
// Output: V

// Example 2:

// Input:
// n = 3
// Output: III

// Your Task:
// Complete the function convertToRoman() which takes an integer N as input parameter and returns the equivalent roman.

// Expected Time Complexity: O(log10N)
// Expected Auxiliary Space: O(log10N * 10)

// Constraints:
// 1<=n<=3999

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string convertToRoman(int n)
    {
        // code here
        string units[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousands[] = {"", "M", "MM", "MMM"};

        return thousands[n / 1000] + hundreds[(n % 1000) / 100] + tens[(n % 100) / 10] + units[n % 10];
    }
};

// { Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.convertToRoman(N) << endl;
    }
    return 0;
} // } Driver Code Ends