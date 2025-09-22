/*
Problem: Minimum Platforms (GFG)

Approach:
- Sort the arrival and departure times separately.
- Use two pointers:
  - `i` for arrival
  - `j` for departure
- Traverse arrivals:
  - If the next train arrives before or at the same time as the current departure → need a new platform (`cnt++`).
  - Else → one train has departed (`cnt--`, move `j`).
- Keep track of the maximum platforms required (`maxcnt`).

Complexity:
- Time: O(n log n) — due to sorting arrivals and departures.
- Space: O(1) — uses only counters and pointers.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0;
        int cnt = 0, maxcnt = 0;

        while (i < arr.size()) {
            if (arr[i] <= dep[j]) {
                cnt++;
                i++;
            } else {
                cnt--;
                j++;
            }
            maxcnt = max(maxcnt, cnt);
        }
        return maxcnt;
    }
};
