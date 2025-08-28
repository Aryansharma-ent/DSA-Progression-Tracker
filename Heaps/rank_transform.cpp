// File: rank_transform.cpp
//
// Problem: Rank Transform of an Array (LeetCode 1331)
// Difficulty: Easy
// 
// Approach:
// 1. Copy the original array and sort it.
// 2. Use a hash map to assign ranks to unique numbers in the sorted array.
// 3. Replace each element in the original array with its corresponding rank.
//
// Why it works:
// - Sorting helps us order numbers.
// - A hash map ensures quick lookups for assigning ranks to each number.
// - This way, duplicates get the same rank, and all numbers are transformed correctly.
//
// Time Complexity: O(n log n)
//   - Sorting: O(n log n)
//   - Hash map creation: O(n)
//   - Final replacement: O(n)
//   -> Overall: O(n log n)
//
// Space Complexity: O(n)
//   - Copy of array for sorting
//   - Hash map for ranks
//
// This is the optimal solution because sorting is unavoidable for rank ordering.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        int currRank = 1;
        for (int num : sorted) {
            if (rank.find(num) == rank.end()) {
                rank[num] = currRank++;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};
