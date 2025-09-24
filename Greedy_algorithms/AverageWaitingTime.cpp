/*
Approach:
---------
1. The problem is to calculate the average waiting time for processes (jobs) given their burst times.
2. Sort the burst times (bt) in ascending order to minimize the average waiting time.
   - This is because executing smaller burst times first reduces overall waiting time (Shortest Job First principle).
3. Traverse through the sorted burst times:
   - Maintain a cumulative sum (waiting time so far).
   - Add this cumulative sum to the total waiting time for all processes (except the last one since it doesn’t wait).
4. Finally, divide the total waiting time by the number of processes to get the average waiting time.

Complexity Analysis:
--------------------
- Sorting: O(n log n)
- Loop for calculating waiting times: O(n)
- Overall Time Complexity: O(n log n)
- Space Complexity: O(1) (ignoring input storage)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        int n = bt.size();
        long long sum = 0;
        long long realsum = 0;

        for (int i = 0; i < n - 1; i++) {
            sum += bt[i];
            realsum += sum;
        }

        long long avg = realsum / n;
        return avg;
    }
};
