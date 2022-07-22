/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(-1);
        ListNode* more = new ListNode(-2);
        ListNode* less_pointer = less;
        ListNode* more_pointer = more;
        
        while(head) {
            if(head->val >= x) {
                more_pointer->next = new ListNode(head->val);
                more_pointer = more_pointer->next;
            }else {
                less_pointer->next = new ListNode(head->val);
                less_pointer = less_pointer->next;
            }
            head = head->next;
        }
        less_pointer->next = more->next;
        return less->next;
    }
};