/*
    --------------------------------------------------
    Problem Statement:
    Given an N x N grid (maze) filled with 0s and 1s, 
    where 1 represents an open cell and 0 represents a blocked cell,
    a rat starts at the top-left cell (0,0) and must reach the bottom-right cell (n-1,n-1).
    The rat can move in 4 possible directions: Down (D), Left (L), Right (R), and Up (U).
    Return all possible paths as strings of directions.

    --------------------------------------------------
    Approach:
    - Use Depth-First Search (DFS) with backtracking.
    - Keep track of visited cells using a `vis` matrix to avoid revisiting in the same path.
    - From the current cell, explore each of the 4 possible directions if:
        1. The new cell is within bounds.
        2. The new cell is open (value == 1).
        3. The new cell has not been visited in the current path.
    - When the bottom-right cell is reached, store the path string.
    - Backtrack after exploring each direction to allow other paths to use the current cell.

    --------------------------------------------------
    Time Complexity:
    - Worst Case: O(4^(n*n)) in an open maze (all 1s), as each cell has up to 4 moves.
      Practically reduced by visited checks.
    Space Complexity:
    - O(n*n) for visited matrix + recursion stack (in worst case path length).

    --------------------------------------------------
    Example:
    Input:
    4
    1 0 0 0
    1 1 0 1
    0 1 0 0
    1 1 1 1

    Output:
    DDRDRR DRDDRR

    --------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(int i, int j, vector<vector<int>> &a, int n,
               vector<string> &ans, string move, vector<vector<int>> &vis) {
        // Base case: reached destination
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        // Down
        if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
            vis[i][j] = 1;
            solve(i + 1, j, a, n, ans, move + 'D', vis);
            vis[i][j] = 0;
        }
        // Left
        if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
            vis[i][j] = 1;
            solve(i, j - 1, a, n, ans, move + 'L', vis);
            vis[i][j] = 0;
        }
        // Right
        if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
            vis[i][j] = 1;
            solve(i, j + 1, a, n, ans, move + 'R', vis);
            vis[i][j] = 0;
        }
        // Up
        if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
            vis[i][j] = 1;
            solve(i - 1, j, a, n, ans, move + 'U', vis);
            vis[i][j] = 0;
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (m[0][0] == 1)
            solve(0, 0, m, n, ans, "", vis);

        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];

    Solution obj;
    vector<st
