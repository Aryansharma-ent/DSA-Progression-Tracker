
/*
Problem: Asteroid Collision (LeetCode 735)

You are given an array asteroids of integers representing asteroids in a row.
- For each asteroid, the absolute value represents its size, and the sign represents its direction 
  (positive means right, negative means left).
- Each asteroid moves at the same speed.
- When two asteroids collide, the smaller one will explode.
- If both are the same size, both explode.
- Two asteroids moving in the same direction will never collide.

Return the state of the asteroids after all collisions.

-------------------------------------------------------------
Approach:
- Use a stack to simulate the asteroid collisions.
- Iterate through each asteroid:
  1. If it's moving right (positive), push it to the stack.
  2. If it's moving left (negative), check for collisions with the stack top:
      - While the stack is not empty and top asteroid is moving right:
          * Compare absolute sizes.
          * Pop the smaller one.
          * If equal, pop both and mark destroyed.
  3. If not destroyed, push the asteroid.
- Finally, the stack contains the answer, reverse it to output.

-------------------------------------------------------------
Complexity:
- Time: O(n), since each asteroid is pushed and popped at most once.
- Space: O(n), for the stack.

*/


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int ast : asteroids){
            bool destroyed = false;

            while(!st.empty() && ast < 0 && st.top() > 0){
                if(abs(ast) > abs(st.top())){
                    st.pop();
                }
                else if(abs(ast) == abs(st.top())){
                    st.pop();
                    destroyed = true;
                    break;
                }
                else{
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed){
                st.push(ast);
            }
        }

        vector<int> ans(st.size());
        for(int i = st.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
