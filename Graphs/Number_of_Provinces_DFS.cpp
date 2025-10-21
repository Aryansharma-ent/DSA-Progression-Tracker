// ✅ Problem: Number of Provinces (LeetCode 547)
// 🔹 Approach: Depth First Search (DFS)
// 🔹 Concept: Count connected components in an undirected graph.
// Each province represents one connected component in the adjacency graph.
// 🔹 Input: adjacency matrix (isConnected)
// 🔹 Output: number of connected components (provinces)

// 🔹 Time Complexity: O(n²)
//    - Because we traverse all cells in the adjacency matrix once.
// 🔹 Space Complexity: O(n)
//    - For the visited array and recursion stack.

// 🔹 Approach Steps:
// 1. Convert the adjacency matrix into an adjacency list.
// 2. Perform DFS on every unvisited node.
// 3. Increment the province counter for each new DFS call.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive DFS to mark connected nodes
    void Recur(vector<int> &vis, int node, vector<vector<int>> &adj) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                Recur(vis, it, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        // Build adjacency list from matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        // Count connected components (provinces)
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                Recur(vis, i, adj);
            }
        }

        return cnt;
    }
};

