// leetcode 1382


class Solution {
public:
    vector<TreeNode*> v;
    void inorder(TreeNode* root){
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }
    TreeNode* buildBST(int s,int e){
        if(s>e){
            return NULL;
        }
        
        int mid=(s+e)/2;
        TreeNode* root=v[mid];
        root->left=buildBST(s,mid-1);
        root->right=buildBST(mid+1,e);
        return root;
       
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        inorder(root);
        TreeNode* result=buildBST(0,v.size()-1);
        return result;
    }
};