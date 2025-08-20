/*
    Problem: Sliding Window Maximum
    Platform: LeetCode / GFG
    Difficulty: Hard

    Approach:
    - We maintain a deque (double-ended queue) that stores indices of useful elements
      for the current window of size k.
    - At every step:
        1. Remove indices out of the current window.
        2. Remove all elements smaller than the current element from the back of deque
           since they will never be useful.
        3. Push the current element’s index.
        4. The front of the deque always holds the index of the maximum element for the current window.

    Time Complexity: O(n)  → each element is pushed and popped at most once
    Space Complexity: O(k) → for the deque
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // store indices
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        // Remove indices which are out of this window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove elements smaller than nums[i] from the back
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add current element index
        dq.push_back(i);

        // Starting from i >= k - 1, we can take the maximum for each window
        if (i >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}
