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


// ---------------------------------------------------------APPROACH2


class Solution {
public:
    int findHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(findHeight(root->left),findHeight(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh=findHeight(root->left);
        int rh=findHeight(root->right);
        int leftDia=diameterOfBinaryTree(root->left);
        int rightDia=diameterOfBinaryTree(root->right);
        return max({leftDia,rightDia,lh+rh});
    }
};