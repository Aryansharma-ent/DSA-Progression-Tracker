/*Problem: Isomorphic Strings (LeetCode 205)

Approach:  
Used two hash maps to ensure a one-to-one mapping between characters of string `s` and string `t`, and vice versa.  
For each character position, it checks:
- If a previous mapping exists and matches the current character
- If not, it returns false immediately  
Otherwise, it adds the new mapping.

Reflection:  
At first, it was hard to think of a brute force or pattern. But once I understood the idea of bi-directional mapping, it clicked. A strong question to improve reasoning around character patterns and hash maps.

Time Complexity: O(n)  
Space Complexity: O(1) (since only 26 lowercase characters are involved) */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){return false;}
        unordered_map<char,char> swali,twali ;

        for(int i = 0;i<s.size();i++){
            char sc = s[i];
            char tc = t[i];

            if(swali.count(sc) && swali[sc] != tc) return false;
            if(twali.count(tc) && twali[tc] != sc) return false;
            
            swali[sc] = tc;
            twali[tc] = sc;
        }
        return true;
    }
};