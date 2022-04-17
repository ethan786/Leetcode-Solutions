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
    
        TreeNode* temp;
    void solve(TreeNode* root,TreeNode* &ans){
        if(!root) return;
        solve(root->left,ans);
        
        if(!ans){
            ans = new TreeNode(root->val);
            temp = ans;
        }else{
            cout<<ans->val;
            ans->right = new TreeNode(root->val);
            ans = ans->right;
        }
        
        solve(root->right,ans);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        TreeNode* ans = NULL;
        solve(root,ans);
        return temp;
    }
};