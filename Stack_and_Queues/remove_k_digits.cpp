/* Problem

402. Remove K Digits (LeetCode)

You are given a string num representing a non-negative integer and an integer k.
Remove k digits from the number so that the new number is the smallest possible.

Approach

Use a monotonic increasing stack:

Traverse digits left to right.

Pop from stack while k > 0 and current digit < stack top (to maintain smallest lexicographic number).

Push current digit to stack.

After traversal, if k > 0, remove remaining digits from stack.

Build result string from stack, remove leading zeros, reverse string to correct order.

Return "0" if result is empty.

 Complexity

Time: O(n) — each digit is pushed/popped at most once.

Space: O(n) — stack to store digits.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k > 0) {
            st.pop();
            k--;
        }

        if (st.empty()) return "0";

        string result = "";
        while (!st.empty()) {
            result = result + st.top();
            st.pop();
        }

        while (result.size() != 0 && result.back() == '0') {
            result.pop_back();
        }

        reverse(result.begin(), result.end());
        if (result.empty()) return "0";

        return result;
    }
};
