// Extended Moore's Voting Algorithm
/*
Problem: Find all elements in the array that appear more than ⌊n/3⌋ times.
Approach: Extended Moore's Voting Algorithm
Time Complexity: O(N)
Space Complexity: O(1) auxiliary (excluding output vector)

At most 2 elements can appear more than n/3 times.
This implementation finds those two candidates and verifies them.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1;
                el1 = nums[i];
            } else if (cnt2 == 0 && nums[i] != el1) {
                cnt2 = 1;
                el2 = nums[i];
            } else if (nums[i] == el1) {
                cnt1++;
            } else if (nums[i] == el2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ls;
        int count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) count1++;
            if (nums[i] == el2) count2++;
        }

        if (count1 > n / 3) ls.push_back(el1);
        if (count2 > n / 3) ls.push_back(el2);

        sort(ls.begin(), ls.end());
        return ls;
    }
};
