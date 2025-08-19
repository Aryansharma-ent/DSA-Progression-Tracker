/* Problem Statement

Given an array representing the heights of bars in a histogram, find the area of the largest rectangle that can be formed within the histogram.
 Approach

For each bar, the largest rectangle that can be formed with that bar as the smallest height extends between the previous smaller element (PSE) and next smaller element (NSE).

Compute:

NSE[i]: index of the next smaller bar to the right of i (or n if none exists).

PSE[i]: index of the previous smaller bar to the left of i (or -1 if none exists).

For each i, area = heights[i] * (NSE[i] - PSE[i] - 1).

Track maximum area.

 Complexity

Time: O(n) (each element is pushed and popped from stack at most once).

Space: O(n) for stacks and NSE/PSE arrays.*/

// Problem: Largest Rectangle in Histogram
// Approach: Using NSE + PSE arrays (Stack based)
// Time: O(n), Space: O(n)



#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> NSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n);   // default = n (no smaller to right)
        stack<int> st;           // stack will store indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                ans[st.top()] = i;  // i is the index of next smaller
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> PSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1);   // default = -1 (no smaller to left)
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> right = NSE(heights);
        vector<int> left = PSE(heights);
      
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
