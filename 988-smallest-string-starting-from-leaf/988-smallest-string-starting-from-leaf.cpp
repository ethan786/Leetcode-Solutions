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
    vector<string> ans;
    
    void solve(TreeNode* root, string s) {
        if(!root) return;
        s += root->val + 97;
        if(!root->left and !root->right) {
            reverse(begin(s),end(s));
            ans.push_back(s);
            return;
        }
        solve(root->left,s);
        solve(root->right,s);
        s.pop_back(); 
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return " ";
        string s;
        solve(root,s);
        sort(begin(ans),end(ans));
        return ans[0];
    }
};