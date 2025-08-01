/*
 Problem: Generate Parentheses
 Leetcode: https://leetcode.com/problems/generate-parentheses/
 Topic: Recursion / Backtracking

 Description:
Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

--------------------------------------------------------------
 Approach:
- Use **backtracking** to build the string step-by-step.
- Keep track of the number of open and close brackets used so far.
- At any point:
  - We can add an opening bracket `'('` if `open < n`.
  - We can add a closing bracket `')'` if `close < open` (to maintain validity).
- Base case: If the current string length is `2 * n`, it's complete and valid → add to the result.

 Dry Run (n = 3):
Start from: "", open=0, close=0  
1. Add '(': "(", open=1  
2. Add '(': "((", open=2  
3. Add '(': "(((", open=3  
4. Add ')': "((()", close=1  
5. Add ')': "((())", close=2  
6. Add ')': "((()))", close=3 → push to result  
... backtrack and try other combinations


 Time Complexity:
- O(2^n): For each level, two choices (add '(' or ')') → exponential tree.
- But due to constraints, total valid combinations for n is given by **Catalan Number**, i.e., Cₙ = (2n)! / (n!(n+1)!) → better than pure 2^n.

Space Complexity:
- O(n) recursion stack depth.
- O(1) extra per recursion call (besides result vector).

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Recur(int n, string current, int open, int close, vector<string> &result) {
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            Recur(n, current + "(", open + 1, close, result);
        }

        if (close < open) {
            Recur(n, current + ")", open, close + 1, result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        Recur(n, "", 0, 0, result);
        return result;
    }
};


