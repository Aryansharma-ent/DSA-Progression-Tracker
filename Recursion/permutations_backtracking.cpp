#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Permutations of an Array
    Platform: LeetCode
    Difficulty: Medium

    Approach (Backtracking):
    1. Use a recursive function to build permutations step by step:
        - Maintain a `temp` vector to store the current permutation.
        - Maintain a `used` boolean vector to track which elements have been included.
    2. For each recursive call:
        - If `temp.size()` equals `nums.size()`, we have a complete permutation → add to answer.
        - Otherwise, try each unused element:
            - Mark it as used, add to `temp`, recurse.
            - After recursion, backtrack: remove from `temp` and mark as unused.
    3. Continue until all permutations are generated.

    Time Complexity: O(N * N!)
        - There are N! permutations.
        - Each permutation of length N takes O(N) to copy to the answer.

    Space Complexity: O(N)
        - For recursion stack and `temp` vector.

    Key Intuition:
    🔄 Backtracking generates all permutations by exploring every possibility 
       and undoing choices to explore other branches.
*/

class Solution {
public:
    void Recur(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, vector<bool> &used) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                temp.push_back(nums[i]);
                used[i] = true;
                Recur(ans, nums, temp, used);
                temp.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        Recur(ans, nums, temp, used);
        return ans;
    }
};
