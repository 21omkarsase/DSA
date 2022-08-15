#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    if (n == -1)
        return;

    solve(n - 1);
    cout << n << endl;
    n++;
    cout << n << " o" << endl;
}

int main()
{
    // solve(6);
    string s = "omkar";
    cout << s.substr(0, 5) << endl;
    cout << s.substr(4);
    return 0;
}