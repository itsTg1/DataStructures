

class Solution {
  public:
    void storeAllPaths(Node* root,vector<int> &v,vector<vector<int>> &ans){
        if(root==NULL){
            return ;
        }

        if(root->left==NULL && root->right==NULL){
            v.push_back(root->data);
            ans.push_back(v);
            v.pop_back();
            return ;
        }
        v.push_back(root->data);
        storeAllPaths(root->left,v,ans);
        storeAllPaths(root->right,v,ans);
        v.pop_back();
        return ;
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> v;
        storeAllPaths(root,v,ans);
        return ans;
    }
};