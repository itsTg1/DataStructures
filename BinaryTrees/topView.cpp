/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        mp[0].push_back(root->data);
        while(!q.empty()){
            auto frontNod=q.front();
            q.pop();
            int lvl=frontNod.second;
            Node* nod=frontNod.first;
            if(nod->left){
                mp[lvl-1].push_back(nod->left->data);
                q.push({nod->left,lvl-1});
            }
            if(nod->right){
                mp[lvl+1].push_back(nod->right->data);
                q.push({nod->right,lvl+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second[0]);
        }
        return ans;
    }
};