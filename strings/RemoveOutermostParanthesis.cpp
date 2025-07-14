// Problem: Remove Outermost Parentheses
// Platform: LeetCode
// Link: https://leetcode.com/problems/remove-outermost-parentheses/
// Difficulty: Easy
// Tags: Stack, String
// Approach: Track balance of parentheses; add inner parentheses to result.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int balance = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                if(balance > 0) {
                    result += s[i];
                }
                balance++;
            }
            else {
                balance--;
                if(balance > 0) {
                    result += s[i];
                }
            }
        }
        return result;
    }
};
