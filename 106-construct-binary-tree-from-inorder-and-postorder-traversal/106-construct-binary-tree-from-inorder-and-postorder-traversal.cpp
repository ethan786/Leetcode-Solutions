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
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int,int> &m) {
        if(inStart > inEnd || postStart > postEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inroot = m[postorder[postEnd]];
        int leftsize = inroot - inStart;
        root->left = solve(inorder, postorder, inStart, inroot-1, postStart, postStart+leftsize-1, m);
        root->right = solve(inorder, postorder, 1+inroot, inEnd, postStart+leftsize, postEnd-1, m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        return solve(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, m);
    }
}; 