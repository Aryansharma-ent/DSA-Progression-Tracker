/*
    Problem: Leaders in an Array (GFG)
    Link: https://www.geeksforgeeks.org/leaders-in-an-array/

    ✅ Approach:
    - Traverse from the end of the array.
    - Keep track of the maximum seen so far.
    - Any element greater than or equal to the current maximum is a leader.
    - Append it to the result and update the maximum.
    - Reverse the result at the end since we collected leaders from right to left.

    ✅ Time Complexity: O(n)
    ✅ Space Complexity: O(n) — to store the output list
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int max = INT_MIN;
        int n = arr.size();

        for(int i = n - 1; i >= 0; i--) {
            if(arr[i] >= max) {
                ans.push_back(arr[i]);
                max = arr[i];
            }      
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
