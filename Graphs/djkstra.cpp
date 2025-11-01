
class Solution {
  public:
    unordered_map<int,vector<pair<int,int>>> adj;
    
    
    
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int dis=it[2];
            adj[u].push_back({v,dis});
            adj[v].push_back({u,dis});
        }
        vector<int> result(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,src});
        result[src]=0;
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            int u=front.second;
            int dis=front.first;
            for(auto v:adj[u]){
                if((dis+v.second)<result[v.first]){
                    result[v.first]=dis+v.second;
                    pq.push({result[v.first],v.first});
                }
            }
        }
        return result;
    }
};