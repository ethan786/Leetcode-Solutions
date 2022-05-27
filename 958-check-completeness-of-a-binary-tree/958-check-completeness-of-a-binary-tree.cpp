// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
    
//     int depth(TreeNode* root) {
//         if(!root) return 0;
//         return 1 + max(depth(root->left),depth(root->right));
//     } 
    
//     bool isCompleteTree(TreeNode* root) {
//         int d = depth(root);
//         if(d == 1) return true;
//         queue<TreeNode*> q;
//         q.push(root);
//         int level = 0;
//         while(level+2 != d) {
//             int n = q.size();
            
//             if(level != 0) 
//                 if(n != pow(2,level)) return false;
            
//             // cout<<n<<" "<<pow(2,level)<<endl;
            
//             for(int i=0;i<n;i++) {
//                 auto node = q.front();
//                 q.pop();
//                 if(node->left)
//                     q.push(node->left);
//                 if(node->right)
//                     q.push(node->right);
//             }
//             level++;
//         }
//         // cout<<d<<" "<<level<<endl;
//         if(q.size() != pow(2,level)) return false;
//         bool flag = (q.front()->left != NULL);
//         // cout<<q.size()<<endl;
// //         while(!q.empty()) {
// //             cout<<q.front()->val<<endl;
// //             q.pop();
// //         }
        
// //         return false;
        
//         while(!q.empty()) {
//             auto node = q.front();
//             q.pop();
            
//             if((node->left and node->right and flag) || (node->left and flag) || (!node->left and !node->right)) {
//                 if(!node->right) {
//                     flag = false;
//                 }
//             }else {
//                 return false;
//             }
            
//         }
//         return true;
//     }
// };



class Solution{
    public:
    bool isCompleteTree(TreeNode* root) {
        bool value = false;
        if(root==NULL)
            return true;
        queue<TreeNode *> q;
        q.push(root);
        int c = 0;
        while(q.size()>0)
        {
            TreeNode *p = q.front();
            q.pop();
            if(p==NULL)
            {
                // c++;
                value=true;
            }
            else
            {
                if(value)
                    return false;
                q.push(p->left);
                q.push(p->right);
            }
        }
        cout<<c;
        return true;
    }
};