// Leetcode: 1614. Maximum Nesting Depth of the Parentheses
// Topic: Stack / String
// Time: O(n), Space: O(1)
// very easy compared to frequency sort

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxcount = 0;
        for(char c : s){
            if(c == '('){
                count++;
                maxcount = max(maxcount, count);
            } else if(c == ')'){
                count--;
            }
        }
        return maxcount;
    }
};
