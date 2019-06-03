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
    ListNode* reverseList(ListNode* head) {
        
        if(!head) return NULL;
        
        ListNode* p = head;
        ListNode* prev = NULL;
        
        while(p != NULL)
        {
            ListNode* tmp = p -> next;
            p -> next = prev;
            prev = p;
            p = tmp;
        }
        return prev;
    }
};
