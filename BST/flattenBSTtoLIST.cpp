// You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. 
// The goal is to flatten the tree such that, the left child of each element points to 
// nothing (NULL), and the right child points to the next element in the sorted 
// list of elements of the BST

// gfg
class Solution {
  public:
    Node* newRoot=new Node(-1);
    Node* tail=newRoot;
    void inorder(Node* root){
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        Node* nex=new Node(root->data);
        tail->right=nex;
        tail=nex;
        inorder(root->right);
    }
    Node *flattenBST(Node *root) {
        // code here
        if(root==NULL){
            return NULL;
        }
        inorder(root);
        tail->right=NULL;
        
        return newRoot->right;
        
    }
};