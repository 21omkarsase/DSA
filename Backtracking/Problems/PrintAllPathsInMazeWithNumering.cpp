// counting no of ways by which we can reach to end of the matrix of sudoku
// either take right of down
#include <bits/stdc++.h>
using namespace std;

void printMatrixPath(int c, int r, int n, int step, string sol, vector<vector<bool>> arr, vector<vector<int>> path)
{

    if (c == n - 1 and r == n - 1)
    {
        cout << sol << endl;
        path[r][c] = step;
        for (auto v : path)
        {
            for (auto i : v)
                cout << i << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }

    if (!arr[r][c])
    {
        return;
    }

    path[r][c] = step;
    arr[r][c] = 0;

    if (r < n - 1)
    {
        printMatrixPath(c, r + 1, n, step + 1, sol + "d", arr, path);
    }
    if (c < n - 1)
    {
        printMatrixPath(c + 1, r, n, step + 1, sol + "r", arr, path);
    }
    if (r > 0)
    {
        printMatrixPath(c, r - 1, n, step + 1, sol + "u", arr, path);
    }
    if (c > 0)
    {
        printMatrixPath(c - 1, r, n, step + 1, sol + "l", arr, path);
    }

    arr[r][c] = 1;
    path[r][c] = 0;
}

int main()
{
    int n;
    cout << "Enter the size of the maze : ";
    cin >> n;

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

    vector<vector<int>> path(n, (vector<int>(n)));

    printMatrixPath(0, 0, n, 1, "", arr, path);

    return 0;
}