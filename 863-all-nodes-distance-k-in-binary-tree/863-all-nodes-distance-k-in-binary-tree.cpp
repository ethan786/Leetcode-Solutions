/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void fillParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &par) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left) {
                par[cur->left] = cur;
                q.push(cur->left);
            }
            if(cur->right) {
                par[cur->right] = cur;
                q.push(cur->right);
            }
        }
    } 
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> par;
        fillParent(root,par);
        
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int dis = 0;
        
        while(!q.empty()) {
            int n = size(q);
            if(dis++ == k) break;
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left and vis[node->left] == false) {
                    vis[node->left] = true;
                    q.push(node->left);
                }
                if(node->right and vis[node->right] == false) {
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if(par[node] and vis[par[node]] == false) {
                    vis[par[node]] = true;
                    q.push(par[node]);
                }
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
        
    }
};