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
    
    TreeNode* solve(int &i, vector<int> &a, int bound) {
        if(i == a.size() || a[i] > bound) return NULL;
        TreeNode* node = new TreeNode(a[i++]);
        node->left = solve(i,a,node->val);
        node->right = solve(i,a,bound);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& a) {
        int i = 0;
        return solve(i,a,100000);
    }
    
};