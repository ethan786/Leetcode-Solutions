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
    
    TreeNode* solve(int s, int e, vector<int> &a) {
        if(s > e) return NULL;
        int m = (s+e) / 2;
        TreeNode* root = new TreeNode(a[m]);
        root->left = solve(s,m-1,a);
        root->right = solve(m+1,e,a);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& a) {
        return solve(0,a.size()-1, a);
    }
};