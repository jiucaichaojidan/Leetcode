// 链表实现整数相加， 数是逆序存在链表中的
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        int add = 0;
        while(l1 && l2)
        {
            p -> next = new ListNode(0);
            p = p -> next;
            p -> val = (add + l1 -> val + l2 -> val) % 10;
            add =  (add + l1 -> val + l2 -> val) / 10;
            l1 = l1 -> next;
            l2 = l2 -> next;          
        }
        while(l1)
        {
            p -> next = new ListNode(0);
            p = p -> next;
            p -> val = (add + l1 -> val) % 10;
            add =  (add + l1 -> val) / 10;
            l1 = l1 -> next;
        }
        while(l2)
        {
            p -> next = new ListNode(0);
            p = p -> next;
            p -> val = (add + l2 -> val) % 10;
            add =  (add + l2 -> val) / 10;
            l2 = l2 -> next;
        }
        if(add) p -> next = new ListNode(1);
        return head -> next;
        
        
    }
};