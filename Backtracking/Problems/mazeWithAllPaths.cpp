// counting no of ways by which we can reach to end of the matrix of sudoku
// either take right of down
#include <bits/stdc++.h>
using namespace std;

void printMatrixPath(int c, int r, int n, string sol, vector<string> &solutions, vector<vector<bool>> arr)
{

    if (c == n - 1 and r == n - 1)
    {
        solutions.push_back(sol);
        return;
    }

    if (!arr[r][c])
    {
        return;
    }

    arr[r][c] = 0;

    if (r < n - 1)
    {
        printMatrixPath(c, r + 1, n, sol + "d", solutions, arr);
    }
    if (c < n - 1)
    {
        printMatrixPath(c + 1, r, n, sol + "r", solutions, arr);
    }
    if (r > 0)
    {
        printMatrixPath(c, r - 1, n, sol + "u", solutions, arr);
    }
    if (c > 0)
    {
        printMatrixPath(c - 1, r, n, sol + "l", solutions, arr);
    }

    arr[r][c] = 1;
}

int main()
{
    int n;
    cout << "Enter the size of the maze : ";
    cin >> n;
    vector<string> solutions;

    vector<vector<bool>> arr;
    for (int i = 0; i < n; i++)
    {
        vector<bool> temp;
        for (int j = 0; j < n; j++)
        {
            bool t;
            cin >> t;
            temp.push_back(t);
        }
        arr.push_back(temp);
    }

    printMatrixPath(0, 0, n, "", solutions, arr);

    for (auto i : solutions)
        cout << i << endl;
    cout << endl;
    return 0;
}