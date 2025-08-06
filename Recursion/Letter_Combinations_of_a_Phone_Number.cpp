/*
    Problem: Letter Combinations of a Phone Number
    Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

     Approach:
    - This is a classic backtracking problem.
    - Each digit maps to a set of characters (like '2' → "abc").
    - Start from index 0 and try each character for the current digit.
    - Recursively move to the next digit after choosing a character.
    - Once the current string (temp) reaches the length of digits, we add it to the answer.

     Time Complexity:
    - O(4^N), where N is the number of digits.
      Each digit maps to at most 4 letters (like '7' or '9'), so in worst-case we explore 4^N combinations.

     Space Complexity:
    - O(N) auxiliary space for recursion stack.
    - O(4^N * N) for the result storage in the worst case.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Recur(int index, string &temp, vector<string> &ans, unordered_map<char, string> &mp, string &digits) {
        if (index == digits.length()) {
            ans.push_back(temp);
            return;
        }

        for (char c : mp[digits[index]]) {
            temp.push_back(c);                        
            Recur(index + 1, temp, ans, mp, digits);  
            temp.pop_back();                 
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        string temp;
        vector<string> ans;
        Recur(0, temp, ans, mp, digits);
        return ans;
    }
};
