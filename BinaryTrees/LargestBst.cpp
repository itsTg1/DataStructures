// https://www.geeksforgeeks.org/problems/largest-bst/1


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

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    void inorder(Node* root,vector<int> &arr){
        if(root==NULL){
            return ;
        }
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    int findInorder(Node* root){
        if(root==NULL){
            return 0;
        }
        vector<int> arr;
        inorder(root,arr);
        vector<int> temp=arr;
        sort(arr.begin(),arr.end());
        if(arr==temp){
            for(int i=1;i<temp.size();i++){
                if(temp[i]==temp[i-1]){
                    return 0;
                }
            }
            return arr.size();
        }
        return 0;
    }
    int largestBst(Node *root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        return max(findInorder(root),max(largestBst(root->left),largestBst(root->right)));
        
        
        
    }
};