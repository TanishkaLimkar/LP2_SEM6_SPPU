#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

bool isSafe(vector<vector<int>> &board, int row, int col)
{
    int i = row;
    int j = col;

    while (j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        j--;
    }

    i = row;
    j = col;

    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }
    i = row;
    j = col;

    while (i < board.size() && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void solve(vector<vector<int>> &board, int col)
{
    if (col >= board.size())
    {
        cout << "--------------------FINAL ANSWER------------------------" << endl;
        print(board);

        cout << "--------------------FINAL ANSWER------------------------" << endl;
        return;
    }

    for (int row = 0; row < board.size(); row++)
    {
        if (isSafe(board, row, col))
        {
            cout << "QUEEN PLACED AT LOCATION (" << row << " , " << col << " )" << endl;
            board[row][col] = 1;
            print(board);
            solve(board, col + 1);
            board[row][col] = 0;
            cout << "----------------------BACKTRACKING--------------------------" << endl;
            print(board);
        }
    }
}
int main()
{
    cout << "Enter the value of N" << endl;
    int n;
    cin >> n;
    if (n == 0 || n == 1 || n == 2 || n == 3)
    {
        cout << "NO SOLUTION AVAILABLE !!" << endl;
        return 0;
    }
    int row = 0;
    int col = 0;
    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(board, col);

    return 0;
}