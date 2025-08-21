/*
LeetCode 424. Longest Repeating Character Replacement

Problem:
Given a string s and an integer k, return the length of the longest substring 
containing the same character after replacing at most k characters.

Approach:
- Use sliding window with two pointers (l and r).
- Maintain a frequency array for characters in the window.
- Track the count of the most frequent character in the current window.
- A window is valid if (window length - maxFreq) <= k.
- If invalid, shrink the window from the left.
- Keep track of the maximum valid window length.

Complexity:
- Time: O(n), each character processed once.
- Space: O(1), since only 26 uppercase letters are considered.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int l = 0, maxFreq = 0, maxLen = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);

            // If window invalid, shrink it
            while ((r - l + 1) - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
