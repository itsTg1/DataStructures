class Solution {
public:
    void makeGraph(TreeNode* root,unordered_map<int,vector<int>> &adjlist,int parent){
        if(root==NULL){
            return ;
        }
        if(parent!=-1){
            adjlist[root->val].push_back(parent);
        }
        if(root->left){
            adjlist[root->val].push_back(root->left->val);
        }
        if(root->right){
            adjlist[root->val].push_back(root->right->val);
        }
        makeGraph(root->left,adjlist,root->val);
        makeGraph(root->right,adjlist,root->val);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adjlist;
        makeGraph(root,adjlist,-1);
        int time=0;
        queue<int> q;
        q.push(start);
        unordered_set<int> st;
        st.insert(start);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int node=q.front();
                q.pop();
                for(int nbr:adjlist[node]){
                    if(!st.count(nbr)){
                        st.insert(nbr);
                        q.push(nbr);
                    }
                }
            }
            time++;
        }
        return time-1;
    }
};