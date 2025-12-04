class Solution {
  public:
    bool checkCycle(int src,unordered_map<int,int> &parent,unordered_map<int,bool> &visited
    ,unordered_map<int,vector<int>> &adj){
        queue<int> q;
        q.push(src);
        visited[src]=1;
        parent[src]=-1;
        while(!q.empty()){
            int frontNod=q.front();
            q.pop();
            for(auto nbr:adj[frontNod]){
                if(!visited[nbr]){
                    parent[nbr]=frontNod;
                    visited[nbr]=1;
                    q.push(nbr);
                }
                else if(visited[nbr] && parent[frontNod]!=nbr){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,int> parent;
        unordered_map<int,bool> visited;
        unordered_map<int,vector<int>> adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(checkCycle(i,parent,visited,adj)){
                    return true;
                }
            }
        }
        return false;
        
    }
};