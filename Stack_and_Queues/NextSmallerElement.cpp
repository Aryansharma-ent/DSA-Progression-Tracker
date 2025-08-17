/*
----------------------------------------------
Problem: Next Smaller Element (NSE)

Approach:
- We traverse the array from right to left.
- We use a stack to keep track of potential "next smaller elements".
- For each element arr[i]:
    1. Pop elements from the stack until we find a smaller element than arr[i].
    2. If the stack is not empty, the top of the stack is the Next Smaller Element.
    3. Push the current element arr[i] into the stack.
- If no smaller element is found, the answer is -1.

Example:
Input:  [4, 8, 5, 2, 25]
Output: [2, 5, 2, -1, -1]

Complexities:
- Time Complexity: O(n) 
    (Each element is pushed and popped at most once from the stack)
- Space Complexity: O(n)
    (Stack can store up to n elements in the worst case, and output array)

----------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // Pop elements greater or equal to arr[i]
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            // If stack not empty, top is next smaller
            if (!st.empty()) {
                ans[i] = st.top();
            }

            // Push current element into stack
            st.push(arr[i]);
        }
        return ans;
    }
};

