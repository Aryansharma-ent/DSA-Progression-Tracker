/*
Approach: Modified Dijkstra (Min Heap)

- This problem asks to minimize the maximum absolute difference between adjacent cells
  along a path from (0,0) to (m-1,n-1).

- Instead of the usual shortest path (sum of weights), here:
    Path cost = maximum edge difference along the path

- Use a priority queue (min-heap) where:
    {effort, {row, col}}

- Start from (0,0) with effort = 0

- For each neighbor:
    difference = abs(heights[nr][nc] - heights[r][c])
    newEffort = max(currentEffort, difference)

- If this new effort is smaller than previously recorded effort:
    update and push into the priority queue

- The first time we reach destination, we return the effort (Dijkstra property)

Time Complexity: O(m * n * log(m * n))
Space Complexity: O(m * n)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0; 

        pq.push({0,{0,0}});

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int effort = pq.top().first;
            pq.pop();

            // Early exit (Dijkstra guarantee)
            if(r == m-1 && c == n-1) return effort;

            // Optional optimization
            if(effort > dist[r][c]) continue;

            for(int i = 0; i < 4; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int difference = abs(heights[nr][nc] - heights[r][c]);
                    int newEffort = max(effort, difference);

                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }

        return 0;
    }
};