/*
Problem: Daily Temperatures
Platform: LeetCode
Problem No: 739

Problem Statement:
Given an array of integers temperatures where temperatures[i] is the temperature on the ith day,
return an array answer such that answer[i] is the number of days you have to wait after the ith day
to get a warmer temperature. If there is no future day for which this is possible, answer[i] = 0.

Approach:
- Use a monotonic stack (stack of indices) to find the Next Greater Element (NGE) for each day.
- Traverse from right to left:
  - Maintain a stack of indices whose temperatures are strictly greater than current temperature.
  - Pop indices while the top of stack has temperature <= current temperature.
  - If stack is empty → no warmer day exists → answer[i] = 0
  - Else → next warmer day is at index st.top() → answer[i] = st.top() - i
  - Push current index into the stack.

Why this works:
- The stack always keeps indices in a way that their temperatures are strictly increasing
  from top to bottom for future days.
- Each index is pushed and popped at most once.

Time Complexity:
- O(N), each element is pushed/popped once.

Space Complexity:
- O(N), for the stack and result array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> NGE(vector<int> temperatures, vector<int> &result) {
        stack<int> st; // stores indices

        for (int i = (int)temperatures.size() - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            result[i] = st.empty() ? 0 : (st.top() - i);
            st.push(i);
        }

        return result;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        NGE(temperatures, result);
        return result;
    }
};
