/*
LeetCode 455. Assign Cookies
--------------------------------
Problem:
- Each child has a greed factor g[i].
- Each cookie has a size s[j].
- A child i is content if s[j] >= g[i].
- Goal: Maximize number of content children.

Approach (Greedy + Two Pointers):
1. Sort both g (greed) and s (cookies).
2. Use two pointers:
   - r → child pointer
   - l → cookie pointer
3. Traverse cookies:
   - If s[l] >= g[r], assign cookie to child and increment r.
   - Always move to the next cookie (l++).
4. At the end, r is the count of satisfied children.

Complexities:
- Time: O(n log n + m log m) due to sorting.
- Space: O(1), ignoring sorting space.

Code:
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size();
        int m = s.size();
        int l = 0; // pointer for cookies
        int r = 0; // pointer for children
        while (l < m && r < n) {
            if (g[r] <= s[l]) {
                r++;
            }
            l++;
        }
        return r;
    }
};
