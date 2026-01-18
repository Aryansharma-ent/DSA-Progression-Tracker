/*
Problem: Simplify Path
Platform: LeetCode
Problem No: 71

Problem Statement:
Given a string path, which is an absolute path (starting with a slash '/') to a file
or directory in a Unix-style file system, convert it to a simplified canonical path.

Rules:
- "." means current directory → ignore it
- ".." means move to parent directory → pop last folder if possible
- Multiple slashes "//" should be treated as a single slash "/"
- The final path must:
  - start with "/"
  - have no trailing "/" unless it's the root "/"

Approach:
- Use stringstream to split the path by '/'.
- Use a stack to store valid directory names.
- For each token:
  - Ignore empty tokens and "."
  - If token is ".." → pop from stack if not empty
  - Else → push directory name into stack
- Reconstruct the simplified path from stack contents.

Why this works:
- Stack perfectly models directory navigation (go inside / go back).
- Each token is processed once.

Time Complexity:
- O(N), where N is length of the path.
Space Complexity:
- O(N), for storing directories in stack.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        stringstream ss(path);
        stack<string> st;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") continue;

            if (token != "..") {
                st.push(token);
            } else {
                if (!st.empty()) st.pop();
            }
        }

        if (st.empty()) {
            return "/";
        }

        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result;
    }
};
