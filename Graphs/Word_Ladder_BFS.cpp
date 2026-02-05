#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 127: Word Ladder

Problem:
Given two words (beginWord and endWord), and a dictionary wordList,
return the length of the shortest transformation sequence from beginWord
to endWord such that:
- Only one letter can be changed at a time.
- Each transformed word must exist in wordList.

Approach (BFS on implicit graph):
- Each word is a node.
- An edge exists between two words if they differ by exactly one character.
- Since all edges have equal weight (1 step), BFS guarantees the shortest path.

Key Idea:
- Start BFS from beginWord.
- For each word, try changing every character ('a' to 'z') and check
  if the new word exists in the dictionary.
- Use an unordered_set for O(1) lookup and erase words once visited
  to avoid revisiting and cycles.

Why erase from set?
- Prevents revisiting the same word.
- Ensures each word is processed only once → optimal performance.

Time Complexity:
- O(N * L * 26)
  where N = number of words, L = word length

Space Complexity:
- O(N) for queue and set
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;   // {currentWord, steps}
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());

        // If beginWord exists in wordList, remove it to avoid revisiting
        if(st.find(beginWord) != st.end())
            st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If endWord reached, shortest path found
            if(word == endWord)
                return steps;

            // Try changing each character
            for(int i = 0; i < word.size(); i++){
                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;

                    if(st.find(word) != st.end()){
                        st.erase(word);              // mark visited
                        q.push({word, steps + 1});  // next level
                    }
                }

                word[i] = original;  // restore original character
            }
        }

        // If transformation not possible
        return 0;
    }
};
