// counting no of ways by which we can reach to end of the matrix of sudoku
// either take right , down or diagonal
#include <bits/stdc++.h>
using namespace std;

void printMatrixPath(int d, int r, int n, string sol, vector<string> &solutions)
{

    if (d == n and r == n)
    {
        solutions.push_back(sol);
        return;
    }

    if (d <= n - 1 and r <= n - 1)
    {
        printMatrixPath(d + 1, r + 1, n, sol + "D", solutions);
    }

    if (d < n)
    {
        printMatrixPath(d + 1, r, n, sol + "V", solutions);
    }
    if (r < n)
    {

        printMatrixPath(d, r + 1, n, sol + "H", solutions);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the matrix : ";
    cin >> n;
    vector<string> solutions;

    printMatrixPath(1, 1, n, "", solutions);

    for (auto i : solutions)
        cout << i << endl;
    cout << endl;
    return 0;
}