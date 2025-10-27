class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void addParent(TreeNode* root) {
        if(!root)
            return;
        
        if(root->left)
            parent[root->left] = root;
        
        addParent(root->left);
        
        if(root->right)
            parent[root->right] = root;
        
        addParent(root->right);
    }
    
    void collectKDistanceNodes(TreeNode* target, int k, vector<int>& result) {
        
        queue<TreeNode*> que;
        que.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);
        
        while(!que.empty()) {
            
            int n = que.size();
            if(k == 0)
                break;
            
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                
                if(curr->left && !visited.count(curr->left->val)) {
                    que.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if(curr->right && !visited.count(curr->right->val)) {
                    que.push(curr->right);
                    visited.insert(curr->right->val);
                }
                
                if(parent.count(curr) && !visited.count(parent[curr]->val)) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        
        while(!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            result.push_back(temp->val);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        
        addParent(root);
        
        collectKDistanceNodes(target, k, result);
        return result;
    }
};



// --------------------------******------------------------------------------------------------------



// gfg

class Solution {

  public:
    unordered_map<Node*,Node*> mp;
    unordered_map<Node*,bool> visited;
    Node* findNode(Node* root,int target){
        if(root==NULL){
            return NULL;
        }
        if(root->data==target){
            return root;
        }
        Node* leftAns=findNode(root->left,target);
        Node* rightAns=findNode(root->right,target);
        
        if(leftAns){
            return leftAns;
        }
        if(rightAns){
            return rightAns;
        }
        return NULL;
    }
    void storeParents(Node* root,Node* parent){
        if(root==NULL){
            return ;
        }
        mp[root]=parent;
        storeParents(root->left,root);
        storeParents(root->right,root);
        return ;
    }
    void findAllNodes(Node* root,int dis,int k,vector<int> &ans){
        if(root==NULL || visited[root]){
            return ;
        }
        if(dis==k){
            ans.push_back(root->data);
            return ;
        }
        visited[root]=true;
        findAllNodes(mp[root],dis+1,k,ans);
        findAllNodes(root->left,dis+1,k,ans);
        findAllNodes(root->right,dis+1,k,ans);
        return ;
    }
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        // return the sorted vector of all nodes at k dist
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        storeParents(root,NULL);
        Node* newRoot=findNode(root,target);
     
        if(newRoot==NULL){
            return ans;
        }
        findAllNodes(newRoot,0,k,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};