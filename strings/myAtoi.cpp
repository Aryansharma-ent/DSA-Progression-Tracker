// myAtoi.cpp
// Problem: String to Integer (atoi) - LeetCode #8
// Converts a string to a 32-bit signed integer with handling of spaces, signs, invalid chars, and overflow.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Converts the input string s to a 32-bit signed integer.
    
    Approach:
    1. Skip leading whitespaces.
    2. Check for optional '+' or '-' sign.
    3. Parse digits until a non-digit is encountered.
    4. Handle integer overflow by clamping result within INT_MIN and INT_MAX.
    
    Time Complexity: O(n), where n is length of the string (single pass).
    Space Complexity: O(1), constant extra space used.
    */
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        long result = 0;
        int i = 0;

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Handle optional sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Step 3: Parse digits and build the integer result
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 4: Check for overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return (int)(sign * result);
    }
};


