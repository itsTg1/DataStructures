class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    bool checkSum(Node* root){
        if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        int rval=0;
        int lval=0;
        if(root->left){
            lval=root->left->data;
        }
        if(root->right){
            rval=root->right->data;
        }
        if(root->data!=(rval+lval)){
            return false;
        }
        return (checkSum(root->left) && checkSum(root->right));
        
    }
    int isSumProperty(Node *root) {
        // Add your code here
        if(checkSum(root)){
            return 1;
        }
        return 0;
    }
};