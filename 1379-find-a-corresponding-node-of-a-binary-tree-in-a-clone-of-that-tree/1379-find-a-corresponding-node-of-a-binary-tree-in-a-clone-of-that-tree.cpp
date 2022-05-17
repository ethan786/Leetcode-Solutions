/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void solve(TreeNode* &o, TreeNode* &c, TreeNode* &t){
        if(!c||!o) return;
        if(o == t){
            ans = c;
        }
        solve(o->left,c->left,t);
        solve(o->right,c->right,t);
    }
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t) {
        solve(o,c,t);
        return ans;
    }
};