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
    int minCameraCover(TreeNode* root) 
    {
        int cam = 0;
        int miniCam = cover(root, cam);
        
        if(miniCam==0) //need to install a cam here
            cam++;
        
        return cam;
    }
    
    int cover(TreeNode* root, int &cam)
    {
        if(root==NULL) return 1; //This is not a node so it doesn't need a cam
        
        //we go at the bottom of the tree i.e. at leaf nodes
        int left = cover(root->left, cam); 
        int right = cover(root->right, cam);
        
        //While returning to the top we check which node needs cam
        if(left==0 || right==0) //Node's child want cam so we install cam here 
        {
            cam++;
            return 2;
        }
        
        else if(left==2 || right==2) //Cam installed at node's child, so node doesn't need a cam
            return 1;
        
        //for (left==1 || right==1) condition, children doesn't need a cam but parents have
        return 0; 
    }
};