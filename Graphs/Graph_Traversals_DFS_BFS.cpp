/*
    🔹 File: Graph_Traversals_DFS_BFS.cpp
    🔹 Author: Aryan
    🔹 Topic: Graph Traversal Algorithms — DFS & BFS
    🔹 Language: C++

    ---------------------------------------------------
    🧠 APPROACH:
    ---------------------------------------------------
    1. **DFS (Depth First Search)**:
       - A recursive traversal technique that explores as far as possible along
         each branch before backtracking.
       - Uses recursion (or a stack in iterative versions).
       - We mark each node as visited when we process it.
       - Suitable for pathfinding, connectivity, and cycle detection in graphs.

       ⚙️ Steps:
         - Start from a node (usually 0).
         - Mark it visited and store it in result.
         - Recursively call DFS for all unvisited adjacent nodes.

       ⏱️ Time Complexity: O(V + E)
       💾 Space Complexity: O(V) (for recursion + visited array)

    ---------------------------------------------------
    2. **BFS (Breadth First Search)**:
       - A level-order traversal technique using a queue.
       - Explores all neighbors at the present depth before moving to the next.
       - Useful for finding the shortest path in unweighted graphs.

       ⚙️ Steps:
         - Push the starting node into a queue.
         - Mark it visited.
         - While queue is not empty:
             - Pop front node, add to result.
             - Push all unvisited adjacent nodes into queue.

       ⏱️ Time Complexity: O(V + E)
       💾 Space Complexity: O(V) (for queue + visited array)

    ---------------------------------------------------
    📘 NOTES:
    ---------------------------------------------------
    - This implementation handles disconnected graphs in DFS.
    - Both traversals assume 0-based indexing of graph nodes.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dfs; // For storing DFS traversal order

    // 🔸 DFS helper function
    void Recur(int node, vector<int> adj[], int vis[]) {
        vis[node] = 1;
        dfs.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                Recur(it, adj, vis);
            }
        }
    }

    // 🔹 DFS traversal
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        dfs.clear();

        // Handles disconnected graphs
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                Recur(i, adj, vis);
            }
        }
        return dfs;
    }

    // 🔹 BFS traversal
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

// 🧩 Example Usage:
// int main() {
//     int V = 5;
//     vector<int> adj[V];
//     adj[0] = {1, 2};
//     adj[1] = {0, 3};
//     adj[2] = {0, 4};
//     adj[3] = {1};
//     adj[4] = {2};
//
//     Solution obj;
//     vector<int> dfsRes = obj.dfsOfGraph(V, adj);
//     vector<int> bfsRes = obj.bfsOfGraph(V, adj);
//
//     cout << "DFS: ";
//     for (int x : dfsRes) cout << x << " ";
//     cout << "\nBFS: ";
//     for (int x : bfsRes) cout << x << " ";
// }
