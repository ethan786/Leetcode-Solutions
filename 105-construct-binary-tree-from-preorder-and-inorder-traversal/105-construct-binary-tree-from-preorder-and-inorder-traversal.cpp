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
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int k;
        for(int i = inStart; i <= inEnd; i++) {
            if(inorder[i] == preorder[preStart]) {
                k = i; 
                break;
            }
        }
        root->left = solve(preorder,inorder,preStart+1,preStart+k-inStart,inStart,k-1);
        root->right = solve(preorder,inorder,preStart+1+k-inStart,preEnd,k+1,inEnd);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};