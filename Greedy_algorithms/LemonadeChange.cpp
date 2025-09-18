/*
Approach:
- Use two counters to track the number of $5 and $10 bills.
- For each bill:
  - If bill is $5 → just increment fivebills.
  - If bill is $10 → check if a $5 is available for change. If yes, decrement fivebills and increment tenbills, else return false.
  - If bill is $20:
      - Prefer to give one $10 + one $5 as change (to save $5 bills for later).
      - If not possible, try giving three $5 bills.
      - If neither possible, return false.
- If we finish iterating, return true.

Complexity:
- Time Complexity: O(n), where n is the number of customers.
- Space Complexity: O(1), since only counters are used.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivebills = 0;
        int tenbills = 0;

        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                fivebills++;
            }
            else if(bills[i] == 10) {
                if(fivebills > 0) {
                    fivebills--;
                    tenbills++;
                } else {
                    return false;
                }
            }
            else if(bills[i] == 20) {
                if(tenbills > 0 && fivebills > 0) {
                    tenbills--;
                    fivebills--;
                } 
                else if(fivebills >= 3) {
                    fivebills -= 3;
                } 
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
