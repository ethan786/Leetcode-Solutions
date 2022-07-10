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
    
    TreeNode* now(TreeNode* root, int key) {
        if(root->left == NULL) {
            return root->right;
        }else if(root->right == NULL) {
            return root->left;
        }
        
        TreeNode* r = root->right;
        TreeNode* l = root->left;
        // cout<<l->val<<" "<<r->val<<endl;
        while(l->right) {
            l = l->right;
        }
        
        l->right = r;
        root->right = NULL;
        return root->left;
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key) {
            return now(root,key);
        }
        TreeNode* temp = root;
        while(temp) {
            if(temp->val > key) {
                if(temp->left and temp->left->val == key) {
                    temp->left = now(temp->left, key);
                }else {
                    temp = temp->left;
                }
            }else {
                if(temp->right and temp->right->val == key) {
                    temp->right = now(temp->right, key);
                }else {
                    temp = temp->right;
                }
            }
        }
        return root;
    } 
};