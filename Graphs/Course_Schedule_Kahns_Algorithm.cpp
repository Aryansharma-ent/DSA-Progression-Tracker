// LeetCode 207: Course Schedule

#include <bits/stdc++.h>
using namespace std;

/*
Problem: Course Schedule

Intuition:
This problem asks whether it is possible to finish all courses given
a list of prerequisite relations.
This is equivalent to checking whether a directed graph contains a cycle.
If a cycle exists, we cannot complete all courses.

Approach (Kahn’s Algorithm - Topological Sort using BFS):
1. Treat each course as a node in a directed graph.
2. For each prerequisite [u, v], add a directed edge v -> u
   (v must be completed before u).
3. Compute the indegree of each node.
4. Push all nodes with indegree 0 into a queue (courses with no prerequisites).
5. Repeatedly:
   - Pop a node from the queue.
   - Increment count of completed courses.
   - Reduce indegree of its neighbors.
   - If any neighbor’s indegree becomes 0, push it into the queue.
6. If we are able to process all courses, return true.
   Otherwise, a cycle exists → return false.

Why this works:
- In a DAG, topological ordering exists and all nodes can be processed.
- In a cyclic graph, some nodes will never reach indegree 0.

Time Complexity:
O(V + E), where V = number of courses and E = number of prerequisites.

Space Complexity:
O(V + E) for adjacency list, indegree array, and queue.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // Build adjacency list: v -> u
        for(auto &e : prerequisites){
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }

        vector<int> indegree(numCourses, 0);

        // Compute indegrees
        for(int u = 0; u < numCourses; u++){
            for(int v : adj[u]){
                indegree[v]++;
            }
        }

        queue<int> q;

        // Push courses with no prerequisites
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;

        // BFS Topological Sort
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(int it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        // If all courses are processed, return true
        return cnt == numCourses;
    }
};
