#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<bool>> board)
{
    for (auto v : board)
    {
        for (auto i : v)
        {
            if (i)
                cout << "Q"
                     << " ";
            else
                cout << "x"
                     << " ";
        }
        cout << endl;
    }

    cout << endl;
}

bool isSafe(vector<vector<bool>> board, int row, int col, int n)
{
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col])
            return false;
    }

    int maxLeft = min(row, col), maxRight = min(row, n - col - 1);

    for (int i = 1; i <= maxLeft; i++)
    {
        if (board[row - i][col - i])
            return false;
    }

    for (int i = 1; i <= maxRight; i++)
    {
        if (board[row - i][col + i])
            return false;
    }

    return true;
}

int placeQueens(vector<vector<bool>> &board, int n, int row)
{
    if (row == n)
    {
        display(board);
        return 1;
    }

    int count = 0;
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1;
            count += placeQueens(board, n, row + 1);
            board[row][col] = 0;
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n));

    int totalPossibleWays = placeQueens(board, n, 0);

    cout << totalPossibleWays << endl;

    return 0;
}