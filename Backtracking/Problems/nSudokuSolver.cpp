#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> board)
{
    for (auto v : board)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << endl;
}

bool isSafe(vector<vector<int>> &board, int row, int col, int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == num)
            return false;
    }

    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == num)
            return false;
    }
    int divider = sqrt(n);
    int rowStart = row - (row % divider);
    int colStart = col - (col % divider);

    for (int i = rowStart; i < rowStart + divider; i++)
    {
        for (int j = colStart; j < colStart + divider; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board, int n)
{
    int row = -1, col = -1;

    bool emptyLeft = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                row = i, col = j;
                emptyLeft = false;
                break;
            }
            if (!emptyLeft)
                break;
        }
    }

    if (emptyLeft)
        return true; // sudoku already solved

    for (int number = 1; number <= 9; number++)
    {
        if (isSafe(board, row, col, n, number))
        {
            board[row][col] = number;
            if (solve(board, n))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> board = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (solve(board, 9))
        display(board);
    else
        cout << "Can't solve sudoku" << endl;

    return 0;
}