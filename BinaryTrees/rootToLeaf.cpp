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