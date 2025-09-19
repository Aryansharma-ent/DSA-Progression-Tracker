/*
File Name: max_meetings.cpp

Problem:
Given two arrays start[] and end[] of equal size, where start[i] and end[i] denote
the start and end times of the i-th meeting, find the maximum number of meetings
that can be performed in a meeting room without overlaps.

Approach:
- Pair up meetings as {end, start}.
- Sort all meetings by end time (earliest finishing meeting first).
- Use a greedy strategy:
  - Always select the meeting that finishes first and does not overlap with the previously selected meeting.
- Count how many such meetings can be held.

Time Complexity: O(N log N)  // due to sorting
Space Complexity: O(N)       // for storing meeting pairs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
       vector<pair<int,int>> meetings;
       for(int i = 0;i<start.size();i++){
           meetings.push_back({end[i],start[i]});
       }
       
       sort(meetings.begin(),meetings.end());
       
       int freetime = meetings[0].first;
       int cnt = 1;
       
       for(int i = 1; i < start.size(); i++){
           if(meetings[i].second > freetime){
               cnt++;
               freetime = meetings[i].first;
           }
       }
       return cnt;
    }
};

/*
Sample Input:
start = [1, 3, 0, 5, 8, 5]
end   = [2, 4, 6, 7, 9, 9]

Sample Output:
4
Explanation: Meetings can be held at [1,2], [3,4], [5,7], [8,9].
*/
