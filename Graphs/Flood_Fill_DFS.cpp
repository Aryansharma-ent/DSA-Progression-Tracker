// ✅ Problem: Flood Fill (LeetCode 733)
// 📚 Approach: Depth First Search (DFS)
// 🧠 Intuition:
// The problem is similar to performing a DFS on a 2D grid.
// Starting from the source pixel (sr, sc), we recursively fill
// all adjacent cells (up, down, left, right) that have the same
// initial color with the new color. We ensure not to revisit
// already colored cells to avoid infinite recursion.
//
// 🕒 Time Complexity: O(N * M)
// Each cell is visited once at most in the DFS traversal.
//
// 💾 Space Complexity: O(N * M)
// Due to the recursion stack in the worst case (when the entire
// image is filled).
//
// 🧩 Bits Used: DFS, 2D Grid Traversal, Recursion
//
// 🧰 Namespace:
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Recursive DFS helper
    void dfs(int row, int col,
             vector<vector<int>> &ans,
             vector<vector<int>> &image,
             int newColor, int delRow[], int delCol[], int iniColor) {

        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        // Explore 4 directions (Up, Right, Down, Left)
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // Check boundary and same initial color condition
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        dfs(sr, sc, ans, image, color, delRow, delCol, iniColor);
        return ans;
    }
};
    