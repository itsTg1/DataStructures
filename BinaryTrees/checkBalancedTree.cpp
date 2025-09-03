// leetcode= 110
class Solution {
  public:
    int getHeight(Node* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(getHeight(root->left),getHeight(root->right));
    }
    bool checkBalance(int left,int right){
      
        if(abs(left-right)<=1){
            
            return true;
        }
        return false;
    }
    bool isBalanced(Node* root) {
        // Code here
        if(root==NULL){
            return true;
        }
        int leftHeight=getHeight(root->left);
        int rightHeight=getHeight(root->right);
        bool nodeans=checkBalance(leftHeight,rightHeight);
        bool leftAns=isBalanced(root->left);
        bool rightAns=isBalanced(root->right);
        return (nodeans&leftAns&rightAns);
    }
};