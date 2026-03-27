/*
Approach: Modified Dijkstra with Stop Constraint

- We are given flights as edges with cost, and we need to find the cheapest price
  from src to dst with at most k stops.

- Build adjacency list:
    adj[u] = {v, cost}

- Use a priority queue (min-heap) storing:
    {stops, cost, node}

- Start from src:
    stops = 0, cost = 0

- For each node:
    - If stops > k → skip
    - Explore neighbors

- For each neighbor:
    newCost = currentCost + edgeCost

- If newCost is smaller than previously recorded cost:
    update and push into pq with stops + 1

- This is similar to Dijkstra but with an added constraint on stops.

- NOTE:
    We prioritize cost, but also track stops to ensure we don’t exceed k.

Time Complexity: O(E log V)
Space Complexity: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e : flights)
            adj[e[0]].push_back({e[1], e[2]});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // {stops, cost, node}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<>
        > pq;

        pq.push({0, 0, src});

        while (!pq.empty()) {
            tuple<int, int, int> current = pq.top();
            pq.pop();

            int stops = get<0>(current);
            int cost = get<1>(current);
            int node = get<2>(current);

            if (stops > k) continue;

            for (auto& edge : adj[node]) {
                int newnode = edge.first;
                int newdistance = edge.second;
                int newCost = cost + newdistance;

                if (newCost < dist[newnode]) {
                    dist[newnode] = newCost;
                    pq.push({stops + 1, newCost, newnode});
                }
            }
        }

        return (dist[dst] == INT_MAX ? -1 : dist[dst]);
    }
};