/*
File: subarrays_with_k_distinct.cpp
Problem: Count Subarrays with Exactly K Distinct Integers
Platform: LeetCode (https://leetcode.com/problems/subarrays-with-k-different-integers/)
Topic: Sliding Window + HashMap
Difficulty: Hard

Approach:
- Use the trick: 
      countExactlyK = countAtMostK(k) – countAtMostK(k-1)
- Define a helper function `algo` that counts subarrays with at most k distinct elements.
- Sliding Window:
    - Expand right pointer (r), add nums[r] into hashmap.
    - If window has more than k distinct, shrink from left (l).
    - Each time, all subarrays ending at r are valid, so add (r - l + 1) to count.
- Finally, subtract results of atMost(k) and atMost(k-1) to get exactly K.

Time Complexity: O(N), each element is inserted/removed at most once.
Space Complexity: O(K), hashmap stores at most k distinct elements.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int algo(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int,int> mp;
        int l = 0, count = 0;
        for (int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;
            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            count += r - l + 1; // all valid subarrays ending at r
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return algo(nums, k) - algo(nums, k - 1);
    }
};


