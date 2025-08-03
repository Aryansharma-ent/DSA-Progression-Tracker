// 🔍 Approach:
// 1. Store all elements in an unordered_set for O(1) average lookups.
// 2. Iterate through each element in the set.
// 3. Only start counting a sequence if the current number is the start (i.e., num - 1 not in the set).
// 4. Count the length of the sequence by checking num + 1, num + 2, ... until the end.
// 5. Keep updating the longest length found.

// ⏱️ Time Complexity: O(n), where n is the number of elements in the array
//     - Insertion and lookup in unordered_set is O(1) on average.
//     - Each number is processed only once.
// 🧠 Space Complexity: O(n) for the unordered_set.


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 1;
       
        int n = nums.size();
        if(n==0) return 0;

        unordered_set<int> mp;
        for(int i = 0;i<n;i++){
            mp.insert(nums[i]);
        }

        for(auto &it : mp){
            if(mp.find(it-1) == mp.end()){
                int cnt = 1;
                int x = it;
                while(mp.find(x+1) != mp.end()){
                    x = x+1;
                    cnt++;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};
