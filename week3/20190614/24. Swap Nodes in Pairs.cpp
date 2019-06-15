// Given a linked list, swap every two adjacent nodes and return its head.

// You may not modify the values in the list's nodes, only nodes itself may be changed.

 

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        
        ListNode *prev = new ListNode(0);
        prev -> next = head;
        ListNode *res = prev; 
        
        while(prev -> next != NULL && prev -> next -> next != NULL)
        {
            ListNode* p1 = prev -> next;
            ListNode* p2 = prev -> next -> next;
               
            p1 -> next = p2 -> next;
            prev -> next = p2;
            p2 -> next = p1; 
            prev = p1;
        }
        return res -> next;
    }
 
};