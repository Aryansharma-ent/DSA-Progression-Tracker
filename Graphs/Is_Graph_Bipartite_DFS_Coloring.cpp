    #include <bits/stdc++.h>
using namespace std;

/*
LeetCode 785: Is Graph Bipartite?

Intuition:
A graph is bipartite if we can color its nodes using 2 colors such that
no two adjacent nodes have the same color.
This is equivalent to checking whether the graph contains an odd-length cycle.

Approach (DFS + 2-Coloring):
- Maintain an array `vis` where:
    vis[node] = 0  -> unvisited
    vis[node] = 1  -> color 1
    vis[node] = 2  -> color 2
- Run DFS from every unvisited node (important for disconnected graphs).
- During DFS:
    - Color the current node.
    - For each neighbor:
        1) If unvisited, assign opposite color and continue DFS.
        2) If already colored and has the same color as current node -> not bipartite.

Color Trick:
- Opposite color can be assigned using `3 - color`:
    if color = 1 -> 3-1 = 2
    if color = 2 -> 3-2 = 1

Time Complexity:
O(V + E) because each node and edge is processed once.

Space Complexity:
O(V) for visited/color array and recursion stack in worst case.
*/

class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, int color, vector<int> &vis) {
        vis[node] = color;

        for (int it : graph[node]) {
            if (!vis[it]) {
                if (!dfs(it, graph, 3 - color, vis)) return false;
            } else if (vis[it] == vis[node]) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!dfs(i, graph, 1, vis)) return false;
            }
        }
        return true;
    }
};
