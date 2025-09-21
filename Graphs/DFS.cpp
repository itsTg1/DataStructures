class Solution {
  public:
    vector<int> traversal;
    void dfsTraversal(int src,unordered_map<int,vector<int>> &adjLis,unordered_map<int,bool> &visited){
        visited[src]=1;
        traversal.push_back(src);
        for(auto it:adjLis[src]){
            if(!visited[it]){
                dfsTraversal(it,adjLis,visited);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int,vector<int>> adjLis;
        int n=adj.size();
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                adjLis[i].push_back(it);
         
            }
        }
        
        unordered_map<int,bool> visited;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfsTraversal(i,adjLis,visited);
            }
        }
        return traversal;
    }
};