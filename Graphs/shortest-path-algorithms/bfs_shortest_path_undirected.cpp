/*
 * Problem: Shortest Path in Undirected Graph (Unit Weights)
 *
 * Approach: BFS (Breadth First Search)
 *
 * Key Insight:
 *   In an unweighted graph, BFS explores nodes in waves — all nodes at
 *   distance 1 first, then distance 2, and so on. This guarantees that
 *   the first time a node is discovered, it is via the shortest path.
 *
 * Algorithm:
 *   1. Build an adjacency list from the edge list.
 *   2. Initialize dist[] = INT_MAX for all nodes, dist[src] = 0.
 *   3. Push src into the queue.
 *   4. For each node popped, iterate over its neighbours.
 *      - If a neighbour hasn't been visited (dist == INT_MAX),
 *        set dist[neighbour] = dist[node] + 1 and push it.
 *   5. The dist[] array is the answer. Unreachable nodes return -1.
 *
 * Why dist is set at PUSH time (not pop time):
 *   Setting dist at push time ensures a node enters the queue exactly once,
 *   preventing duplicate entries and redundant processing.
 *
 * Why this is correct (Proof sketch):
 *   The queue always holds nodes in non-decreasing distance order.
 *   So the first time a node is discovered, it is by the closest
 *   possible wave. The dist == INT_MAX guard acts as a lock —
 *   once written, no later (longer) path can overwrite it.
 *
 * Time Complexity  : O(V + E)
 * Space Complexity : O(V + E)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V);

        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int,int>> q;
        q.push({src, 0});
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            int node = q.front().first;
            int dis  = q.front().second;
            q.pop();

            for(int it : adj[node]){
                if(dist[it] == INT_MAX){
                    dist[it] = dis + 1;
                    q.push({it, dis + 1});
                }
            }
        }

        vector<int> ans(V, -1);
        for(int i = 0; i < V; i++){
            if(dist[i] != INT_MAX){
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};