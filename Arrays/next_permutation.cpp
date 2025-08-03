/*
📝 Problem: Next Permutation (Leetcode 31)
🔗 Link: https://leetcode.com/problems/next-permutation/

👨‍💻 Approach:
1. Traverse from right to left and find the first pair `i` where `nums[i] < nums[i+1]`.
2. If such an `i` is found:
   a. Traverse from the end again to find an element just larger than `nums[i]` (let's say at index `j`), and swap them.
   b. Reverse the subarray from index `i+1` to the end to get the next smallest lexicographical permutation.
3. If no such `i` exists, reverse the entire array (it's already the highest permutation).

📈 Time Complexity: O(n)
📦 Space Complexity: O(1) — in-place manipulation
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // Step 1: Find the first decreasing element from the end
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // If no such element, array is in descending order → reverse it
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the element just greater than nums[index]
        for(int i = n - 1; i > index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 3: Reverse the suffix starting at index + 1
        reverse(nums.begin() + index + 1, nums.end());
    }
};
