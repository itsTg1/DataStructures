// gfg
class Solution {
  public:
    map<int,vector<int>> mp;
    
    void inorderBST(Node* root,int target){
        if(root==NULL){
            return ;
        }
        inorderBST(root->left,target);
        mp[abs(target-(root->data))].push_back(root->data);
        inorderBST(root->right,target);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        inorderBST(root,target);
        for(auto it:mp){
            for(auto i:it.second){
                ans.push_back(i);
                k--;
                if(k==0){
                    return ans;
                }
            }
        }
        return ans;
        
    }
};