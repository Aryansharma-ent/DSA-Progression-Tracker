// LeetCode 14 - Longest Common Prefix
// Problem Link: https://leetcode.com/problems/longest-common-prefix/

// Approach:
// Start with the first string as the initial prefix.
// For each string in the array, compare characters from the beginning
// and shorten the prefix to the matched portion.
// Stop early if prefix becomes empty.
// note : well it was kinda tricky for me because i didn't have any knowledge about 'trie' data structure before this question but it was great


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                j++;
            }
            prefix = prefix.substr(0, j);
            if (prefix == "") return "";
        }

        return prefix;
    }
};
