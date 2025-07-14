// Problem: LeetCode 1903 - Largest Odd Number in String
// Link: https://leetcode.com/problems/largest-odd-number-in-string/
// Category: Strings
// Approach: Traverse from the end and find the last odd digit. Return the prefix up to that digit.
// Time Complexity: O(n) - Worst-case full string scan
// Space Complexity: O(1) - No extra space used beyond output
// Note: It was an easier one compared to the other two I solved today, 
//       just needed a bit of conceptual clarity around substring manipulation.


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        if (num.back() % 2 == 1) return num;

        int i = num.length() - 1;
        while (i >= 0) {
            int n = num[i];
            if (n % 2 == 1) return num.substr(0, i + 1);
            i--;
        }
        return "";
    }
};
