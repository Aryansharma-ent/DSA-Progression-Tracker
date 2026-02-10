// User function Template for C++

#include <bits/stdc++.h>
using namespace std;

/*
Problem: Topological Sort using Kahn’s Algorithm (BFS)

Intuition:
In a Directed Acyclic Graph (DAG), a node with indegree 0 has no dependencies
and can appear first in the topological order.
If we repeatedly remove such nodes and reduce the indegree of their neighbors,
we can generate a valid topological ordering.

Approach (Kahn's Algorithm - BFS):
1. Build the adjacency list from the given edge list.
2. Compute indegree of every vertex.
3. Push all vertices with indegree 0 into a queue.
4. While the queue is not empty:
   - Pop a node and add it to the answer.
   - For each of its neighbors:
       - Decrease indegree.
       - If indegree becomes 0, push it into the queue.
5. The order in which nodes are popped from the queue is the topological order.

Note:
- If the graph contains a cycle, not all nodes will be processed.
- In that case, the size of the result will be less than V.

Time Complexity:
O(V + E), where V is the number of vertices and E is the number of edges.

Space Complexity:
O(V + E) for adjacency list, indegree array, and queue.
*/

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // Build adjacency list
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        vector<int> Indegree(V, 0);

        // Calculate indegree of each node
        for(int u = 0; u < V; u++){
            for(int v : adj[u]){
                Indegree[v]++;
            }
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for(int i = 0; i < V; i++){
            if(Indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        // BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int it : adj[node]){
                Indegree[it]--;
                if(Indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return ans;
    }
};
