// LeetCode 67: Add Binary

#include <bits/stdc++.h>
using namespace std;

/*
Problem: Add Binary Strings

Intuition:
This problem is similar to adding two numbers manually from right to left.
Since the numbers are given as binary strings, we:
- Start from the last character of both strings.
- Add corresponding bits along with carry.
- Append the result bit.
- Continue until all bits and carry are processed.

Approach:
1. Initialize two pointers:
   - i at end of string a
   - j at end of string b
2. Maintain a carry variable.
3. While either string has remaining characters OR carry exists:
   - Add carry to sum.
   - Add a[i] if valid.
   - Add b[j] if valid.
   - Append (sum % 2) to result.
   - Update carry = sum / 2.
4. Reverse the result string at the end since we built it backwards.

Why this works:
Binary addition rules:
0 + 0 = 0
1 + 0 = 1
1 + 1 = 0 (carry 1)
1 + 1 + 1 = 1 (carry 1)

Time Complexity:
O(max(n, m)) where n and m are lengths of input strings.

Space Complexity:
O(max(n, m)) for storing the result string.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        string result;

        while(i >= 0 || j >= 0 || carry){
            int sum = carry;

            if(i >= 0){
                sum += (a[i] - '0');
                i--;
            }

            if(j >= 0){
                sum += (b[j] - '0');
                j--;
            }

            result.push_back((sum % 2) ? '1' : '0');
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
