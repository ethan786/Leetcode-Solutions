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
    
    int ans = INT_MIN;
    
    int solve(TreeNode* root) {
        if(!root) return 0;
        int ls = max(solve(root->left), 0);
        int rs = max(solve(root->right), 0);
        ans = max({ans,root->val + ls + rs});
        return max(ls,rs) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        solve(root);
        return ans;
    }
};