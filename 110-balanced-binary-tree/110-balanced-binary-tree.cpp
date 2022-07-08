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
    
    
    pair<int,bool> solve(TreeNode* root) {
        if(!root) {
            return {0,true};
        }
        auto lh = solve(root->left);
        auto rh = solve(root->right);
        return {1+max(lh.first,rh.first) , abs(lh.first-rh.first) <= 1 && lh.second && rh.second};
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return solve(root).second;
    }
};