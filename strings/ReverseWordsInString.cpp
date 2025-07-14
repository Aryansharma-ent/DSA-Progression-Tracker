// Problem: LeetCode 151 - Reverse Words in a String
// Link: https://leetcode.com/problems/reverse-words-in-a-string/
// Category: Strings
// Approach: In-place reverse of the entire string and each word
// Time Complexity: O(n)
// Space Complexity: O(1)
// well it was kinda tricky cause it was my first time solving such a variety in a string cause i only knew about the reverse string concepts

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int i = 0, r = 0, l = 0;
        int n = s.size();

        while (i < n) {
            while (i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }

            if (l < r) {
                reverse(s.begin() + l, s.begin() + r);
                s[r] = ' ';
                r++;
                l = r;
            }
            i++;
        }

        return s.substr(0, r > 0 ? r - 1 : 0); // Handles trailing space
    }
};

