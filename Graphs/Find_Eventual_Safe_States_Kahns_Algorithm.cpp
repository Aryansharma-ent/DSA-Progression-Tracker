// LeetCode 802: Find Eventual Safe States

#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find Eventual Safe States

Intuition:
A node is called "safe" if every possible path starting from it
eventually leads to a terminal node (a node with no outgoing edges).
In other words, safe nodes are those that are NOT part of any cycle
and do not lead to a cycle.

Instead of directly finding cycles, we reverse the graph and apply
Kahn’s Algorithm (topological sort idea).

Approach (Reverse Graph + Kahn’s Algorithm):
1. Reverse all edges of the graph.
2. Compute indegree for each node in the original graph
   (indegree here represents outgoing edges in the original graph).
3. Push all nodes with indegree 0 into a queue.
   These are terminal nodes and are always safe.
4. Perform BFS:
   - Pop a node and mark it as safe.
   - For each neighbor in the reversed graph:
       - Reduce its indegree.
       - If indegree becomes 0, push it into the queue.
5. All nodes processed by BFS are safe nodes.
6. Sort the result as required.

Why this works:
- Nodes in cycles will never reach indegree 0.
- Nodes leading to cycles will also never reach indegree 0.
- Only nodes that eventually lead to terminal nodes are collected.

Time Complexity:
O(V + E), where V = number of nodes and E = number of edges.

Space Complexity:
O(V + E) for adjacency list, indegree array, queue, and result storage.
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);   // reversed graph
        vector<int> Indeg(n, 0);
        queue<int> q;
        vector<int> safe;

        // Build reversed graph and indegree array
        for(int u = 0; u < n; u++){
            for(int v : graph[u]){
                adj[v].push_back(u);
                Indeg[u]++;
            }
        }

        // Push terminal nodes (indegree 0)
        for(int i = 0; i < n; i++){
            if(Indeg[i] == 0){
                q.push(i);
            }
        }

        // BFS (Kahn's Algorithm)
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for(int it : adj[node]){
                Indeg[it]--;
                if(Indeg[it] == 0){
                    q.push(it);
                }
            }
        }

        // Required sorted output
        sort(safe.begin(), safe.end());
        return safe;
    }
};
