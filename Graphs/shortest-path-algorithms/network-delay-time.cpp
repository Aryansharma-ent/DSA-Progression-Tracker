/*
Approach: Dijkstra (Shortest Path in Weighted Graph)

- Each edge has a travel time → weighted graph
- Goal: find time for signal to reach all nodes

- Build adjacency list:
    adj[u] = {v, weight}

- Use min-heap:
    {distance, node}

- Start from source k

- Relax edges using Dijkstra

- Final answer:
    max distance among all nodes

- If any node unreachable → return -1

Time Complexity: O(E log V)
Space Complexity: O(V + E)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &e : times){
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> dist(n+1, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated entries
            if(distance > dist[node]) continue;

            for(auto &it : adj[node]){
                int newnode = it.first;
                int newdist = it.second;

                if(distance + newdist < dist[newnode]){
                    dist[newnode] = distance + newdist;
                    pq.push({dist[newnode], newnode});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};