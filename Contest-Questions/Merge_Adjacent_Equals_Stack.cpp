#include <bits/stdc++.h>
using namespace std;

/*
Problem (as implemented):
Given an array nums, repeatedly merge adjacent equal values:
- When two adjacent numbers are equal, replace them with their sum (i.e., double the value).
- This merge can cascade (like 2,2,4,4 -> 4,8 -> 16 depending on order).

Intuition:
This is similar to "merge like 2048":
- While scanning left to right, if the current value equals the last value we kept,
  they should merge into one doubled value.
- After merging once, it might again become equal to the new previous value,
  so we keep merging (cascading merges).

Approach (Stack):
- Use a stack to maintain the current merged sequence.
- For each element:
    1) Set sum = nums[i]
    2) If stack top equals sum, merge (sum *= 2) and pop
    3) Keep merging while the new sum equals the new stack top (cascade)
    4) Push final sum back into stack
- Finally, pop stack into a vector and reverse to restore original order.

Time Complexity:
O(n) average/overall, because each element is pushed/popped at most a few times
(total pops across the whole run ≤ total pushes).

Space Complexity:
O(n) for the stack / output.
*/

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;

        for(int i = 0; i < (int)nums.size(); i++){
            long long sum = nums[i];

            // If top equals current, merge and handle cascading merges
            if(!st.empty() && st.top() == sum){
                st.pop();
                sum *= 2;

                while(!st.empty() && st.top() == sum){
                    st.pop();
                    sum *= 2;
                }
            }

            st.push(sum);
        }

        // Build answer from stack (reverse order)
        vector<long long> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};
