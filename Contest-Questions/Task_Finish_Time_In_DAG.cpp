/*
========================================
Problem: Task Finish Time in DAG
Platform: Custom / Interview Problem
Approach: DFS on Directed Acyclic Graph

Author: Aryan
Date: 2026

----------------------------------------
Problem Statement:

Given:

- n tasks numbered from 0 to n - 1
- edges representing dependencies
- baseTime[i] representing the
  execution time of task i

For every task:

ownTime =
(maxChildTime - minChildTime)
+ baseTime[i]

finishTime =
ownTime + maxChildTime

Find the finish time of the
root task (task 0).

Assumption:

The graph is a DAG.

========================================
*/

/*
========================================
Approach: DFS

Observation:

The finish time of a node depends
on the finish times of all its
children.

Therefore:

1. Recursively compute the finish
   time for every child.

2. Track:

   - maximum child finish time
   - minimum child finish time

3. Compute:

   ownTime =
   (maxChildTime - minChildTime)
   + baseTime[node]

4. Return:

   finishTime =
   ownTime + maxChildTime

Leaf Node:

finishTime = baseTime[node]

----------------------------------------
Time Complexity: O(V + E)

Each node and edge is visited once.

Space Complexity: O(V)

Recursion stack + adjacency list.

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long solve(int node,
                    vector<vector<int>>& adj,
                    vector<int>& baseTime) {

        if(adj[node].empty())
            return baseTime[node];

        long long maxi = 0;
        long long mini = LLONG_MAX;

        for(auto child : adj[node]) {

            long long curr =
                solve(child, adj, baseTime);

            maxi = max(maxi, curr);
            mini = min(mini, curr);
        }

        long long ownTime =
            (maxi - mini) + baseTime[node];

        long long finishTime =
            ownTime + maxi;

        return finishTime;
    }

    long long finishTime(int n,
                         vector<vector<int>>& edges,
                         vector<int>& baseTime) {

        vector<vector<int>> adj(n);

        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        return solve(0, adj, baseTime);
    }
};