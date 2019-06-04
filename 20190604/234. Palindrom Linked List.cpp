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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        if (head -> next == NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next && fast -> next ->next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        fast = slow -> next;
        
        ListNode* prev = NULL;
        while(fast != NULL)
        {
            ListNode* tmp = fast -> next;
            fast -> next = prev;
            prev = fast;
            fast = tmp;
        }
        while(prev && head)
        {
            if (prev -> val != head -> val)
                return false;
            prev = prev -> next;
            head = head -> next;
        }
        return true;
            
        
    }
};