


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  
        data = x;  
        next = NULL; 
    }
};


class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        int count = 0;
        Node* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
};
