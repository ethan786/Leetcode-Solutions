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

class node {
    public:
    int mini;
    int maxi;
    int sum;
    node(int a,int b, int c) {
        mini = a;
        maxi = b;
        sum = c;
    }
};

class Solution {
public:
    int ans = 0;
    node solve(TreeNode* root) {
        if(!root) {
            return node(INT_MAX,INT_MIN,0);
        }
        node l = solve(root->left);
        node r = solve(root->right);
        if(root->val > l.maxi and root->val < r.mini) {
            // its a valid bst
            ans = max(ans, root->val + l.sum + r.sum);
            // cout<<ans<<endl;
            return node(min(root->val,l.mini), max(root->val,r.maxi),(root->val + l.sum + r.sum));
        }
        return node(INT_MIN,INT_MAX,max(l.sum,r.sum));
    }
    
    int maxSumBST(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};