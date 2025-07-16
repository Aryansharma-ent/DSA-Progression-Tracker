//  LeetCode: 242. Valid Anagram
//  https://leetcode.com/problems/valid-anagram/

//  Approach: Frequency Count
// We count each character's frequency in both strings.
//  Time Complexity: O(n)
//  Space Complexity: O(1)
// If counts match for all 26 letters, it's an anagram.
// it was an easier one relatively speaking

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int freq[26] = {0};

        for (char c : s) freq[c - 'a']++;
        for (char c : t) freq[c - 'a']--;

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return false;
        }

        return true;
    }
};
