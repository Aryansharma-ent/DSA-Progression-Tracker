/*
LeetCode 904. Fruit Into Baskets

Problem:
You are given an array of integers 'fruits', where each element represents a tree producing one type of fruit. 
You want to collect fruits in two baskets such that each basket can only hold one type of fruit. 
Return the length of the longest subarray containing at most two distinct numbers.

Approach:
- Use the sliding window technique with two pointers (l and r).
- Maintain a frequency map 'basket' to track counts of fruit types within the window.
- Expand the right pointer to add fruits.
- If the number of distinct fruits exceeds 2, shrink the window from the left until only 2 distinct fruits remain.
- Track the maximum valid window length during traversal.

Complexity:
- Time Complexity: O(n), since each element is added/removed from the window at most once.
- Space Complexity: O(1), as the map stores at most 2 distinct fruit types.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0, maxlen = 0;
        unordered_map<int,int> basket;

        while(r < n){
            basket[fruits[r]]++;

            while(basket.size() > 2){
                basket[fruits[l]]--;
                if(basket[fruits[l]] == 0){
                    basket.erase(fruits[l]);
                }
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
