// ✅ Problem: Detect Cycle in an Undirected Graph (DFS Approach)
// 📚 Approach: Depth First Search (DFS)
// 🧠 Intuition:
// We use DFS traversal and check if a visited node is encountered again
// which is not the parent of the current node — this indicates a cycle.
//
// 🕒 Time Complexity: O(V + E)
// 💾 Space Complexity: O(V)
//
// 🧰 Namespace:
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, node, vis, adj))
                    return true;
            } 
            else if (it != parent) {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list from edge list
        vector<vector<int>> adj(V);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }
};
// ✅ Problem: Detect Cycle in an Undirected Graph (DFS Approach)
// 📚 Approach: Depth First Search (DFS)
// 🧠 Intuition:
// We use DFS traversal and check if a visited node is encountered again
// which is not the parent of the current node — this indicates a cycle.
//
// 🕒 Time Complexity: O(V + E)
// 💾 Space Complexity: O(V)
//
// 🧰 Namespace:
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, node, vis, adj))
                    return true;
            } 
            else if (it != parent) {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list from edge list
        vector<vector<int>> adj(V);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }
};
