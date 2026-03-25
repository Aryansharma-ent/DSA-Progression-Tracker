/*
Approach: Breadth First Search (BFS) in 8 Directions

- The grid represents a binary matrix where:
    0 = open cell
    1 = blocked cell

- We need to find the shortest path from (0,0) to (m-1,n-1)
  moving in all 8 directions (including diagonals).

- Since all moves have equal weight (1 step),
  BFS guarantees the shortest path.

- Use a queue storing:
    {{row, col}, distance}

- Start from (0,0) with distance = 1

- For each cell:
    Explore all 8 directions using delRow and delCol arrays

- If a neighbor is:
    - within bounds
    - not visited
    - not blocked (grid[nr][nc] == 0)

  then push it into queue with distance + 1

- The first time we reach (m-1, n-1), return the distance

- If unreachable, return -1

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] != 0) return -1;

        vector<vector<int>> vis(m, vector<int>(n, -1));

        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        vis[0][0] = 0;

        int delRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delCol[] = {-1, 0, 1, -1, 1, -1, 0, 1}; 

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int distance = q.front().second;
            q.pop();

            // Early exit when destination is reached
            if(r == m-1 && c == n-1) return distance;

            for(int i = 0; i < 8; i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                   vis[nr][nc] == -1 && grid[nr][nc] == 0){
                    
                    vis[nr][nc] = distance + 1;
                    q.push({{nr,nc}, distance + 1});
                }
            }
        }

        return -1;
    }
};