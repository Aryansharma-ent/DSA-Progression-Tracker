#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 200: Number of Islands

Problem:
Given an m x n 2D grid of '1's (land) and '0's (water), count the number of islands.
An island is formed by connecting adjacent lands horizontally or vertically.

Approach (DFS Flood Fill):
- Traverse every cell in the grid.
- When you find an unvisited land cell ('1'):
    1) Increment island count.
    2) Run DFS to mark all connected land cells as visited.
- Each DFS call "flood-fills" one complete island.

Why it works:
- DFS explores the entire connected component (island) starting from a land cell.
- Once visited, those cells won't be counted again.

Time Complexity:  O(m * n)  (each cell visited at most once)
Space Complexity: O(m * n) in worst case due to recursion stack / visited matrix
*/

class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &grid,
             int delrow[], int delcol[]) {

        vis[r][c] = 1;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < 4; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
               vis[nr][nc] == 0 && grid[nr][nc] == '1') {
                dfs(nr, nc, vis, grid, delrow, delcol);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    cnt++;
                    dfs(i, j, vis, grid, delrow, delcol);
                }
            }
        }
        return cnt;
    }
};
