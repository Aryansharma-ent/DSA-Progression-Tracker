/*
    File: combination_sum_backtracking.cpp

    Problem:
    Given an array of distinct integers `candidates` and a target integer `target`,
    return all unique combinations in `candidates` where the chosen numbers sum to `target`.
    You may use the same number from `candidates` multiple times.

    Approach:
    - We use recursive backtracking.
    - At each step, we decide whether to include the current element (and stay at same index),
      or move to the next index (to avoid repetition of combinations).
    - If target becomes 0, we store the current valid combination.
    - If target goes negative or we reach the end, we backtrack.

    Time Complexity: O(2^t) where t is the target sum
        - Because each number can be picked unlimited times, and we explore multiple branches.

    Space Complexity: O(k), where k is the current depth of the recursive stack (up to target/candidates[i])

    Note:
    - We pass `temp` by value to avoid needing manual pop_back (optional design choice).
    - The input `candidates` should not contain duplicates.
*/

 #include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void Recur(int index, vector<int> temp, vector<vector<int>> &ans, vector<int> candidates, int target) {
        if(index == candidates.size()) {
            if(target == 0) {
                ans.push_back(temp);
            }
            return;
        }

        if(candidates[index] <= target) {
            temp.push_back(candidates[index]);
            Recur(index, temp, ans, candidates, target - candidates[index]);
       
        }

       
        Recur(index + 1, temp, ans, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        Recur(0, temp, ans, candidates, target);
        return ans;
    }
};
