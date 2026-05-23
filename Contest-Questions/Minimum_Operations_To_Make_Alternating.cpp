/*
========================================
Problem: Minimum Operations to Make Alternating Array
Platform: LeetCode
Approach: Brute Force on Modulo Targets

Author: Aryan
Date: 2026

----------------------------------------
Approach:

1. Try every possible pair (x, y)
   where:
   - x = target remainder for even indices
   - y = target remainder for odd indices
   - x != y

2. For each element:
   - Compute current remainder = nums[i] % k
   - Find minimum circular distance to target remainder

3. Calculate total operations required
   for the chosen pair (x, y)

4. Return the minimum operations
   among all valid pairs

----------------------------------------
Key Insight:

Since modulo values are circular,
cost to convert rem -> target is:

min(abs(rem - target), k - abs(rem - target))

----------------------------------------
Time Complexity: O(k² * n)
Space Complexity: O(1)

========================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        // Single element already satisfies condition
        if(nums.size() == 1) return 0;

        int ans = INT_MAX;

        // Try all possible alternating pairs
        for(int x = 0; x < k; x++) {

            for(int y = 0; y < k; y++) {

                // Adjacent positions must differ
                if(x == y) continue;

                int cnt = 0;

                for(int i = 0; i < nums.size(); i++) {

                    // Even index -> x
                    // Odd index  -> y
                    int target = (i % 2 == 0) ? x : y;

                    int rem = nums[i] % k;

                    // Circular distance
                    int diff = abs(rem - target);

                    cnt += min(diff, k - diff);
                }

                ans = min(ans, cnt);
            }
        }

        return ans;
    }
};