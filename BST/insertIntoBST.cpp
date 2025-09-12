
class Solution {
public:
    void findInorder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return ;
        }
        findInorder(root->left,ans);
        ans.push_back(root->val);
        findInorder(root->right,ans);
    }
    TreeNode* insertNode(int newNod,TreeNode* head){
        if(head==NULL){
            
            TreeNode* Nod=new TreeNode(newNod);
            head=Nod;
            return head;
        }
        if(newNod>head->val){
            head->right=insertNode(newNod,head->right);
        }
        else if(newNod<head->val){
            head->left=insertNode(newNod,head->left);
        }
        return head;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* newNod=new TreeNode(val);
            return newNod;
        }
        vector<int> ans;
        findInorder(root,ans);
        TreeNode* head=new TreeNode(val);
        for(int i=0;i<ans.size();i++){
            head=insertNode(ans[i],head);
        }
        return head;

    }
};