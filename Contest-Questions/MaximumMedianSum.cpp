/*Approach:
Sort the array in non-decreasing order.

The array is to be split into n/3 triplets, and the median of each triplet is to be summed.

Since the medians will be the middle values when sorted, they lie at positions: n-2, n-4, ..., n/3 (moving in steps of 2).

Loop backwards from index n-2 down to n/3, skipping 1 element each time to pick the median of each triplet.

Accumulate these median values to get the final answer.

Time Complexity:
Sorting: O(n log n)

Loop: O(n) (worst case)

Overall: O(n log n)

 Space Complexity:
O(1) (if we ignore the sorting overhead)
*/
#include <bits/stdc++.h>   
using namespace std; 

class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum = 0;

        for(int i = n-2;i>=n/3;i -= 2){
            sum += nums[i];
        }
        return sum;
    }
};