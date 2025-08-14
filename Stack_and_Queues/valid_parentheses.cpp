
/*
Problem:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every closing bracket has a corresponding opening bracket of the same type.

Approach:
1. Use a stack to store opening brackets as they appear.
2. Iterate through each character in the string:
   - If it's an opening bracket ('(', '{', '['), push it onto the stack.
   - If it's a closing bracket:
     a. Check if the stack is empty — if yes, return false.
     b. Pop the top element and verify if it matches the corresponding opening bracket.
     c. If it does not match, return false immediately.
3. After the loop, check if the stack is empty — if not, there are unmatched brackets.
4. If the stack is empty, the string is valid.

Time Complexity:
O(n) — Each character is pushed and popped from the stack at most once.

Space Complexity:
O(n) — Stack can store up to all characters in the worst case (all opening brackets).

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char ch = st.top();
                st.pop();
                if (!((c == ')' && ch == '(') || 
                      (c == ']' && ch == '[') || 
                      (c == '}' && ch == '{'))) {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};

