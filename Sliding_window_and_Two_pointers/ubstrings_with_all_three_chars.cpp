/*
File: substrings_with_all_three_chars.cpp

Problem:
Given a string s consisting only of characters 'a', 'b', and 'c', 
return the number of substrings containing at least one occurrence of all three characters.

Approach:
1. Define a helper function Algo(s, val) that counts the number of substrings 
   with at most 'val' distinct characters using a sliding window.
   - Maintain a frequency map of characters.
   - Expand the window by moving 'r'.
   - If the window has more than 'val' distinct characters, shrink from 'l' 
     until valid again.
   - For every valid window ending at 'r', add (r - l + 1) to cnt.
2. Use the atMostK trick:
   - Substrings with exactly 3 distinct chars = atMost(3) - atMost(2).

Complexity:
- Time: O(n), each index is visited at most twice (once by right and once by left pointer).
- Space: O(1), since only three possible characters (a, b, c), so hashmap size ≤ 3.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Algo(string s, int val) {
        if (val < 0) return 0;
        
        unordered_map<char,int> mp;
        int cnt = 0, l = 0, n = s.size();

        for (int r = 0; r < n; r++) {
            mp[s[r]]++;
            
            while ((int)mp.size() > val) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }

            cnt += r - l + 1;
        }
        return cnt;
    }

    int numberOfSubstrings(string s) {
        return Algo(s, 3) - Algo(s, 2);
    }
};
