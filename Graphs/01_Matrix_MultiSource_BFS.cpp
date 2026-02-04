#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 542: 01 Matrix

Problem:
Given an m x n binary matrix mat, return a matrix where each cell contains the
distance to the nearest 0 (distance = number of moves in 4 directions).

Approach (Multi-Source BFS):
- Treat every cell with value 0 as a BFS source (distance = 0).
- Push all 0-cells into the queue initially.
- Run BFS level-by-level; when we first reach a cell, that is the shortest distance
  to any 0 (because BFS expands in increasing distance order).
- Use a visited matrix to ensure each cell is processed once.

Why Multi-Source BFS works:
- Instead of running BFS/DFS from each 1 (costly), we run ONE BFS from ALL zeros together.
- The first time a cell is visited, we have found its minimum distance to a zero.

Time Complexity:  O(m * n)
Space Complexity: O(m * n)  (queue + visited + answer matrix)
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<pair<int,int>,int>> q;               // ((row,col), distance)
        vector<vector<int>> vis(m, vector<int>(n, 0));  // visited matrix
        vector<vector<int>> newmat(m, vector<int>(n, 0)); // answer matrix

        // 1) Push all 0-cells as starting points (multi-source)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                    // newmat[i][j] is already 0 by default
                }
            }
        }

        // 4-direction movement arrays
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        // 2) BFS expansion
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                // If inside bounds and not visited and it's a 1-cell, assign distance
                if(nr >= 0 && nr < m && nc >= 0 && nc < n
                   && vis[nr][nc] == 0 && mat[nr][nc] == 1) {

                    newmat[nr][nc] = d + 1;            // child dist = parent dist + 1
                    q.push({{nr, nc}, d + 1});
                    vis[nr][nc] = 1;
                }
            }
        }

        return newmat;
    }
};
