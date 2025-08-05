/*
 Leetcode Problem: Combination Sum II (https://leetcode.com/problems/combination-sum-ii/)
 Difficulty: Medium

 Approach:
        - Sort the input array to handle duplicates.
        - Use backtracking to generate all combinations.
        - Skip duplicates at the same recursive level using `if(i > index && candidates[i] == candidates[i-1])`.
        - Each element can be used only once → move to i + 1 in recursive call.
        - Prune recursion when candidates[i] > target.

    Time Complexity:
        - O(2^n) in the worst case (backtracking over all subsets)
 Space Complexity:
        - O(k) for recursion depth and temporary storage, where k is the size of one combination.

 Key Points:
        - Each number can be used only once.
        - Input may contain duplicates, but output must have unique combinations.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Recur(int index, vector<int> &temp, vector<vector<int>> &ans, vector<int> &candidates, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
            if (candidates[i] > target) break; /

            temp.push_back(candidates[i]);
            Recur(i + 1, temp, ans, candidates, target - candidates[i]);
            temp.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        Recur(0, temp, ans, candidates, target);
        return ans;
    }
};
