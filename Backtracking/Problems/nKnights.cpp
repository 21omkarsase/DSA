#include <bits/stdc++.h>
using namespace std;

void printKnights(vector<vector<bool>> board)
{
    for (auto v : board)
    {
        for (auto i : v)
        {
            if (i)
                cout << "K"
                     << " ";
            else
                cout << "x"
                     << " ";
        }
        cout << endl;
    }

    cout << endl;
}

bool isValid(vector<vector<bool>> &board, int row, int col, int n)
{
    if (row < n and row >= 0 and col < n and col >= 0)
        return true;
    return false;
}

bool isSafe(vector<vector<bool>> board, int row, int col, int n)
{
    if (isValid(board, row - 2, col - 1, n))
    {
        if (board[row - 2][col - 1])
            return false;
    }

    if (isValid(board, row - 1, col - 2, n))
    {
        if (board[row - 1][col - 2])
            return false;
    }

    if (isValid(board, row - 2, col + 1, n))
    {
        if (board[row - 2][col + 1])
            return false;
    }

    if (isValid(board, row - 1, col + 2, n))
    {
        if (board[row - 1][col + 2])
            return false;
    }

    return true;
}

void placeKnights(vector<vector<bool>> &board, int row, int col, int n, int target)
{
    if (target == 0)
    {
        printKnights(board);
        return;
    }

    if (col == n and row == n - 1)
    {
        return;
    }

    if (col == n)
    {
        placeKnights(board, row + 1, 0, n, target);
        return;
    }

    // int count = 0;
    if (isSafe(board, row, col, n))
    {
        board[row][col] = 1;
        placeKnights(board, row, col + 1, n, target - 1);
        board[row][col] = 0;
    }
    // else
    placeKnights(board, row, col + 1, n, target);
}

int main()
{
    int n;
    cout << "Enter the size of the maze : ";
    cin >> n;
    int target;
    cout << "Enter target size : ";
    cin >> target;
    vector<vector<bool>> board(n, vector<bool>(n));

    placeKnights(board, 0, 0, n, target);
    // cout << placeKnights(board, 0, 0, n, target) << endl;

    return 0;
}