

/*
Problem: Max Consecutive Ones III (LeetCode 1004)

Approach:
- Use the sliding window technique.
- Maintain two pointers (l and r) representing the window boundaries.
- Keep a count of zeros inside the window.
- If the zero count exceeds k, shrink the window from the left until it's valid again.
- At each step, calculate the maximum length of the valid window.

Time Complexity: O(n) 
    - Each element is processed at most twice (once by r, once by l).
Space Complexity: O(1) 
    - Only a few variables are used, no extra data structures.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        int maxlen = 0;
        int zerocount = 0;

        while (r < n) {
            if (nums[r] == 0) {
                zerocount++;
            }

            while (zerocount > k) {
                if (nums[l] == 0) zerocount--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
