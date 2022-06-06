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
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode* ta = a, *tb = b;
        if(ta == tb) {
            return ta;
        }
        while(ta and tb and ta != tb) {
            ta = ta->next;
            tb = tb->next;
            if(ta == tb) {
                return ta;
            }
            if(!ta) ta = b;
            if(!tb) tb = a;
        }
        return ta;
    }
};