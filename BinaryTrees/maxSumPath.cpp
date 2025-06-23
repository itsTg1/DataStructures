// same as diameter

class Solution {
public:
    int getSum(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }
        int lh=getSum(root->left,ans);
        int rh=getSum(root->right,ans);
        int option1=root->val+lh+rh;
        int option2=max(lh,rh)+root->val;
        int option3=root->val;
        ans=max(ans,max(max(option1,option2),option3));
        return max(option2,option3);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=root->val;
        getSum(root,ans);
        return ans;
    }
};