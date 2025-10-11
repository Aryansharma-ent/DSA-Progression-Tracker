#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Permutations II (Unique Permutations)
    Platform: LeetCode
    Difficulty: Medium

    Approach (Backtracking with Duplicate Handling):
    1. Sort the input array `nums` to ensure duplicate numbers are adjacent.
    2. Use a recursive function to build unique permutations step by step:
        - Maintain a `temp` vector for the current permutation.
        - Maintain a `used` boolean vector to track included elements.
    3. For each recursion call:
        - If `temp.size()` equals `nums.size()`, we have a complete permutation → add to answer.
        - Otherwise, iterate over all elements:
            - Skip duplicates: if current number equals previous and previous isn’t used → continue.
            - Mark current number as used, add it to `temp`, and recurse.
            - After recursion, backtrack: remove it from `temp` and mark as unused.
    4. Continue until all unique permutations are generated.

    Time Complexity: O(N * N!)
        - There are up to N! unique permutations.
        - Each permutation takes O(N) to copy into the result vector.

    Space Complexity: O(N)
        - For recursion stack, `used[]`, and temporary permutation vector.

    Key Intuition:
    🔁 Sorting + Skipping duplicates ensures we never explore identical branches of the recursion tree,
       thus eliminating duplicate permutations efficiently.
*/

class Solution {
public:
    void Recur(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, vector<bool> &used) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates: if current equals previous and previous not used
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            if (!used[i]) {
                temp.push_back(nums[i]);
                used[i] = true;
                Recur(ans, nums, temp, used);
                temp.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); // Sorting ensures duplicates are adjacent
        Recur(ans, nums, temp, used);
        return ans;
    }
};

