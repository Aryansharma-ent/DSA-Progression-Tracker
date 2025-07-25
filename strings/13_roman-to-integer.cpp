// Leetcode: 13. Roman to Integer
// Time: O(n), Space: O(1)
// Topic: String, Hashing
// intuition is quite simple i.e. any numeral which is less than the given values will be subtracted rest all will be added in the result
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int char2num(char a) {
        switch (a) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && char2num(s[i]) < char2num(s[i + 1])) {
                result -= char2num(s[i]);
            } else {
                result += char2num(s[i]);
            }
        }
        return result;
    }
};
