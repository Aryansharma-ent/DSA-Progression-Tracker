/*
Approach:
- We recursively pop all elements from the stack until it becomes empty.
- Then, we insert each element at the bottom of the stack as the recursion unwinds.
- This effectively reverses the stack using recursion.

Functions:
- reverseStack(): Pops elements recursively and then uses insertp() to push them at the bottom.
- insertp(): Inserts an element at the bottom of the stack recursively.

Time Complexity:
- O(n^2) in worst case because each insertp() can take O(n) time and it’s called n times.
- Specifically, insert at bottom is O(n), and we do it for each element.

Space Complexity:
- O(n) due to recursion call stack.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseStack(stack<int> &st) {
        if (st.empty()) {
            return;
        }
        int temp = st.top();
        st.pop();
        reverseStack(st);
        insertp(st, temp);
    }

    void insertp(stack<int> &st, int temp) {
        if (st.empty()) {
            st.push(temp);
            return;
        }
        int top = st.top();
        st.pop();
        insertp(st, temp);
        st.push(top);
    }
};
