
class Solution {
  public:
    
    pair<int,int> getSum(Node* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> left=getSum(root->left);
        pair<int,int> right=getSum(root->right);
        pair<int,int> currResult;
        currResult.first=root->data +left.second+right.second;
        currResult.second=max(left.first,left.second)+max(right.first,right.second);
        return currResult;
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