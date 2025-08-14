

/*
Problem:
LeetCode 155 — Min Stack
Design a stack that supports the following operations in constant time:
1. push(int val) — Pushes the element onto the stack.
2. pop() — Removes the top element.
3. top() — Retrieves the top element.
4. getMin() — Retrieves the minimum element in the stack.

Constraints:
- All operations must run in O(1) time complexity.

Approach:
We use a single stack of pairs (value, current_min).
- First element of pair: actual pushed value.
- Second element of pair: the minimum value in the stack at that point.
When pushing:
    - If the stack is empty, push (val, val).
    - Else, push (val, min(val, current_min)).
When popping:
    - Simply pop the top pair.
When calling top():
    - Return the first value in the top pair.
When calling getMin():
    - Return the second value in the top pair.

This ensures O(1) retrieval of both top and minimum.

Time Complexity:
- push: O(1)
- pop: O(1)
- top: O(1)
- getMin: O(1)

Space Complexity:
O(n) — Each element stores its own min so far in the stack.

*/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<pair<int,int>> st;
    
    MinStack() {}
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};


