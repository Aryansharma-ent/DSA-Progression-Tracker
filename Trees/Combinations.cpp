/*
Problem: Combinations
Platform: LeetCode
Problem No: 77

Problem Statement:
Given two integers n and k, return all possible combinations of k numbers chosen
from the range [1, n]. You may return the answer in any order.

Approach:
- Use backtracking (DFS).
- Build combinations using a temporary vector `temp`.
- Start choosing numbers from `index` to ensure:
  - No duplicates
  - Combinations are in increasing order
- When temp.size() becomes k, we store it in the answer.

Why this works:
- Each recursive call chooses the next number from a higher starting point (i+1),
  ensuring each number is used at most once and combinations are unique.
- Backtracking removes the last choice to explore other possibilities.

Time Complexity:
- O(C(n, k) * k)
  We generate C(n, k) combinations and each combination has length k.

Space Complexity:
- O(k) recursion depth (excluding output storage).

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Recur(int n, int k,
               vector<vector<int>> &ans,
               vector<int> temp,
               int index) {

        if ((int)temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i <= n; i++) {
            temp.push_back(i);
            Recur(n, k, ans, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        Recur(n, k, ans, temp, 1);
        return ans;
    }
};
