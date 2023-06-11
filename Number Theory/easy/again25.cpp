// A. Again Twenty Five!
// time limit per test0.5 seconds
// memory limit per test64 megabytes
// inputstandard input
// outputstandard output
// The HR manager was disappointed again. The last applicant failed the interview the same way as 24 previous ones. "Do I give such a hard task?" — the HR manager thought. "Just raise number 5 to the power of n and get last two digits of the number. Yes, of course, n can be rather big, and one cannot find the power using a calculator, but we need people who are able to think, not just follow the instructions."

// Could you pass the interview in the machine vision company in IT City?

// Input
// The only line of the input contains a single integer n (2 ≤ n ≤ 2·1018) — the power in which you need to raise number 5.

// Output
// Output the last two digits of 5n without spaces between them.

// Examples
// inputCopy
// 2
// outputCopy
// 25

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // long long n;
    // cin >> n;
    // long long base = 5, ans = 1;
    // while (n)
    // {
    //     if (!(n & 1))
    //     {
    //         n /= 2;
    //         base *= base;
    //     }
    //     else
    //     {
    //         n--;
    //         ans = ans * base;
    //     }
    // }
    // long long res = 0;
    // res = ans % 10;
    // ans /= 10;
    // res = res + (ans % 10) * 10;

    // cout << res << endl;

    // we dont't need to use binary exponentiation

    // last 2 digits of any power of 5 -- > always will be 2 and 5

    // therefor just print 25

    cout << 25 << endl;
}