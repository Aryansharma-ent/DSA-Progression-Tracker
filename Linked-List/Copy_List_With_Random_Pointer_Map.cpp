// Definition for a Node.
/*
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

/*
Problem: Copy List with Random Pointer

Intuition:
Each node in the linked list has two pointers: next and random.
While copying the list, the main challenge is correctly assigning
the random pointers in the copied list.

To solve this, we can use a hash map that maps each original node
to its corresponding copied node. This allows us to easily connect
both next and random pointers in the copied list.

Approach:
1. Traverse the original list and create a copy of each node.
   - Store a mapping from original node -> copied node in a hash map.
2. Traverse the original list again:
   - For each original node, set:
     - copiedNode->next = copy of original->next
     - copiedNode->random = copy of original->random
   - The hash map helps retrieve the copied nodes in O(1) time.
3. Return the copied head node.

Why this works:
- Each original node is copied exactly once.
- The hash map ensures correct pointer assignments without losing references.
- Handles NULL random and next pointers naturally.

Time Complexity:
O(n), where n is the number of nodes in the list.

Space Complexity:
O(n), due to the extra hash map storing node mappings.
*/


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        unordered_map<Node*, Node*> mpp;
        Node* temp = head;

        // Step 1: Create copy of each node and store mapping
        while(temp != nullptr){
            Node* newNode = new Node(temp->val);
            mpp[temp] = newNode;
            temp = temp->next;
        }

        // Step 2: Assign next and random pointers
        temp = head;
        while(temp != nullptr){
            Node* copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];       // handles NULL automatically
            copyNode->random = mpp[temp->random];  // handles NULL automatically
            temp = temp->next;
        }

        // Step 3: Return copied head
        return mpp[head];
    }
};
