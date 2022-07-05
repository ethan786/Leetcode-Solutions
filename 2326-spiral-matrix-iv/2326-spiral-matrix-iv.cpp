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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        
        int l = 0, r = n-1, t = 0, b = m-1;
        
        ListNode* temp = head;
        
        while(l <= r and t <= b and temp != NULL) {
            for(int i = l; i <= r; i++) {
                if(temp == NULL) return ans;
                ans[t][i] = temp->val;
                temp = temp->next;
            }
            t++;
            // cout<<t<<b<<endl;
            for(int i = t; i <= b; i++) {
                // cout<<i<<" "<<temp->val<<endl;
                if(temp == NULL) return ans;
                ans[i][r] = temp->val;
                temp = temp->next;
            }
            r--;
            // cout<<l<<r<<t<<b<<endl;
            for(int i = r; i >= l; i--) {
                if(temp == NULL) return ans;
                ans[b][i] = temp->val;
                temp = temp->next;
            }
            b--;
            for(int i = b; i >= t; i--) {
                if(temp == NULL) return ans;
                ans[i][l] = temp->val;
                temp = temp->next;
            }
            l++;
        }
        return ans;
    }
};