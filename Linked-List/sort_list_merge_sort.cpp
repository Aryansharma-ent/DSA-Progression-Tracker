/*
Leetcode Problem: 148. Sort List
Approach: Merge Sort on Linked List

1. Use fast and slow pointer to find the middle node.
2. Recursively divide the list into two halves until base case is reached.
3. Merge the sorted halves using a dummy node.

Time Complexity: O(n log n)
    - Finding the middle takes O(log n) divisions
    - Merging takes O(n) at each level
Space Complexity: O(log n) for recursion stack (no extra list creation)

It was a really hard question for me, I had to look at the solution to understand the merge sort on linked list as well as
merging sorted linked lists.
*/


 #include<bits/stdc++.h>
using namespace std;

 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:

ListNode* FindMiddle(ListNode *head){
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


    ListNode* MergeSortList(ListNode* list1,ListNode* list2) {
ListNode* dummy = new ListNode(-1);
ListNode* temp = dummy;
ListNode* t1 = list1;
ListNode* t2 = list2;

while(t1 != NULL && t2 != NULL){
    if(t1->val < t2->val){
        temp->next = t1;
        temp = t1;
        t1 = t1->next;
    }
     else{   temp->next = t2;
        temp = t2;
        t2 = t2->next;
     }
}
if(t1) temp->next = t1;
else temp->next = t2;

return dummy->next;
    }


    ListNode* sortList(ListNode *head) {
if(head == NULL || head->next == NULL){
    return head;
}

        ListNode* mid = FindMiddle(head);
        ListNode* right = mid->next;
        mid->next = NULL;
        ListNode* left = head;

 left = sortList(left);
 right = sortList(right);

return MergeSortList(left,right);
    }
};