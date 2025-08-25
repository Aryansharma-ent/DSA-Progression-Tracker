/*
File: minimum_window_substring.cpp
Problem: Minimum Window Substring
Platform: LeetCode (https://leetcode.com/problems/minimum-window-substring/)
Topic: Sliding Window + HashMap
Difficulty: Hard

Approach:
- Use a hashmap to store the frequency of characters required from string t.
- Expand right pointer r, decrementing the frequency of s[r] in the map.
- If s[r] was a required character (mp[s[r]] > 0 before decrement), increment cnt.
- Once cnt == m (all characters covered), attempt to shrink the window from left l.
- While shrinking, update the minimum window length and starting index if smaller found.
- Restore frequencies when moving l; if a required character is lost, decrement cnt.
- Continue until the end, return the minimum window substring.

Time Complexity: O(N), where N = length of s. Each character processed at most twice.
Space Complexity: O(M), where M = size of t (map stores at most distinct chars in t).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for (char c : t) mp[c]++;

        int l = 0, r = 0, cnt = 0;
        int minlen = INT_MAX, startIndex = -1;
        int n = s.size(), m = t.size();

        while (r < n) {
            if (mp[s[r]] > 0) cnt++;
            mp[s[r]]--;

            // shrink window if valid
            while (cnt == m) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    startIndex = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return (startIndex == -1) ? "" : s.substr(startIndex, minlen);
    }
};
