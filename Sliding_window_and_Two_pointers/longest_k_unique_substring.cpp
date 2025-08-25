/*
File: longest_k_unique_substring.cpp
Problem: Longest Substring with Exactly K Distinct Characters
Platform: GFG (https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1)
Topic: Sliding Window + HashMap
Difficulty: Medium

Approach:
- Use two pointers (l, r) to represent a sliding window.
- Maintain a hashmap (unordered_map) to count characters inside the window.
- Expand the window by moving r.
- If the number of distinct characters (map.size()) exceeds k, shrink from left (l).
- Whenever map.size() == k, update maxlen = max(maxlen, r - l + 1).
- Return maxlen (or -1 if no valid substring exists).

Time Complexity: O(N), each character is added/removed at most once.
Space Complexity: O(K), hashmap stores at most k distinct characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, n = s.size();
        int maxlen = -1;  // return -1 if no such substring exists

        while (r < n) {
            mp[s[r]]++;  // include current char in window

            // shrink from left if too many distinct chars
            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }

            // check valid window
            if (mp.size() == k) {
                maxlen = max(maxlen, r - l + 1);
            }

            r++; // expand right pointer
        }

        return maxlen;
    }
};


