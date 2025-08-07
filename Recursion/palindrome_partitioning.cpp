/*
 Description:
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

 Input:
- A string s

 Output:
- A vector of vector of strings containing all possible palindrome partitions

 Example:
Input: "aab"
Output: [["a","a","b"], ["aa","b"]]

-----------------------------------------------

 Approach:
- Use backtracking to explore all possible partitions.
- At each step, check if the current substring (from index to i) is a palindrome.
- If yes, include it in the current path and recurse from i+1.
- If the end of the string is reached, store the current path.
- Use a helper function `ispalindrome()` to check if a substring is a palindrome.

-----------------------------------------------

Time Complexity:
- Worst-case: O(2^n * n)
  - 2^n for generating all possible partitions
  - n for checking palindromes and copying substrings

 Space Complexity:
- O(n) for recursion stack (max depth = n)
- O(2^n * n) for storing all partitions

-----------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool ispalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    void Recur(int index, string &s, vector<string> &temp, vector<vector<string>> &ans) {
        if (index == s.length()) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (ispalindrome(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1));
                Recur(i + 1, s, temp, ans);
                temp.pop_back(); // Backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        Recur(0, s, temp, ans);
        return ans;
    }
};

