class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,int> childParent;
        unordered_map<int,vector<int>> adj;
        unordered_map<int,bool> visited;
        // step 1 create parent child relation and only one parent should be there.
        for(int i=0;i<n;i++){
            int node=i;
            int leftCh=leftChild[i];
            int rightCh=rightChild[i];
            if(leftCh!=-1){
                adj[node].push_back(leftCh);
                if((childParent.find(leftCh)!=childParent.end()))
                {
                    return false;
                }
                childParent[leftCh]=node;
            }
            if(rightCh!=-1){
                adj[node].push_back(rightCh);
                if((childParent.find(rightCh)!=childParent.end()))
                {
                    return false;
                }
                childParent[rightCh]=node;
            }
        }
        // find root
        int root=-1;
        for(int i=0;i<n;i++){
            if(childParent.find(i)==childParent.end()){
                if(root!=-1){
                    return false;
                }
                root=i;
            }
        }
        if(root==-1){
            return false;
        }
        // count nodes and check whether equal to n 
        int count=0;
        queue<int> q;
        q.push(root);
        visited[root]=1;
        count=1;
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            for(auto nbr:adj[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    count++;
                    visited[nbr]=1;
                }
            }
        }
        return count==n;
    }
};