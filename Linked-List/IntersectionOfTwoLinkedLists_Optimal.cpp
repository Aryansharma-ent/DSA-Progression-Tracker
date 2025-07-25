/* Two Pointer Technique

Initialize two pointers a and b at headA and headB.

Move each one step at a time.

When a pointer reaches the end, redirect it to the head of the other list.

Eventually, either they will meet at the intersection node or both reach nullptr.


Time Complexity:
O(m + n) where m and n are lengths of the two linked lists.

Space Complexity:
O(1) (constant space, no extra memory used)
*/

#include <bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};
