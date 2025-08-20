#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;

        vector<int> hash(256, -1);  // track last seen positions of characters
        int l = 0, r = 0, maxlen = 0;
        int n = s.size();

        while (r < n) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;  // move left pointer
            }
            maxlen = max(maxlen, r - l + 1);
            hash[s[r]] = r; // update last seen index
            r++;
        }
        return maxlen;
    }
};