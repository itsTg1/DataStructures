/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findSuccessor(TreeNode* root){
        
        if(root->right==NULL){
            return root;
        }
        return findSuccessor(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key && root->left==NULL && root->right==NULL){
            return NULL;
        }
        if(root->val==key && root->left==NULL && root->right!=NULL){
            TreeNode* newNod=root->right;
            root->right=NULL;
            return newNod;
        }
        if(root->val==key && root->right==NULL && root->left!=NULL){
            TreeNode* newNod=root->left;
            root->left=NULL;
            return newNod;
        }
        if(root->val==key && root->right!=NULL && root->left!=NULL){
            TreeNode* newNod=findSuccessor(root->left);
          
            root->val=newNod->val;
            root->left=deleteNode(root->left,newNod->val);
            return root;

        }
        if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        return root;
    }
};