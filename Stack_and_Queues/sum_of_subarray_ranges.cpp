/*
-----------------------------------
 Problem: 2104. Sum of Subarray Ranges
-----------------------------------

 Description:
You are given an integer array `nums`. The range of a subarray of `nums` is the difference between the largest 
and smallest element in the subarray. Return the sum of all subarray ranges of `nums`.

-----------------------------------
 Approach:
1. Brute Force (O(n^2)): 
   - For each subarray, find min and max, then add (max - min).
   - Too slow for large n.

2. Optimized Contribution Technique with Monotonic Stacks (O(n)):
   - Each element contributes as:
        → A maximum in some subarrays
        → A minimum in some subarrays
   - Use stacks to compute:
        - PSE: Previous Smaller Element
        - NSE: Next Smaller Element
        - PGE: Previous Greater Element
        - NGE: Next Greater Element
   - Contribution:
        minContribution = nums[i] * (i - PSE[i]) * (NSE[i] - i)
        maxContribution = nums[i] * (i - PGE[i]) * (NGE[i] - i)
   - Total = Σ(maxContribution - minContribution)

-----------------------------------

Time Complexity:
- O(n), since each element is pushed/popped at most once from a stack.

Space Complexity:
- O(n), for storing PSE, NSE, PGE, NGE arrays.

-----------------------------------
 Example:
Input: nums = [1,2,3]
Subarrays:
[1] → range = 0
[2] → range = 0
[3] → range = 0
[1,2] → range = 1
[2,3] → range = 1
[1,2,3] → range = 2
Total = 4

Output: 4
-----------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        // Arrays for previous/next smaller/greater indices
        vector<int> PSE(n), NSE(n), PGE(n), NGE(n);

        // ----------- PSE (Previous Smaller Element) -----------
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            PSE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // ----------- NSE (Next Smaller Element) -----------
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // ----------- PGE (Previous Greater Element) -----------
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            PGE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // ----------- NGE (Next Greater Element) -----------
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            NGE[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long leftMin = i - PSE[i];
            long long rightMin = NSE[i] - i;
            long long leftMax = i - PGE[i];
            long long rightMax = NGE[i] - i;

            long long minContribution = (long long)nums[i] * leftMin * rightMin;
            long long maxContribution = (long long)nums[i] * leftMax * rightMax;

            ans += (maxContribution - minContribution);
        }

        return ans;
    }
};
