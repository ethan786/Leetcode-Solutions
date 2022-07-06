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
        if(!root) return 0;
        
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        
        while(!q.empty()) {
            int n = q.size();
            int mini = q.front().second; // to make start from 0;
            int first,last;
            for(int i = 0; i < n; i++) {
                int cur_id = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();
                cout<<cur_id<<" "<<n<<" "<<mini<<endl;
                if(i == 0) first = cur_id;
                if(i == n-1) last = cur_id;
                if(node->left) q.push({node->left, 2*cur_id+1});
                if(node->right) q.push({node->right, 2*cur_id+2});
            }
            ans = max(ans,last - first + 1);
        }
        #undef int
        return ans;
    }

};