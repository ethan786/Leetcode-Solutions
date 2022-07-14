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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        typedef pair<int,ListNode*> pp;
        priority_queue<pp,vector<pp>, greater<pp>> pq;
        for(auto &i : lists) {
            if(i != NULL)
            pq.push({i->val,i});
        }
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            temp->next = new ListNode(cur.first);
            temp = temp->next;
            if(cur.second->next) pq.push({cur.second->next->val,cur.second->next});
        }
        return ans->next;
    }
};