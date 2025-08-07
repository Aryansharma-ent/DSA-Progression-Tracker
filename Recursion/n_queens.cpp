// HARD
/*
 DSA Tracker Problem: N-Queens (Leetcode 51)
 Approach: Backtracking (Standard Template)
 Time Complexity: O(N!) — Worst-case time complexity due to the N! permutations of queens
 Space Complexity: O(N^2) — For storing the board and the recursive stack
 Tags: Recursion, Backtracking

 Idea:
1. Place queens row by row starting from the top.
2. For each column in the current row, check if placing a queen is safe:
   - No other queen in the same column
   - No other queen in the same upper-left diagonal
   - No other queen in the same upper-right diagonal
3. If safe, place the queen and move to the next row.
4. If all queens are placed, store the board configuration.
5. Backtrack if no valid column exists in the current row.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n) {
        //  upper column
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') return false;
        }

        // upper left diagonal
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        //  upper right diagonal
        for (int i = row-1, j = col+1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int row, vector<string> &board, vector<vector<string>> &ans, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q'; // Place queen
                solve(row + 1, board, ans, n); // Recur
                board[row][col] = '.'; // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};
