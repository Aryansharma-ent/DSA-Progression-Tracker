/*
Problem: Minimum Coins (Greedy for Canonical Coin Systems)
----------------------------------------------------------
Given an array of coin denominations and a target sum, find the minimum number of coins 
needed to make the sum. If it is impossible to make the exact sum, return -1.

Note: This greedy approach works only for **canonical coin systems** like Indian/US currency.

Approach (Greedy):
1. Sort the coins in descending order.
2. Initialize `dsum = 0` and `count = 0`.
3. For each coin:
   - While adding the coin does not exceed `sum`, add it:
       - `dsum += coin`
       - `count++`
4. After processing all coins:
   - If `dsum == sum`, return `count`.
   - Else return -1 (cannot form sum).

Example:
coins = [1, 2, 5, 10, 20, 50, 100], sum = 93
- Take 50 → sum left 43, count 1
- Take 20 → sum left 23, count 2
- Take 20 → sum left 3, count 3
- Take 2 → sum left 1, count 4
- Take 1 → sum left 0, count 5
Answer = 5 coins ✅

Complexity:
- Time: O(n log n + sum/coin_min) ≈ O(n log n) (sorting dominates)
- Space: O(1)

Code:
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int MinimumCoins(vector<int>& coins, int sum) {
        if(sum == 0) return 0;
        int dsum = 0;
        int count = 0;

        // Sort coins descending
        sort(coins.rbegin(), coins.rend());

        for(int i = 0; i < coins.size(); i++){
            if(coins[i] > sum) continue;

            while(dsum + coins[i] <= sum){
                dsum += coins[i];
                count++;
            }
        }

        return (dsum == sum) ? count : -1;
    }
};
