class Solution {
public:
    void morrisInorder(TreeNode* root,vector<int>&ans){
        // till root is not null
        while(root){
            //left part does not exist
            if(root->left==NULL){
                ans.push_back(root->val);
                root=root->right;
            }
            // left part exist
            else{
                TreeNode* curr=root->left;
                // traverse left part to check whether link is there or not
                while(curr->right && curr->right!=root){
                    curr=curr->right;
                }
                // if left part is not traversed
                if(curr->right==NULL){
                    // form link to root
                    curr->right=root;
                    root=root->left;
                }
                // if already traversed 
                else{
                    // remove the link
                    curr->right=NULL;
                    ans.push_back(root->val);
                    root=root->right;
                }
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        morrisInorder(root,ans);
        return ans;
    }
};