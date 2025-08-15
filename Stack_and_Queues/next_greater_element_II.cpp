/*
    Problem: LeetCode 503 - Next Greater Element II
    ------------------------------------------------
    Approach:
    - The array is circular, meaning after the last element we wrap around to the start.
    - To simulate circularity, iterate through the array twice (indices from 2*n-1 down to 0).
    - Use a monotonic decreasing stack to keep track of elements for which we haven't found the next greater.
    - For each index:
        - Pop elements from the stack while the current number is greater than or equal to stack's top.
        - If i < n (meaning we are in the first pass for actual array positions), store the next greater element
          as the stack's top if stack is not empty, else -1.
        - Push the current number into the stack.
    - This ensures each element's next greater element is found in O(1) amortized time.

    Complexity:
    - Time Complexity: O(n)
        * Each element is pushed and popped at most once from the stack.
    - Space Complexity: O(n)
        * For the stack and result vector.

    Example:
    nums = [1, 2, 1]
    Output = [2, -1, 2]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); // default -1
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (i < n) {
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};
