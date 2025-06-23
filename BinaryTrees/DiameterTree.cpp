class Solution {
public:
    int diam(TreeNode* root,int &ans){
        if (root == NULL){
            return 0;
        }
        int l=diam(root->left,ans);
        int r=diam(root->right,ans);
        
        ans=max(ans,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        int ans=0;
        diam(root,ans);
        return ans;
    }
};