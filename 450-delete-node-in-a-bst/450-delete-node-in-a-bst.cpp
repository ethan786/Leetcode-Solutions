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
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key) {
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root) {
            if(root->val > key) {
                if(root->left and root->left->val == key) {
                    root->left = helper(root->left);
                }else {
                    root = root->left;
                }
            }else {
                if(root->right and root->right->val == key) {
                    root->right = helper(root->right);
                }else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
    
    TreeNode* helper(TreeNode* root) {
        if(!root->left) {
            return root->right;
        }else if(!root->right){
            return root->left;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        TreeNode* extremeRight = findLast(left);
        extremeRight->right = right;
        return root->left;
    }
    
    TreeNode* findLast(TreeNode* root) {
        while(root->right) {
            root = root->right;
        }
        return root;
    }
};