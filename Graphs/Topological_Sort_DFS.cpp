// User function Template for C++

#include <bits/stdc++.h>
using namespace std;

/*
Problem: Topological Sort of a Directed Acyclic Graph (DAG)

Intuition:
In a directed graph, a node must appear before all the nodes it points to.
Using DFS, once we finish exploring all neighbors of a node, we can safely
place that node in the topological order.

So the idea is:
- Go as deep as possible using DFS.
- Push the node into a stack only AFTER all its outgoing edges are processed.

Approach (DFS + Stack):
1. Build the adjacency list from the given edge list.
2. Maintain a visited array to avoid revisiting nodes.
3. For every unvisited node, run DFS.
4. In DFS:
   - Mark the node as visited.
   - Recursively call DFS for all unvisited neighbors.
   - After visiting all neighbors, push the node into a stack.
5. After DFS finishes for all nodes:
   - Pop elements from the stack to get the topological order.

Why this works:
- DFS ensures dependencies are processed first.
- Stack reverses the finishing time order, giving a valid topological sort.
- Works only for Directed Acyclic Graphs (DAGs).

Time Complexity:
O(V + E), where V is number of vertices and E is number of edges.

Space Complexity:
O(V) for visited array, recursion stack, and stack used for ordering.
*/

class Solution {
public:
    void dfs(int node, vector<int> &vis,
             vector<vector<int>> &adj,
             stack<int> &st) {

        vis[node] = 1;

        for(int it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }

        // push after all neighbors are processed
        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // build adjacency list
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);
        stack<int> st;

        // handle disconnected components
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }

        // extract topological order
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
