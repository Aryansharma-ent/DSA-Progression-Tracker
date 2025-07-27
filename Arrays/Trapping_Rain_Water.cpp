 /*Approach
Create two arrays:

leftMax[i]: maximum height to the left of or at index i.

rightMax[i]: maximum height to the right of or at index i.

Traverse from left to right to fill leftMax.

Traverse from right to left to fill rightMax.

For each index i, compute:
min(leftMax[i], rightMax[i]) - height[i]
and add to total water if it’s positive.

 Time Complexity
O(n) — three linear passes: one for leftMax, one for rightMax, and one final to calculate water.

 Space Complexity
O(n) — for the leftMax and rightMax arrays.
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        for(int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i-1], height[i]);

        rightMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1], height[i]);

        int water = 0;
        for(int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }
        return water;
    }
};