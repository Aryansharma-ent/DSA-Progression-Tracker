/*
 * Problem: Shortest Path in a DAG (Directed Acyclic Graph)
 *
 * Approach: Topological Sort (DFS-based) + Edge Relaxation
 *
 * Key Insight:
 *   In a DAG, we can process nodes in topological order, which guarantees
 *   that when we process a node, all nodes that could feed into it have
 *   already been processed. This means dist[node] is finalized before
 *   we relax its outgoing edges — no future node can give it a shorter path.
 *
 * Algorithm:
 *   1. Build a weighted adjacency list from the edge list.
 *   2. Run DFS on all unvisited nodes, pushing each node onto a stack
 *      after all its descendants are processed (topological order).
 *   3. Initialize dist[] = INT_MAX for all nodes, dist[0] = 0.
 *   4. Pop nodes from the stack one by one (topological order).
 *      - Skip if dist[node] == INT_MAX (unreachable, avoid overflow).
 *      - For each neighbour, relax: dist[neighbour] = min(dist[neighbour],
 *        dist[node] + edge_weight).
 *   5. Unreachable nodes return -1.
 *
 * Why topological order guarantees correctness:
 *   In a DAG, every edge goes from an earlier node to a later node in
 *   topological order. So when we process node U, every node V that has
 *   an edge V->U has already been processed and has already relaxed into U.
 *   dist[U] is therefore fully finalized before we use it.
 *
 * Why this does NOT work on graphs with cycles:
 *   Topological sort requires a DAG. In a cyclic graph, a node could be
 *   processed before all its predecessors are settled, producing wrong distances.
 *   Use Dijkstra (non-negative weights) or Bellman-Ford (negative weights) instead.
 *
 * Why we skip dist[node] == INT_MAX:
 *   If a node is unreachable from source, dist[node] = INT_MAX.
 *   INT_MAX + any positive weight overflows to a negative number,
 *   silently corrupting distances. The continue guard prevents this.
 *
 * Time Complexity  : O(V + E)
 * Space Complexity : O(V + E)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int src, vector<int> &vis, vector<vector<pair<int,int>>> &adj, stack<int> &st) {
        vis[src] = 1;

        for(auto it : adj[src]){
            if(!vis[it.first]){
                dfs(it.first, vis, adj, st);
            }
        }
        st.push(src);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> vis(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }

        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(dist[node] == INT_MAX) continue;

            int distance = dist[node];
            for(auto it : adj[node]){
                int newnode     = it.first;
                int newdistance = it.second;
                dist[newnode] = min(dist[newnode], newdistance + distance);
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