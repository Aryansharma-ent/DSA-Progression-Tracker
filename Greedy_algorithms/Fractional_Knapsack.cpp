/*
LeetCode 170 Fractional Knapsack (GFG version too)
--------------------------------------------------
Problem:
- Given values and weights of items, put them in a knapsack of capacity W.
- You can take fractions of items.
- Maximize the total value in the knapsack.

Approach (Greedy + Sorting by ratio):
1. Compute value/weight ratio for each item.
2. Sort items in descending order of ratio.
3. Traverse items:
   - If full item fits, take it.
   - Else take fraction proportional to remaining capacity.
4. Stop when capacity becomes 0.

Complexities:
- Time: O(n log n)  // sorting dominates
- Space: O(n)       // for storing ratios

Code:
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        // store {ratio, index}
        vector<pair<double, int>> ratio;
        for (int i = 0; i < n; i++) {
            ratio.push_back({(double)val[i] / wt[i], i});
        }

        // sort by ratio descending
        sort(ratio.rbegin(), ratio.rend());

        double ans = 0.0;
        for (int k = 0; k < n && capacity > 0; k++) {
            int idx = ratio[k].second;
            if (wt[idx] <= capacity) {
                ans += val[idx];
                capacity -= wt[idx];
            } else {
                ans += ((double)val[idx] / wt[idx]) * capacity;
                capacity = 0;
            }
        }

        return ans;
    }
};
