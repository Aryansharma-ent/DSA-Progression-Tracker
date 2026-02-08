#include <bits/stdc++.h>
using namespace std;

/*
Problem (as implemented):
Count the number of subarrays such that:
    (max(subarray) - min(subarray)) * (length of subarray) <= k

Intuition:
For any fixed right end r, if we can find the smallest left end l such that
the window [l..r] satisfies the condition, then every subarray ending at r
and starting anywhere from l..r is valid.

So for each r, add (r - l + 1) to the answer.

Approach (Sliding Window + Multiset):
- Use two pointers l and r to maintain a sliding window.
- Maintain a multiset of elements in the current window so we can get:
    mini = *ms.begin()
    maxi = *ms.rbegin()
  in O(1) time (after O(log n) insert/erase).
- Expand r:
    - insert nums[r]
    - while cost > k, shrink from left:
        erase nums[l] from multiset, l++
- Once valid, count all subarrays ending at r:
    add (r - l + 1)

Cost formula:
    cost = (maxi - mini) * window_length

Time Complexity:
- Each element inserted and erased at most once from multiset
- Each operation is O(log n)
=> O(n log n)

Space Complexity:
- multiset can hold up to window size
=> O(n) worst case
*/

class Solution {
public:
    long long Algo(const vector<int>& nums, long long k) {
        if (k < 0) return 0;

        long long ans = 0;
        int l = 0;

        multiset<int> ms;

        for (int r = 0; r < (int)nums.size(); r++) {
            ms.insert(nums[r]);

            while (!ms.empty()) {
                long long maxi = *ms.rbegin();
                long long mini = *ms.begin();
                long long len  = (r - l + 1LL);
                long long cost = (maxi - mini) * len;

                if (cost <= k) break;

                ms.erase(ms.find(nums[l]));
                l++;
            }

            ans += (r - l + 1LL);
        }

        return ans;
    }

    long long countSubarrays(vector<int>& nums, long long k) {
        return Algo(nums, k);
    }
};
