/*
🧠 Approach:
- Used Floyd’s Cycle Detection Algorithm (Tortoise and Hare method).
- Once the loop is detected (when slow == fast), a temporary pointer is moved
  from the meeting point until it comes back to the same node to count the loop length.

📈 Time Complexity: O(N) — worst case when loop is at the end
📦 Space Complexity: O(1) — constant space
*/
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // Loop detected
            if (slow == fast) {
                int count = 1;
                Node* temp = slow->next;

                while (temp != slow) {
                    count++;
                    temp = temp->next;
                }

                return count;
            }
        }

        return 0; 
    }
};
