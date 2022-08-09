// counting no of ways by which we can reach to end of the matrix of sudoku
// either take right of down
#include <bits/stdc++.h>
using namespace std;

void printMatrixPath(int d, int r, int n, string sol, vector<string> &solutions)
{

    if (d == n and r == n)
    {
        solutions.push_back(sol);
        return;
    }

    if (d < n)
    {
        // sol += "d";
        printMatrixPath(d + 1, r, n, sol + "d", solutions);
        // sol.erase(sol.end() - 1);
    }
    if (r < n)

    {

        // sol += "r";
        printMatrixPath(d, r + 1, n, sol + "r", solutions);
        // sol.erase(sol.end() - 1);
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