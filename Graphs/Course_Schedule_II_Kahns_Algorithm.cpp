// LeetCode 210: Course Schedule II

#include <bits/stdc++.h>
using namespace std;

/*
Problem: Course Schedule II

Intuition:
This problem is an extension of Course Schedule I.
Instead of just checking if all courses can be completed,
we must also return a valid order in which the courses can be taken.

This can be solved using Topological Sorting.
If a topological order exists for the directed graph of courses,
then all courses can be completed in that order.
If a cycle exists, no valid ordering is possible.

Approach (Kahn’s Algorithm - BFS Topological Sort):
1. Represent each course as a node in a directed graph.
2. For each prerequisite [u, v], add an edge v -> u
   (course v must be completed before course u).
3. Compute indegree for every node.
4. Push all nodes with indegree 0 into a queue.
5. While the queue is not empty:
   - Pop a node and add it to the result order.
   - Reduce indegree of all its neighbors.
   - If any neighbor’s indegree becomes 0, push it into the queue.
6. If the number of processed nodes equals numCourses,
   return the computed order.
   Otherwise, a cycle exists → return an empty vector.

Why this works:
- Kahn’s algorithm guarantees a valid topological order for DAGs.
- If a cycle exists, some nodes will never reach indegree 0.

Time Complexity:
O(V + E), where V = number of courses and E = number of prerequisites.

Space Complexity:
O(V + E) for adjacency list, indegree array, queue, and result vector.
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // Build adjacency list (v -> u)
        for(auto &e : prerequisites){
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }

        vector<int> indeg(numCourses, 0);

        // Calculate indegrees
        for(int u = 0; u < numCourses; u++){
            for(int v : adj[u]){
                indeg[v]++;
            }
        }

        queue<int> q;

        // Push all courses with no prerequisites
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        int cnt = 0;

        // BFS Topological Sort
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            cnt++;

            for(int it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }

        // If all courses are processed, return order
        return (cnt == numCourses) ? ans : vector<int>();
    }
};
