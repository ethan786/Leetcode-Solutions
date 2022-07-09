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
        //leaf node , one child , two child
        if(root == NULL){
            return NULL;
        }
        
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }else{
            //is leaf node
            if(root->left == NULL and root->right == NULL){
                delete root;
                return NULL;//good practise
            }else if(root->left == NULL){//for one child
                TreeNode* temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }else if(root->right == NULL){//for one child
                TreeNode* temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }else{//for two child
                TreeNode* mini = root->right;
                while(mini->left){ // find replacement and delete using recursion
                    mini = mini->left;
                }
                root->val = mini->val;
                root->right = deleteNode(root->right,mini->val);
                return root;
            }   
        }
        
        return root;
        
    }
};