// LeetCode: https://leetcode.com/problems/rotate-string/
// Problem: Given two strings s and goal, return true if and only if s can become goal after some number of shifts.
// A shift means removing the first character of s and appending it to the end.

// Optimal Solution - O(n^2){brute} O(n){optimal} Time
// Idea: If goal is a substring of s + s, it's a valid rotation.
// it was quite easy with the brute force solution but i guess ihave to work on my optimzations more

#include<bits/stdc++.h>
using namespace std;

// Brute force solution and my initial approach


class Solution
{
public:
    bool rotateString(string s, string goal)
    {

        if (s.size() != goal.size())
            return false;
        bool ans = false;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s.front();
            s.erase(0, 1); // remove first character

            // Push back
            s.push_back(ch);

            if (s == goal)
            {
                return ans = true;
                break;
            }
        }

        return ans;
    }
};




//optimal approach 
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};
