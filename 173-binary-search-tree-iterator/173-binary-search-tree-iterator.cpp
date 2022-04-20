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
class BSTIterator {
    stack<TreeNode*> s;
    public:
    BSTIterator(TreeNode* root) {
        fill(root);
    }
    
    void fill(TreeNode* root){
        TreeNode* temp = root;
        while(temp){
            s.push(temp);
            temp=temp->left;
        }
    }
    
    int next() {
        TreeNode* front = s.top();
        s.pop();
        fill(front->right);
        return front->val;
    }
    
    bool hasNext() {
        bool ans = true;
        s.size()==0 ? ans = false:ans = true;
        return ans;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */