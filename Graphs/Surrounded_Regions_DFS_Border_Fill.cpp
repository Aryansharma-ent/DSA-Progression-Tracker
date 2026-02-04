#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 130: Surrounded Regions

Problem:
You are given an m x n board containing 'X' and 'O'.
Capture all regions surrounded by 'X' by flipping surrounded 'O' to 'X'.
Any 'O' connected to the border cannot be captured.

Approach (DFS from Boundary):
- Any 'O' connected to the boundary is NOT surrounded.
- Start DFS from all boundary cells that contain 'O'.
- Mark all such reachable 'O' cells as safe using a temporary marker 'S'.
- After DFS:
    - Remaining 'O' cells are surrounded → flip them to 'X'
    - Restore 'S' back to 'O'

Why this works:
- Surrounding is defined only for regions NOT touching the boundary.
- DFS ensures we mark all boundary-connected regions efficiently.

Time Complexity:  O(m * n)
Space Complexity: O(m * n)  (visited matrix + recursion stack)
*/

class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &vis,
             vector<vector<char>> &board,
             int delrow[], int delcol[]) {

        vis[r][c] = 1;
        board[r][c] = 'S';   // mark as safe

        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < 4; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
               vis[nr][nc] == 0 && board[nr][nc] == 'O') {
                dfs(nr, nc, vis, board, delrow, delcol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        // 1) DFS from all boundary 'O's
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || j == 0 || i == m-1 || j == n-1)
                   && board[i][j] == 'O') {
                    dfs(i, j, vis, board, delrow, delcol);
                }
            }
        }

        // 2) Flip surrounded regions and restore safe cells
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
};
