// ✅ Problem: Rotting Oranges (LeetCode 994)
// 🔹 Approach: Multi-Source Breadth First Search (BFS)
// 🔹 Concept: Use BFS to simulate the spread of rot in a grid where each rotten orange affects its neighbors.
// 🔹 Input: 2D grid of integers (0 = empty, 1 = fresh orange, 2 = rotten orange)
// 🔹 Output: Minimum time required for all oranges to rot, or -1 if impossible.

// 🔹 Time Complexity: O(N × M)
//    - Each cell is processed at most once.
// 🔹 Space Complexity: O(N × M)
//    - For the queue and visited matrix.

// 🔹 Approach Steps:
// 1. Push all initially rotten oranges (value = 2) into a queue with time = 0.
// 2. Perform BFS in 4 directions from each rotten orange to spread rot to adjacent fresh oranges.
// 3. Track time taken to rot all oranges.
// 4. If the number of fresh oranges that got rotten != total fresh oranges, return -1 (some remained unreachable).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>, int>> q; // {{row, col}, time}
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cntFresh = 0;

        // Step 1: Initialize queue with all rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                if (grid[i][j] == 1) cntFresh++;
            }
        }

        int time = 0;
        int cnt = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // Step 2: BFS traversal
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            // Step 3: Spread rot to adjacent fresh oranges
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        // Step 4: Check if all fresh oranges got rotten
        if (cnt != cntFresh) return -1;
        return time;
    }
};


