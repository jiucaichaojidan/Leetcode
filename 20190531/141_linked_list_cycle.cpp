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
    bool hasCycle(ListNode *head) {
        if (!head) return 0;
        ListNode* p = head;
        ListNode* q = head;
        while( p && q -> next)
        {
            if (!q -> next -> next) break;  // 若链表长度为2， q -> next -> next为空，while的地方就会出问题
            p = p -> next;
            q = q -> next -> next;
            if (p == q) return true;
        }
        return false;
    }
};