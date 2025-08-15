/*
    Problem: LeetCode 496 - Next Greater Element I
    ------------------------------------------------
    Approach:
    - Use a monotonic decreasing stack to precompute the next greater element for each number in nums2.
    - Traverse nums2 from left to right:
        - While stack is not empty and the current number > stack's top:
            - This means current number is the next greater element for the stack's top.
            - Pop from stack and store mapping in an unordered_map.
        - Push current number into stack.
    - After the loop, assign -1 for all remaining elements in the stack (no greater element exists).
    - Build the answer for nums1 by simply looking up the precomputed map.

    Complexity:
    - Time Complexity: O(m + n)
        * Each element is pushed and popped from the stack at most once.
        * Map lookups for nums1 are O(1) average.
    - Space Complexity: O(n)
        * For the stack and unordered_map storing next greater elements.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }
        return ans;
    }
};
