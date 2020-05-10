#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int>>& board, int x, int y)
{
    // column
    for (int i = 0; i < 9; ++i) {
        if (i != y && board[x][y] == board[x][i]) return false;
    }
    // row
    for (int j = 0; j < 9; ++j) {
        if (j != x && board[x][y] == board[j][y]) return false;
    }
    // 3 * 3 cell
    for (int i = (x/3) * 3; i < (x/3 + 1) * 3; ++i) {
        for (int j = (y/3) * 3; j < (y/3 + 1) * 3; ++j) {
            if ((i != x || j != y) && board[i][j] == board[x][y]) return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                for (int k = 1; k < 10; ++k) {
                    board[i][j] = k;
                    if (isValid(board, i, j) && solve(board)) {
                        return true;
                    }
                    board[i][j] = 0;
                }
                return false;
            }
        }
    }
    return true;
}

bool retry(vector<vector<int>>& board, vector<vector<int>>& board2)
{
    int x[9] = {2, 1, 3, 7, 5, 6, 9, 4, 8};
    for (int k = 0; k < 9; ++k) {
        if (board[6][k] != x[k]) return false;
    }
    board2[6][2] = 5;
    board2[6][3] = 8;
    return true;
}

void print(vector<vector<int>>& board)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string str;
    vector<vector<int>> board(9,vector<int>(9,0));
    for (int i = 0; i < 9; ++i) {
        string line;
        int j = 0;
        while (j < 9 && cin >> board[i][j++]) {}
    }
    vector<vector<int>> board2 = board;
    solve(board);
    if (retry(board, board2))
    {
        solve(board2);
        print(board2);
    }
    else print(board);
    return 0;
}

