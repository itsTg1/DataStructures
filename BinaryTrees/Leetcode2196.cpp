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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_map<int,int> parents;
        for(auto it:descriptions){
            int parent=it[0];
            int child=it[1];
            TreeNode* ch=NULL;
            TreeNode* par=NULL;
            if(mp.find(parent)!=mp.end()){
                par=mp[parent];
            }
            else if(mp.find(parent)==mp.end()){
                par=new TreeNode(parent);
                mp[parent]=par;
            }
            if(mp.find(child)!=mp.end()){
                ch=mp[child];
            }
            else if(mp.find(child)==mp.end()){
                ch=new TreeNode(child);
                mp[child]=ch;
            }
            parents[child]=parent;
            if(it[2]==1){
                par->left=ch;
            }
            else{
                par->right=ch;
            }
        }
        for(auto it:mp){
            if(parents.find(it.first)==parents.end()){
                return it.second;
            }
        }
        return NULL;
    }
};