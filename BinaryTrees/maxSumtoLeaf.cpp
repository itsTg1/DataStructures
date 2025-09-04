// User function Template for C++

class Solution {
  public:
    int findMaxPath(Node* root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return root->data;
        }
        int leftAns=root->data+findMaxPath(root->left);
        int rightAns=root->data+findMaxPath(root->right);
      
        if(leftAns==root->data && rightAns!=root->data){
            return rightAns;
        }
        if(leftAns!=root->data && rightAns==root->data){
            return leftAns;
        }
        return max(leftAns,rightAns);
    }
    int maxPathSum(Node* root) {
        // code here
        if(root==NULL){
            return 0;
        }
        return findMaxPath(root);
    }
};