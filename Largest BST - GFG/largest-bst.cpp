// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

struct dummy {
        int size;
        int largest; 
        int smallest;
    
    dummy(int a, int b, int c) {
        size = a;
        largest = b;
        smallest = c;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    dummy *f(Node *root) {
        if(!root) {
            return new dummy(0, INT_MIN, INT_MAX);
        }
        if(!root->left && !root->right) {
            return new dummy(1, root->data, root->data);
        }
        
        dummy *l = f(root->left);
        dummy *r = f(root->right);
        
        if(l->largest<root->data && root->data<r->smallest) {
            return new dummy(1+l->size+r->size, max(root->data, r->largest), min(root->data, l->smallest));
        }
        
        int s = max(l->size, r->size);
        int maxi = INT_MAX;
        int mini = INT_MIN;
        
        //dummy *t = new dummy(s, maxi, mini);
        return new dummy(s, maxi, mini);
    }
    int largestBst(Node *root)
    {
    	dummy *d = f(root);
    	return d->size;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends