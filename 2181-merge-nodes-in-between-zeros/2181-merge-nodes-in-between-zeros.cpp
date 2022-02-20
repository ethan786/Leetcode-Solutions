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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* h = nullptr;
        ListNode* t = nullptr;
        
        while (head && head->next) {
            head = head->next;
            
            int sum = 0;
            while (head && head->val) {
                sum += head->val;
                head = head->next;
            }
            
            if (sum) {
                auto node = new ListNode(sum);
                if (!h) {
                    h = t = node;
                } else {
                    t->next = node;
                    t = node;
                }
            }
        }
        
        return h;
    }
};