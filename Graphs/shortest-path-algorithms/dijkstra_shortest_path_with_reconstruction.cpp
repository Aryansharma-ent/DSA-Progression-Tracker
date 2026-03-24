/*
 * Problem: Shortest Path in Weighted Undirected Graph (with path reconstruction)
 *
 * Approach: Dijkstra's Algorithm + Parent Tracking
 *
 * Key Insight:
 *   BFS works for unweighted graphs because all edges cost 1.
 *   When edges have different weights, a node farther away in hops
 *   might still be closer in total distance. Dijkstra fixes this by
 *   always processing the globally cheapest unprocessed node first,
 *   using a min-heap (priority queue).
 *
 * Algorithm:
 *   1. Build a weighted adjacency list.
 *   2. Initialize dist[] = INT_MAX, dist[1] = 0, parent[1] = 1.
 *   3. Push {0, src} into a min-heap (sorted by distance).
 *   4. Pop the node with the smallest distance.
 *      - If the popped distance > dist[node], it's a stale entry — skip it.
 *      - Otherwise relax all neighbours:
 *        if (dist[node] + edge_weight < dist[neighbour]):
 *            update dist[neighbour], update parent, push to heap.
 *   5. If dist[n] == INT_MAX, destination is unreachable — return {-1}.
 *   6. Reconstruct path by walking parent[] from destination back to source.
 *      Prepend dist[n] as the first element of the answer.
 *
 * Why the stale entry check (distance > dist[node]):
 *   When we update a node's distance, we push a NEW entry into the heap
 *   but the OLD entry is still sitting there. When the old (larger) entry
 *   is eventually popped, we skip it — the node was already finalized
 *   with a better distance.
 *
 * Why Dijkstra fails on negative weights:
 *   The algorithm assumes that once a node is popped from the heap,
 *   its distance is finalized. Negative edges can invalidate this —
 *   a later path could still be shorter. Use Bellman-Ford for negative weights.
 *
 * Path Reconstruction:
 *   parent[i] stores which node gave node i its shortest distance.
 *   Walk from destination → source via parent[], then reverse.
 *   parent[src] = src acts as the termination condition.
 *
 * Time Complexity  : O((V + E) log V)
 * Space Complexity : O(V + E)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1, 0);

        dist[1]   = 0;
        parent[1] = 1;
        pq.push({0, 1});

        while(!pq.empty()){
            int node     = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            if(distance > dist[node]) continue;

            for(auto it : adj[node]){
                int newdistance = it.second;
                if(newdistance + distance < dist[it.first]){
                    dist[it.first] = newdistance + distance;
                    parent[it.first] = node;
                    pq.push({newdistance + distance, it.first});
                }
            }
        }

        if(dist[n] == INT_MAX) return {-1};

        vector<int> ans;
        ans.push_back(dist[n]);

        int node = n;
        while(parent[node] != node){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(node);

        reverse(ans.begin() + 1, ans.end());
        return ans;
    }
};