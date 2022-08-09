// counting no of ways by which we can reach to end of the matrix of sudoku
// either take right of down
#include <bits/stdc++.h>
using namespace std;

int countTheWays(int d, int r, int n)
{
    if (d == n or r == n)
        return 1;
    if (r > n or d > n)
        return 0;

    int down = countTheWays(d + 1, r, n);
    int right = countTheWays(d, r + 1, n);

    return down + right;
}

int main()
{
    int n;
    cout << "Enter the size of the matrix : ";
    cin >> n;

    cout << countTheWays(1, 1, n);
    return 0;
}