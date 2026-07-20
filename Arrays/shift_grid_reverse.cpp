/*
LeetCode 1260 - Shift 2D Grid

Approach:
- Treat the 2D grid as a flattened 1D array of size (m * n).
- A right shift by k positions is equivalent to rotating the flattened array.
- Perform the rotation in-place using the three-reversal algorithm:
    1. Reverse the entire array.
    2. Reverse the first k elements.
    3. Reverse the remaining elements.
- Convert a 1D index back to 2D using:
      row = idx / n
      col = idx % n

Time Complexity: O(m * n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int size = m * n;
        k = k % size;

        if(k == 0) return grid;

       auto reverse = [&](int i,int j){
          while(i < j){
            swap(grid[i / n][i % n],grid[j / n][j % n]);
            i++;
            j--;
          }
       }; 

        reverse(0,size - 1);  
        reverse(0,k - 1);  
        reverse(k,size - 1);  
     
        return grid;
    }
};