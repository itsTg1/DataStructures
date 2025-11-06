class Solution {
  public:
    void bfs(int V,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &isVisited,int src,vector<vector<int>> &result){
        vector<int> temp;
        queue<int> q;
        q.push(src);
        isVisited[src]=1;
        temp.push_back(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto nbr:adj[node]){
                if(!isVisited[nbr]){
                    q.push(nbr);
                    isVisited[nbr]=1;
                    temp.push_back(nbr);
                }
            }
        }
        result.push_back(temp);
        
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> result;
        unordered_map<int,vector<int>> adj;
        unordered_map<int,bool> isVisited;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<V;i++){
            if(!isVisited[i]){
                bfs(V,adj,isVisited,i,result);
            }
        }
        return result;
    }
};
