/*
    Problem: Combination Sum III
    Link: https://leetcode.com/problems/combination-sum-iii/

     Approach:
    - Use backtracking to explore combinations.
    - Start from number 1 to 9 and build combinations of size 'k'.
    - Only proceed if the running sum doesn't exceed 'n'.
    - Each number is used at most once, so recurse with the next number (i + 1).
    - If a combination reaches size 'k' and the remaining sum is 0, it's valid.

     Time Complexity:
    - O(C(9, k)) -> Because we are choosing k numbers from 1 to 9.

     Space Complexity:
    - O(k) for the temporary list 'temp' used during recursion.
    - O(C(9, k) * k) for the final answer list.

     Constraints:
    - 1 <= k <= 9
    - 1 <= n <= 60
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Recur(int start, vector<int>& temp, vector<vector<int>>& ans, int k, int n) {
        if (temp.size() == k) {
            if (n == 0) {
                ans.push_back(temp);
            }
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > n) break; 
            temp.push_back(i);
            Recur(i + 1, temp, ans, k, n - i);
            temp.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        Recur(1, temp, ans, k, n);
        return ans;
    }
};
