// Given a linked list, remove the n-th node from the end of list and return its head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:

// Given n will always be valid.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //遍历一次
        if(!head) return NULL;
        if(!n) return head;
        ListNode *p1 = head, *p2 = head;
        
        for(int i = 0; i < n; i++)
        {
            p2 = p2 -> next;
        }
        if(!p2)
        {
            head = head -> next;
            return head;
        }
        
        while(p2 -> next != NULL)
        {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        p1 -> next = p1 -> next -> next;
        return head;

        //遍历两次
        // if(!head) return NULL;
        // ListNode *p = head;
        // int i = 0;
        // while(p != NULL)
        // {
        //     i++;
        //     p = p -> next;
        // }
       
        // if(i - n == 0) 
        // {
        //     head = head -> next; 
        //     return head;
        // }
        
        // p = head;
        // for(int j = 1; j < i - n; j++)
        // {
        //     p = p -> next;            
        // }
        // p -> next = p-> next -> next;
        // return head;
        
    }
};
