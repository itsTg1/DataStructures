class Solution {
  public:
   
    vector<int> traversal;
    void bfsTraversal(int src,unordered_map<int,vector<int>> &adjLis,unordered_map<int,bool> &visited)
    {
        queue<int> q;
        q.push(src);
        visited[src]=1;
        while(!q.empty()){
            int currNod=q.front();
            traversal.push_back(currNod);
            q.pop();
            for(auto nbr:adjLis[currNod]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
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
                bfsTraversal(i,adjLis,visited);
            }
        }
        return traversal;
    }
};