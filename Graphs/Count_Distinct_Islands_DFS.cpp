// User function Template for C++

#include <bits/stdc++.h>
using namespace std;

/*
Problem: Count Distinct Islands

Intuition:
Two islands are considered the same if they have the same shape,
even if they appear at different positions in the grid.
So instead of storing absolute coordinates, we store each island's
shape using relative coordinates with respect to the starting cell.

Approach:
1. Traverse the entire grid.
2. When an unvisited land cell (1) is found:
   - Start DFS from that cell.
   - Treat this cell as the origin (sr, sc).
3. During DFS:
   - Mark the cell as visited.
   - Store the relative position (r - sr, c - sc) in a vector.
   - Explore all 4 directions (up, right, down, left).
4. After DFS completes for one island:
   - Insert the shape vector into a set.
5. The number of distinct islands equals the size of the set.

Why this works:
- Translation does not change relative positions.
- Same-shaped islands generate identical relative-coordinate vectors.
- Different shapes produce different vectors, which are stored uniquely in the set.

Time Complexity:
O(n * m), where n and m are grid dimensions (each cell visited once).

Space Complexity:
O(n * m) for visited array, recursion stack, and shape storage.
*/

class Solution {
public:
    void dfs(int r, int c, int sr, int sc,
             vector<vector<int>> &vis,
             vector<vector<int>> &grid,
             vector<pair<int,int>> &shape,
             int delrow[], int delcol[]) {

        vis[r][c] = 1;
        shape.push_back({r - sr, c - sc});

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < 4; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
               vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                dfs(nr, nc, sr, sc, vis, grid, shape, delrow, delcol);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> shapes;

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    vector<pair<int,int>> shape;
                    dfs(i, j, i, j, vis, grid, shape, delrow, delcol);
                    shapes.insert(shape);
                }
            }
        }
        return (int)shapes.size();
    }
};
