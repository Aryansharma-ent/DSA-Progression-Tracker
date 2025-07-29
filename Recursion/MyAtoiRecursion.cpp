/*Approach:
We skip leading whitespaces, determine the sign, ignore leading zeroes, and then recursively construct the number using digits only. The recursion accumulates the number digit by digit while checking for overflow conditions. If an overflow is detected, we immediately return INT_MAX or INT_MIN accordingly.

Time Complexity:
O(n), where n is the number of characters in the string after leading spaces and optional sign.
Each digit is processed once in the recursive function.

Space Complexity:
O(n) for recursion stack (in worst case all characters are digits).
*/
#include <iostream>
#include <climits>
#include <string>
using namespace std;

class Solution {

    int getNum(const string& s, int i, long result, int sign) {

        if (i >= s.size() || !isdigit(s[i]))
            return sign * result;

        result = result * 10 + (s[i] - '0');

        // Check for overflow
        if (sign * result >= INT_MAX) return INT_MAX;
        if (sign * result <= INT_MIN) return INT_MIN;

        // Recursive call for next character
        return getNum(s, i + 1, result, sign);
    }

public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long result = 0;

  
        while (i < s.size() && s[i] == ' ') i++;

        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.size() && s[i] == '0') i++;

        
        return getNum(s, i, 0L, sign);
    }
};

