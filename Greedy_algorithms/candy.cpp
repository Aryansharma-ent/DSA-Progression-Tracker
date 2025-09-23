/*
    Problem: LeetCode 135 - Candy (Hard)

    Approach:
    - Use a greedy two-pass method:
      1. Left → Right pass: If ratings[i] > ratings[i-1], 
         give candies[i] = candies[i-1] + 1.
      2. Right → Left pass: If ratings[i] > ratings[i+1],
         update candies[i] = max(candies[i], candies[i+1] + 1).
    - This ensures that every child with a higher rating than a neighbor
      gets more candies while minimizing the total.

    Complexity:
    - Time: O(n)   (two passes + summation)
    - Space: O(n)  (array to store candies)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Left -> Right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right -> Left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Total candies
        int total = 0;
        for (int c : candies) total += c;
        return total;
    }
};
