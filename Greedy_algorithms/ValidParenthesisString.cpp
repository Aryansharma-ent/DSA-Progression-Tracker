/*
Problem: Leetcode 678 - Valid Parenthesis String

Approach:
We maintain two counters:
- low = minimum possible open brackets (consider '*' as ')' or empty).
- high = maximum possible open brackets (consider '*' as '(').

Process string left to right:
1. '(' → increase both low and high.
2. ')' → decrease both low and high.
3. '*' → treat as flexible: decrease low (like ')'), increase high (like '(').
4. If high < 0 at any time → invalid.
5. Ensure low never drops below 0.
Finally, if low == 0 → string is valid.

Time Complexity: O(n)  (one pass over the string)
Space Complexity: O(1) (only counters used)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0; 
        for (char c : s) {
            if (c == '(') {
                low++; 
                high++;
            } else if (c == ')') {
                if (low > 0) low--; 
                high--;
            } else { // '*'
                if (low > 0) low--; 
                high++;
            }
            if (high < 0) return false; 
        }
        return low == 0;
    }
};
