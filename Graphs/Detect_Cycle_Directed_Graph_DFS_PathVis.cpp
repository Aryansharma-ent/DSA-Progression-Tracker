// User function Template for C++

#include <bits/stdc++.h>
using namespace std;

/*
Problem: Detect Cycle in a Directed Graph

Intuition:
In a directed graph, a cycle exists if during DFS we reach a node that is
already in the current recursion path (back edge).
So we maintain:
- vis[node]      -> node has been visited at least once
- pathvis[node]  -> node is in the current DFS recursion stack/path

If we find an edge to a node with pathvis[node] == 1, we found a cycle.

Approach (DFS + Recursion Stack):
1. Build adjacency list from edge list (u -> v).
2. For each unvisited node, start DFS.
3. In DFS:
   - Mark node as visited and also in current path (pathvis = 1).
   - For every neighbor:
        a) If neighbor is unvisited -> DFS on neighbor
        b) Else if neighbor is in current path (pathvis == 1) -> cycle found
   - Before returning, remove node from current path (pathvis = 0).
4. If any DFS detects a cycle, return true.

Time Complexity:
O(V + E)  (each node and edge processed once)

Space Complexity:
O(V) for vis + pathvis + recursion stack
*/

class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathvis){
        vis[node] = 1;
        pathvis[node] = 1;

        for(int it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathvis)) return true;
            } else {
                if(pathvis[it] == 1) return true; // back edge => cycle
            }
        }

        pathvis[node] = 0; // remove from current path
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Build adjacency list for directed graph
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);

        // Handle disconnected components
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathvis)) return true;
            }
        }
        return false;
    }
};
