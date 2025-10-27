

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


// ----------------------------------------------------**--------------------------------------------

class Solution {
  public:
    void findLeaves(Node* root,vector<int> &leafNodes){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            leafNodes.push_back(root->data);
            return;
        }
        findLeaves(root->left,leafNodes);
        findLeaves(root->right,leafNodes);
        
    }
    bool findPath(Node* root,int dest,vector<int> &path){
        if(root==NULL){
            return false;
        }
        if(root->data==dest){
            path.push_back(root->data);
            return true;
        }
        path.push_back(root->data);
        if(findPath(root->left,dest,path) || findPath(root->right,dest,path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int> leafNodes;
        findLeaves(root,leafNodes);
        vector<vector<int>> result;
        for(auto it:leafNodes){
            vector<int> temp;
            if(findPath(root,it,temp)){
                result.push_back(temp);
            }
            
        }
        return result;
    }
};