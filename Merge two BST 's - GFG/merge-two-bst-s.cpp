// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



 // } Driver Code Ends

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    void inorder(Node *root, vector<int> &ans)
    {
        if(root==NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    Node *minValueNode(Node *nod)
    {
        Node *current = nod;
        while(current->left !=NULL)
            current = current->left;
        return current;
    }
    
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1,Node *root2)
    {
        //using two stacks s1 and s2 to store nodes of both BST separately.
        stack<Node *> s1;
        stack<Node *> s2;
        Node *c1 = root1;
        Node *c2 = root2;
    
        vector<int> ans;
        
        
        if(root1==NULL)
        {
            inorder(root2, ans);
            return ans;
        }
       
        if(root2==NULL)
        {
            inorder(root1, ans);
            return ans;
        }
        
       
        while(c1!=NULL or !s1.empty() or c2!=NULL or !s2.empty())
        {
          
            if(c1!=NULL or c2!=NULL)
            {

                if(c1!=NULL){
                    s1.push(c1);
                    c1 = c1->left;
                }
                if(c2!=NULL){
                    s2.push(c2);
                    c2 = c2->left;
                }
            }
            
            else 
            {
                
                if(s1.empty())
                {
                    while(!s2.empty())
                    {
                        c2  = s2.top();
                        s2.pop();
                        c2->left= NULL;
                        inorder(c2, ans);
                    }
                    return ans;
                }
                if(s2.empty())
                {
                    while(!s1.empty())
                    {
                        c1  = s1.top();
                        s1.pop();
                        c1->left = NULL;
                        inorder(c1, ans);
                    }
                    return ans;
                }
                
                c1 = s1.top();
                c2  = s2.top();
                s1.pop();
                s2.pop();
                
                
                if(c1->data < c2->data)
                {
                    ans.push_back(c1->data);
                    c1 = c1->right;
                    s2.push(c2);
                    c2 = NULL;
                }
                
                else
                {
                    ans.push_back(c2->data);
                    c2 = c2->right;
                    s1.push(c1);
                    c1 = NULL;
                }
            }
        }
        //returning the output list.
        return ans;
    }

};

// { Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}  // } Driver Code Ends