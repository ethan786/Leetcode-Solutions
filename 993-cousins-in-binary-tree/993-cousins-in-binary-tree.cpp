/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y) return false;
        queue<TreeNode*> q;
        q.push(root);
        bool flagx = false, flagy = false;
        int parx = -1, pary = -1;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                auto node = q.front();q.pop();
                if(node->left and node->left->val == x) {
                    flagx = true;
                    parx = node->val;
                }
                if(node->right and node->right->val == x) {
                    flagx = true;
                    parx = node->val;
                }
                if(node->left and node->left->val == y) {
                    flagy = true;
                    pary = node->val;
                }
                if(node->right and node->right->val == y) {
                    flagy = true;
                    pary = node->val;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flagx and flagy) {
                if(parx != pary) return true;
                else return false;
            }else if(flagx || flagy) {
                return false;
            }
        }
        return false;
    }
};