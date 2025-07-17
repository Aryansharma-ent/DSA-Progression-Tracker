// Problem: Sort Characters By Frequency
// Link: https://leetcode.com/problems/sort-characters-by-frequency/


/*
Approach:
1. Count frequency of each character using an unordered_map.
2. Use a max-heap (priority_queue) to sort characters by their frequency.
- Each element in the heap is a pair: {frequency, character}.
3. Pop from the heap and append the character 'frequency' times to the result string.

Time Complexity:
- O(n log k), where n = length of the string and k = number of unique characters.
- O(n) to build the frequency map.
- O(k log k) to push all unique characters into the heap.
- O(n) to build the result string.

Space Complexity:
- O(k) for the frequency map and heap.
- O(n) for the result string.

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Max-heap based on frequency
        priority_queue<pair<int, char>> maxHeap;
        for (auto& [ch, count] : freq) {
            maxHeap.push({count, ch});
        }

        string result;
        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();
            result += string(count, ch);  // Add 'ch' repeated 'count' times
        }

        return result;
    }
};
