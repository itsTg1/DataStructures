
class Solution {
  public:
    /*You are required to complete this method*/
    // concept of returning int_max is that we want path till leaf but if node comes in between that
    // is null it means that is not leaf node bcz we are returning from leaf node thats why to not 
    // consider it in our minimum paths we are returning max value.
    int calcDepth(Node* root){
        if(root==NULL){
            return INT_MAX-1;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        int leftAns=1+calcDepth(root->left);
        int rightAns=1+calcDepth(root->right);
        return min(leftAns,rightAns);
    }
    int minDepth(Node *root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        int leftDepth=calcDepth(root->left);
        int rightDepth=calcDepth(root->right);
        return 1+min(leftDepth,rightDepth);
    }
};