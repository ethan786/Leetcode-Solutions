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
    vector<double> v;
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            int x = 0;
            double sum = 0;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                sum+=node->val;
            }
            v.push_back(sum/n);
        }
        return v;
    }
};