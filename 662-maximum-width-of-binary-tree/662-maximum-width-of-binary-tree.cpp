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
    int widthOfBinaryTree(TreeNode* root) {
        #define int int64_t
        int ans = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        int first = 0, last = 0;
        while(!q.empty()) {
            int min = first;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto x = q.front();
                q.pop();
                TreeNode* node = x.first;
                int ind = x.second;
                if(i == 0) first = ind;
                else if(i == sz-1) last = ind;
                if(node->left) q.push({node->left, 2*ind + 1 - min});
                if(node->right) q.push({node->right, 2*ind + 2 - min});
            }
            // cout<<first<<" "<<last<<endl;
            ans = max(ans, last - first + 1);
        }
        #undef int
        return ans;
    }

};