
class Solution {
  public:
    
    pair<int,int> getSum(Node* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> leftAns=getSum(root->left);
        pair<int,int> rightAns=getSum(root->right);
        pair<int,int> result;
        // if we include root then we have to exclude its childs
        result.first=root->data+leftAns.second+rightAns.second;
        // if we exclude root then we can include or exclude their child nodes
        result.second=max(leftAns.first,leftAns.second)+max(rightAns.first,rightAns.second);
        return result;
    }
    int getMaxSum(Node *root) {
        // code here
        if(root==NULL){
            return 0;
        }
        pair<int,int> ans=getSum(root);
        
        return max(ans.first,ans.second);
        
    }
};