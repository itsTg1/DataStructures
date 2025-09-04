
class Solution {
  public:
    void traversal(Node* root1,Node*root2,bool &ans){
        if(root1==NULL && root2==NULL){
            return;
        }
        if(root1==NULL && root2!=NULL){
            ans=false;
            return ;
        }
        if(root1!=NULL && root2==NULL){
            ans=false;
            return ;
        }
        if(root1->data!=root2->data){
            ans=false;
            return ;
        }
        traversal(root1->left,root2->right,ans);
        traversal(root1->right,root2->left,ans);
    }
    bool isSymmetric(Node* root) {
        // Code here
        if(root==NULL){
            return true;
        }
        bool ans=true;
        traversal(root->left,root->right,ans);
        return ans;
    }
};