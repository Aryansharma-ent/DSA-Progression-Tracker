/*
    Problem: Sort a k-sorted (nearly sorted) array

    Approach:
    - Use a min-heap (priority queue) of size k+1.
    - Push first k+1 elements into the heap.
    - For each remaining element:
        - Pop the smallest element from the heap and place it in the array.
        - Push the next array element into the heap.
    - After processing all elements, pop and place the remaining heap elements.

    Example:
    Input: arr = [6, 5, 3, 2, 8, 10, 9], k = 3
    Output: [2, 3, 5, 6, 8, 9, 10]

    Time Complexity: O(n log k)
        - Each insertion/deletion in heap takes O(log k).
        - We perform it for n elements.

    Space Complexity: O(k)
        - Heap stores at most k+1 elements.

    DSA Sheet Position: Heaps → Applications → Sort a k-sorted array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
      priority_queue<int, vector<int>, greater<int>> mh;
      int n = arr.size();
      
      // Push first k+1 elements
      for(int i = 0; i <= k && i < n; i++) {
          mh.push(arr[i]);
      }
      
      int index = 0;
      // Process remaining elements
      for(int i = k+1; i < n; i++) {
          arr[index++] = mh.top();
          mh.pop();
          mh.push(arr[i]);
      }
      
      // Empty remaining elements from heap
      while(!mh.empty()) {
          arr[index++] = mh.top();
          mh.pop();
      }
    }
};
