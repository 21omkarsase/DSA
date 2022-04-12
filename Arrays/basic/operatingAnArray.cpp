// Given an array A of size N, your task is to do some operations, i.e., search an element, insert an element, and delete an element by completing the functions. Also, all functions should return a boolean value.

// Input Format:
// The first line of input consists of T, the number of test cases. T testcases follow. Each testcase contains 3 lines of input. The first line of every test case consists of an integer N, denotes the number of elements in an array. The second line of every test cases consists of N spaced integers Ai. The third line of every test case consists of four integers X, Y, Yi and Z, denoting the elements for the search operation, insert operation, insert operation element index and delete operation respectively.

// Output Format:
// For each testcase, return 1 for each operation if done successfully else 0.

// Your Task:
// Since this is a function problem, you only need to complete the provided functions.

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 100
// 0 <= Ai <= 1000

// Example:
// Input:
// 1
// 5
// 2 4 1 0 6
// 1 2 2 0
// Output:
// 1 1 1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
bool searchEle(int a[], int x);
bool insertEle(int a[], int y, int yi);
bool deleteEle(int a[], int z);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[10000];
        memset(a, -1, sizeof(a));
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int x, y, yi, z;
        cin >> x >> y >> yi >> z;
        bool b = searchEle(a, x);
        if (b == true)
            cout << "1 ";
        else
            cout << "0 ";
        b = insertEle(a, y, yi);
        if (b)
        {
            if (a[yi] == y)
                cout << "1 ";
            else
                cout << "0 ";
        }
        else
            cout << "0 ";
        b = deleteEle(a, z);
        if (b)
        {
            if (!searchEle(a, z))
                cout << "1 \n";
            else
                cout << "0 \n";
        }
        else
            cout << "0 \n";
    }
} // } Driver Code Ends

/* Complete the function(s) below */

bool searchEle(int a[], int x)
{
    // add code here.
    for (int i = 0; i < 1000; i++)
    {
        if (a[i] == x)
        {
            return true;
        }
    }
    return false;
}
bool insertEle(int a[], int y, int yi)
{
    // add code here.
    if (yi < 1000)
    {
        a[yi] = y;
        return true;
    }
    return false;
}
bool deleteEle(int a[], int z)
{
    // add code here.
    if (a[z] != 0)
    {
        a[z] = 0;
        return true;
    }
    return false;
}